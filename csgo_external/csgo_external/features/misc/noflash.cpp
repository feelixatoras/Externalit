#include "noflash.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cnoflash* c_noflash = new cnoflash();
		void cnoflash::think() {
			if (settings_t.misc.no_flash)
				c_memory->write(globals::local->ent + m_flFlashMaxAlpha, 0);
			else
				c_memory->write(globals::local->ent + m_flFlashMaxAlpha, 255);
		}
	}
}