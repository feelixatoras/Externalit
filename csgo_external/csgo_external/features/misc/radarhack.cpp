#include "radarhack.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cradarhack* c_radarhack = new cradarhack();
		void cradarhack::think() {
			for (int i = 0; i <= 64; i++) {
				auto ent = csgo::c_client->get_entity(i);
				if (ent->is_dormant()) continue;
				//if (ent->sp()) continue;
				c_memory->write(ent->ent + offys::m_bSpotted, 1);
			}
		}
	}
}