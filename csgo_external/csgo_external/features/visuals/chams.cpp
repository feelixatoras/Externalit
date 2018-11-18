#include "chams.h"
using namespace sdk;
using namespace sdk::offys;
clr_t clr;
namespace features {
	namespace visuals {
		cchams* c_chams = new cchams();
		void cchams::think() {
			for (int i = 0; i <= 64; i++) {
				auto ent = csgo::c_client->get_entity(i);
				if (ent->is_dormant()) continue;
				if (!ent->get_health())continue;
				auto mate = ent->get_team() == globals::local->get_team();
				clr.r = mate ? settings_t.visuals.colors.chams_team_r : settings_t.visuals.colors.chams_enemy_r;
				clr.g = mate ? settings_t.visuals.colors.chams_team_g : settings_t.visuals.colors.chams_enemy_g;
				clr.b = mate ? settings_t.visuals.colors.chams_team_b : settings_t.visuals.colors.chams_enemy_b;
				clr.a = 255;
				c_memory->write<clr_t>(ent->ent + offys::m_clrRender, clr);
			}
			auto thisPtr = (int)(enginedll + 0x58BBAC - 0x2c);
			auto xored = *(DWORD*)&settings_t.visuals.colors.chams_brightness ^ thisPtr;
			c_memory->write<int>(enginedll + 0x58BBAC, xored);
		}
	}

}