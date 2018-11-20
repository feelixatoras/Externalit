#pragma once
#include "../sdk.h"
namespace sdk {
	class cweapon
	{
	public:
		static cweapon get_weapon(int i);
		bool is_rcs();
		bool is_ab();
		bool is_auto();
		uint32_t weap;
		int get_zoomlevel();
		cweapon(uint32_t weap);
		short id();
		int get_xuid();

	};
}
