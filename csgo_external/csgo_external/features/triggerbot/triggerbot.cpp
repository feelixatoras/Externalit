#include "triggerbot.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace triggerbot {
		ctriggerbot* c_triggerbot = new ctriggerbot();
		ctriggerbot::ctriggerbot() {
			first = true;
		}
		void ctriggerbot::think() {
			if (globals::weapon->is_ab()) {
				auto id = globals::weapon->id();
				if (wpn_t[id].triggerbot) {
					if (GetAsyncKeyState(wpn_t[id].triggerbot_key1) | GetAsyncKeyState(wpn_t[id].triggerbot_key1)) {
						auto crossid = globals::local->get_incross();
						if (crossid > 0 && crossid <= 64) {
							auto ent = csgo::c_client->get_entity(crossid);
							if (ent->get_team() == globals::local->get_team())
								if (!wpn_t[id].triggerbot_team)return;
							if (globals::local->get_shots_fired() > 0)
								std::this_thread::sleep_for(std::chrono::milliseconds(c_math->rnd_int(wpn_t[id].triggerbot1_sleep_min, wpn_t[id].triggerbot1_sleep_max)));
							else
								std::this_thread::sleep_for(std::chrono::milliseconds(c_math->rnd_int(wpn_t[id].triggerbot2_sleep_min, wpn_t[id].triggerbot2_sleep_max)));
							c_memory->write<int>(offys::clientdll + offys::dwForceAttack, 5);
							std::this_thread::sleep_for(std::chrono::milliseconds(3));
							c_memory->write<int>(offys::clientdll + offys::dwForceAttack, 4);
							std::this_thread::sleep_for(std::chrono::milliseconds(1));
						}
					}
				}
			}
		}
	}

}