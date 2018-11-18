#pragma once
#include "../sdk.h"
namespace sdk {
	class cweapon
	{
	public:
		static cweapon getweapon(int i);
		bool rcswpn();
		bool abwpn();
		bool autowpn();
		uint32_t weap;
		int zoomlvl();
		cweapon(uint32_t weap);
		short id();
	};
}
