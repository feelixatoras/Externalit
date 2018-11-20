#include "bunnyhop.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cbunnyhop* c_bunnyhop = new cbunnyhop();
		void cbunnyhop::think() {
			if (GetAsyncKeyState(32)) {
				auto flags = globals::local->get_flags();
				auto velocity = globals::local->get_velocity();
				if (velocity > 20 && !csgo::c_client->mouse_enable()) {
					if (flags < 263 && flags != 257)
						c_memory->write<uint32_t>(clientdll + offys::dwForceJump, 4);
					else
						c_memory->write<uint32_t>(clientdll + offys::dwForceJump, 5);
				}
			}
		}
	}
}