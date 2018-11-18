#include "slowaim.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cslowaim* c_slowaim = new cslowaim();
		cslowaim::cslowaim() {
			init = false;
			old_sens = 0.f;
		}
		void cslowaim::think() {
			if (!init) {
				old_sens = csgo::c_client->get_sens();
				init = true;
			}
			auto crossid = globals::local->get_incross();
			if (crossid > 0 && crossid <= 64) {
				auto ent = csgo::c_client->get_entity(crossid);
				if (ent->get_team() != globals::local->get_team())
					csgo::c_client->set_sens(settings_t.misc.sens);
				else
					csgo::c_client->set_sens(old_sens);
			}else
				csgo::c_client->set_sens(old_sens);
		}
	}

}