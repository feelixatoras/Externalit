#include "fakelag.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cfakelag* c_fakelag = new cfakelag();
		void cfakelag::think() {
			c_memory->write_prot<BYTE>(offys::enginedll + dwbSendPackets, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
			c_memory->write_prot<BYTE>(offys::enginedll + dwbSendPackets, 1);
		}
	}
}