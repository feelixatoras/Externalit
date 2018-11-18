#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace aimbot {
		class caimbot {
		private:
			int best_target;
			float best_fov;
			bool valid_target(std::auto_ptr<sdk::centity> target);
			void get_target(vec3 viewang, vec3 vecorigin, vec3 vecoffset, vec3 punch, bool rcs, float rcsx, float rcsy, int bone);
		public:
			caimbot();
			~caimbot() = default;
			void think();
		}; extern caimbot* c_aimbot;
	}
}