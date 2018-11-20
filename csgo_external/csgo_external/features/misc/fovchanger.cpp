#include "fovchanger.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cfovchanger* c_fovchanger = new cfovchanger();
		void cfovchanger::think() {
			auto local_fov = globals::local->get_fov();
			auto scope_level = globals::weapon->get_zoomlevel();
			if (!globals::local->is_scoped()) {
				if (settings_t.misc.fov_changer_amout != local_fov)
					c_memory->write<int>(globals::local->ent + (m_iFOVStart - 4), settings_t.misc.fov_changer_amout);
			}else if(scope_level == 1)
				c_memory->write<int>(globals::local->ent + (m_iFOVStart - 4), 40);
			else if(scope_level == 2)
				c_memory->write<int>(globals::local->ent + (m_iFOVStart - 4), 10);
		}
	}
}