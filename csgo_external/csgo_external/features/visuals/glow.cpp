#include "glow.h"
using namespace sdk;
using namespace sdk::offys;

glow_t glow;
namespace features {
	namespace visuals {
		cglow* c_glow = new cglow();
		void cglow::think() {
			auto glow_object = c_memory->read<int>(clientdll + dwGlowObjectManager);
			for (int i = 1; i <= 64; i++) {
				auto ent = csgo::c_client->get_entity(i);
				if (ent->is_dormant()) continue;
				if (!ent->get_health())continue;
				auto visible = globals::local->is_visible(ent->ent);
				if (settings_t.visuals.glow_visible && !visible) continue;
				auto glow_index = ent->get_glow_index();
				auto team_mate = ent->get_team() == globals::local->get_team();
				if (!settings_t.visuals.glow_team && team_mate) continue;
				glow = c_memory->read<glow_t>(glow_object + glow_index * 0x38);
				glow.r = visible ? team_mate ? settings_t.visuals.colors.glow_team_r / 255 : settings_t.visuals.colors.glow_enemy_visible_r / 255 : team_mate ? settings_t.visuals.colors.glow_team_r / 255 : settings_t.visuals.colors.glow_enemy_invisible_r / 255;
				glow.g = visible ? team_mate ? settings_t.visuals.colors.glow_team_g / 255 : settings_t.visuals.colors.glow_enemy_visible_g / 255 : team_mate ? settings_t.visuals.colors.glow_team_g / 255 : settings_t.visuals.colors.glow_enemy_invisible_g / 255;
				glow.b = visible ? team_mate ? settings_t.visuals.colors.glow_team_b / 255 : settings_t.visuals.colors.glow_enemy_visible_b / 255 : team_mate ? settings_t.visuals.colors.glow_team_b / 255 : settings_t.visuals.colors.glow_enemy_invisible_b / 255;
				glow.a = visible ? team_mate ? settings_t.visuals.colors.glow_team_a / 255 : settings_t.visuals.colors.glow_enemy_visible_a / 255 : team_mate ? settings_t.visuals.colors.glow_team_a / 255 : settings_t.visuals.colors.glow_enemy_invisible_a / 255;
				glow.occluded = true;
				glow.unoccluded = false;
				c_memory->write<glow_t>(glow_object + glow_index * 0x38, glow);
			}
		}
	}
}
