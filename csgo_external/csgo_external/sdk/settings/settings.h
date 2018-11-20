#pragma once
#include "../sdk.h"
namespace sdk {
	class csettings {
	public:
		csettings() = default;
		void read();
		void save();
	}; extern csettings* c_settings;

	struct settings {
		bool aimbot;
		bool triggerbot;
		bool skinchanger;
		struct{
			bool glow_esp;
			bool glow_team;
			bool glow_visible;
			bool chams;
			bool chams_team;
			struct {
				float glow_enemy_visible_r;
				float glow_enemy_visible_g;
				float glow_enemy_visible_b;
				float glow_enemy_visible_a;

				float glow_enemy_invisible_r;
				float glow_enemy_invisible_g;
				float glow_enemy_invisible_b;
				float glow_enemy_invisible_a;

				float glow_team_r;
				float glow_team_g;
				float glow_team_b;
				float glow_team_a;

				int chams_enemy_r;
				int chams_enemy_g;
				int chams_enemy_b;
				
				int chams_team_r;
				int chams_team_g;
				int chams_team_b;
				
				int chams_brightness;
			}colors;
		}visuals;
		struct {
			bool radar_hack;
			bool bunny_hop;
			bool no_flash;
			bool auto_pistol;
			bool fake_lag;
			bool slow_aim;
			float sens;
			int fake_lag_amount;
			bool fov_changer;
			int fov_changer_amout;
			bool rank_reveal;
			bool clan_tag;
			std::string clan_tag_string;
			bool clan_tag_animate;
		}misc;
	}; extern settings settings_t;
	struct weapon {
		bool aimbot = true;
		bool triggerbot = false;
		bool aimbot_visible_check = false;
		bool deathmatch = false;

		int aimbot_key1 = 1;
		int aimbot_key2 = 4;
		int triggerbot_key1 = 18;
		int triggerbot_key2 = 18;

		bool humanization = false;
		float humanization_x_min = 0.5f;
		float humanization_x_max = 5.f;
		float humanization_y_min = 0.5f;
		float humanization_y_max = 5.f;

		float fov_min = 12.f;
		float fov_max = 14.f;

		float smooth_x_min = 3.f;
		float smooth_x_max = 4.f;
		float smooth_y_min = 3.f;
		float smooth_y_max = 4.f;

		int shots_ignore = 0;
		int shots_bone_change = 1;

		int first_bone = 8;
		int second_bone = 8;

		int target_change_sleep = 0;

		bool rcs = true;
		float rcs_x_min = 1.9f;
		float rcs_x_max = 2.f;
		float rcs_y_min = 1.9f;
		float rcs_y_max = 2.f;

		int triggerbot1_sleep_min = 1;
		int triggerbot1_sleep_max = 2;
		int triggerbot2_sleep_min = 1;
		int triggerbot2_sleep_max = 2;
		bool triggerbot_team = false;

		bool skinchanger = true;
		int skinchanger_skin = 707;
		int skinchanger_seed = 2313;
		float skinchanger_wear = 0.99f;
		int skinchanger_stattrak = 1337;
		std::string skinchanger_nametag = "Lumine.Club";
	}; extern weapon wpn_t[64];
}