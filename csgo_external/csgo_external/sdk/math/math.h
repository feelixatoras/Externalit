#ifndef CMATH_H
#define CMATH_H
#include "../sdk.h"
namespace sdk {
	class cmath {
	public:
		vec3 calc_ang(vec3 src, vec3 dst, vec3 offset, vec3 punch, bool rcs, float rcsx, float rcsy);
		float get_fov(vec3 ang, vec3 src, vec3 dst, vec3 offset, vec3 punch, bool rcs, float rcsx,float rcsy);
		float rnd_float(float min, float max);
		int rnd_int(int min, int max);
	}; extern cmath* c_math;
}
#endif