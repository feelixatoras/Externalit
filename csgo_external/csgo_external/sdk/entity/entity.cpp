#include "entity.h"
namespace sdk {
	entity entity_t[64];
	using namespace offys;
	class cweapon;
	centity::centity(uint32_t ent) : ent(ent)
	{
	}

	int centity::get_health() {
		
		return c_memory->read<int>(ent + m_iHealth);
	}
	int centity::get_flags() {
		return c_memory->read<int>(ent + m_fFlags);
	}
	int centity::get_team() {
		return c_memory->read<int>(ent + m_iTeamNum);
	}
	bool centity::is_visible(uint32_t i) {
		auto mask = c_memory->read<int>(i + offys::m_bSpottedByMask);
		auto PBASE = c_memory->read<int>(ent + 0x64) - 1;
		return (mask & (1 << PBASE)) > 0;
	}
	bool centity::is_dormant() {
		return c_memory->read<bool>(ent + m_bDormant);
	}
	int centity::get_glow_index() {
		return c_memory->read<int>(ent + m_iGlowIndex);
	}
	int centity::get_incross() {
		return c_memory->read<int>(ent + m_iCrosshairId);
	}
	std::auto_ptr<cweapon> centity::get_weapon() {
		auto hweap = c_memory->read<uint32_t>(ent + m_hActiveWeapon);
		hweap &= 0xFFF;
		std::auto_ptr<cweapon> weapon(new cweapon(c_memory->read<uint32_t>(offys::clientdll + offys::dwEntityList + (hweap - 1) * 0x10)));
		return weapon;
	}
	int centity::get_shots_fired() {
		return c_memory->read<int>(ent + m_iShotsFired);
	}
	vec3 centity::get_punch_angle() {
		return c_memory->read<vec3>(ent + m_aimPunchAngle);
	}
	int centity::get_fov() {
		return c_memory->read<int>(ent + (m_iFOVStart - 4));
	}
	bool centity::is_scoped() {
		return c_memory->read<bool>(ent + m_bIsScoped);
	}
	uint32_t centity::get_bone_base() {
		return c_memory->read<uint32_t>(ent + m_dwBoneMatrix);
	}
	vec3 centity::get_bone_position(int i) {
		vec3 pos;
		auto bone_base = get_bone_base();
		pos.x = c_memory->read<float>(bone_base + 0x30 * i + 0x0C);
		pos.y = c_memory->read<float>(bone_base + 0x30 * i + 0x1C);
		pos.z = c_memory->read<float>(bone_base + 0x30 * i + 0x2C);
		return pos;
	}
	vec3 centity::get_vec_offset() {
		return c_memory->read<vec3>(ent + m_vecViewOffset);
	}
	vec3 centity::get_vec_origin() {
		return c_memory->read<vec3>(ent + m_vecOrigin);
	}
	bool centity::get_immunity() {
		return c_memory->read<bool>(ent + m_bGunGameImmunity);
	}
	float centity::get_flash_alpha() {
		return c_memory->read<float>(ent + m_flFlashMaxAlpha);
	}
	float centity::get_velocity() {
		return c_memory->read<vec3>(ent + m_vecVelocity).length();
	}
	
}