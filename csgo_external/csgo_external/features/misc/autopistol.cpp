#include "autopistol.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cautopistol* c_autopistol = new cautopistol();
		void cautopistol::think() {
			if (GetAsyncKeyState(1))
				if (globals::weapon->autowpn())
					c_memory->write(clientdll + dwForceAttack, 6);
		}
	}
}