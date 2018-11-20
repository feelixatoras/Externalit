#pragma once
#include "../sdk.h"
namespace sdk {
	namespace csgo {
		class cengine {
		private:
			uint32_t client_state();
		public:
			cengine() = default;
			vec3 get_viewang();
			void set_viewang(vec3 ang);
			const char* get_mapdir();
			const char* get_mapname();
			const char* get_gamedir();
			void full_update();
		}; extern cengine* c_engine;
	};
}