#pragma once
#include "../sdk.h"
namespace sdk {
	class cweapon;
	class centity
	{
	public:
		uint32_t ent;
		int get_health();
		int get_flags();
		int get_team();
		bool is_dormant();
		bool is_visible(uint32_t i);
		int get_glow_index();
		int get_incross();
		bool get_immunity();
		float get_flash_alpha();
		int get_shots_fired();
		vec3 get_punch_angle();
		vec3 get_bone_position(int i);
		vec3 get_vec_offset();
		int get_fov();
		float get_velocity();
		bool is_scoped();
		vec3 get_vec_origin();
		std::auto_ptr<cweapon> get_weapon();
		uint32_t get_bone_base();
		//void update();
		centity(uint32_t ent);
		~centity() = default;
	private:
	};
	struct entity {
		uint32_t base;
		int health;
		int flags;
		int team;
		bool is_dormant;
		bool is_visible;
		int glow_index;
		int incross;
		bool immunity;
		float flash_alpha;
		int shots_fired;
		vec3 punch_angle;
		vec3 bone_position;
		vec3 vec_offset;
		vec3 vec_origin;
		std::auto_ptr<cweapon> weapon;
		uint32_t bone_base;
	}; extern entity entity_t[64];
}

