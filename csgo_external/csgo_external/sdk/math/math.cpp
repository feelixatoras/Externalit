
#include "math.h"
namespace sdk {
	cmath* c_math = new cmath();
	vec3 cmath::calc_ang(vec3 src, vec3 dst, vec3 offset, vec3 punch, bool rcs, float rcsx, float rcsy) {
		vec3 rang;
		auto delta = vec3(src.x - dst.x, src.y - dst.y, (src.z + offset.z) - dst.z);
		auto hyp = sqrt(delta.x * delta.x + delta.y *delta.y);
		if (rcs) {
			rang.x = (float)(asinf(delta.z / hyp) * 180.f / PI - punch.x * rcsx);
			rang.y = (float)(atanf(delta.y / delta.x) * 180.f / PI - punch.y * rcsy);
		}
		else {
			rang.x = (float)(asinf(delta.z / hyp) * 180.f / PI);
			rang.y = (float)(atanf(delta.y / delta.x) * 180.f / PI);
		}
		rang.z = 0;
		if (delta.x >= 0.0)
			rang.y += 180.0f;
		return rang;
	}

	float cmath::get_fov(vec3 ang, vec3 src, vec3 dst, vec3 offset, vec3 punch, bool rcs, float rcsx, float rcsy) {
		auto nang = calc_ang(src, dst, offset, punch, rcs, rcsx,rcsy) - ang;
		//nang.Normalized();
		return sqrtf(powf(nang.x, 2.0f) + powf(nang.y, 2.0f));
	}
	float cmath::rnd_float(float min, float max)
	{
		assert(max > min);
		float random = ((float)rand()) / (float)RAND_MAX;
		float range = max - min;
		return (random*range) + min;
	}
	int cmath::rnd_int(int min, int max) {
		assert(max > min);
		int random = ((int)rand()) / (int)RAND_MAX;
		int range = max - min;
		return (random*range) + min;
	}
}