#pragma once
#include "../sdk.h"
namespace sdk{

	class centity;
	namespace csgo {
		class cclient {
		public:
			cclient() = default;
			std::auto_ptr<centity> get_local();
			std::auto_ptr<centity> get_entity(int i);
			bool mouse_enable();
			float get_sens();
			void set_sens(float f);
		}; extern cclient* c_client;
	}
}