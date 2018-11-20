#include "skinchanger.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace skinchanger {
		cskinchanger* c_skinchanger = new cskinchanger(); 
		void cskinchanger::think() {
			if (globals::weapon->is_ab()) {
				auto id = globals::weapon->id();
				if (wpn_t[id].skinchanger) {
					auto xuid = globals::weapon->get_xuid();
					c_memory->write<int>(globals::weapon->weap + m_iItemIDHigh, -1);
					c_memory->write<int>(globals::weapon->weap + m_OriginalOwnerXuidLow, 0);
					c_memory->write<int>(globals::weapon->weap + m_OriginalOwnerXuidHigh, 0);
					c_memory->write<int>(globals::weapon->weap + m_nFallbackPaintKit, wpn_t[id].skinchanger_skin);
					c_memory->write<int>(globals::weapon->weap + m_nFallbackSeed, wpn_t[id].skinchanger_seed);
					c_memory->write<float>(globals::weapon->weap + m_flFallbackWear, wpn_t[id].skinchanger_wear);
					c_memory->write<int>(globals::weapon->weap + m_nFallbackStatTrak, wpn_t[id].skinchanger_stattrak);
					c_memory->write<std::string>(globals::weapon->weap + m_szCustomName, wpn_t[id].skinchanger_nametag);
					c_memory->write<int>(globals::weapon->weap + m_iAccountID, xuid);
				}
			}
		}
	}
}