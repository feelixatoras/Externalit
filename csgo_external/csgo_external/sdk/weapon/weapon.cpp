#include "weapon.h"
namespace sdk {
	using namespace offys;
	cweapon::cweapon(uint32_t weap) : weap(weap) {
	}
	cweapon cweapon::get_weapon(int i) {
		return cweapon(c_memory->read<uint32_t>(clientdll + dwEntityList + ((i & 0xFFF) - 1) * 0x10));
	}
	short cweapon::id() {
		return c_memory->read<short>(weap + m_iItemDefinitionIndex);
	}
	bool cweapon::is_ab() {
		switch (id()) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 13:
		case 14:
		case 16:
		case 17:
		case 19:
		case 23:
		case 24:
		case 25:
		case 26:
		case 27:
		case 28:
		case 29:
		case 30:
		case 32:
		case 33:
		case 34:
		case 35:
		case 36:
		case 38:
		case 39:
		case 40:
		case 60:
		case 61:
		case 63:
		case 64:
			return true;
			break;
		default:
			return false;
			break;

		}
	}
	bool cweapon::is_rcs() {
		switch (id()) {
		case 7:
		case 8:
		case 10:
		case 13:
		case 14:
		case 16:
		case 17:
		case 19:
		case 24:
		case 26:
		case 28:
		case 33:
		case 34:
		case 39:
		case 60:
		case 63:
			return true;
			break;
		default:
			return false;
			break;

		}
	}
	int cweapon::get_zoomlevel() {
		return c_memory->read<int>(weap + m_zoomLevel);
	}
	int cweapon::get_xuid() {
		return c_memory->read<int>(weap + m_OriginalOwnerXuidLow);
	}
	bool cweapon::is_auto() {
		switch (id()) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 30:
		case 32:
		case 36:
		case 61:
			return true;
			break;
		default:
			return false;
			break;

		}
	}
}