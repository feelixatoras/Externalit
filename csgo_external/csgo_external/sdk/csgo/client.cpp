#include "client.h"
namespace sdk {
	using namespace offys;
	namespace csgo {
		cclient* c_client = new cclient();
		std::auto_ptr<centity> cclient::get_local() {
			std::auto_ptr<centity> ent(new centity(c_memory->read<uint32_t>(clientdll + dwLocalPlayer)));
			return ent;
		}
		std::auto_ptr<centity> cclient::get_entity(int i) {
			std::auto_ptr<centity> ent(new centity(c_memory->read<uint32_t>(clientdll + dwEntityList + (i - 1) * 0x10)));
			return ent;
		}
		float cclient::get_sens() {
			auto xorsens = clientdll + dwSensitivityPtr;
			auto sens = c_memory->read<uint32_t>(clientdll + dwSensitivity);
			sens ^= xorsens;
			return *reinterpret_cast<float*>(&sens);
		}
		bool cclient::mouse_enable() {
			auto xored = clientdll + dwMouseEnablePtr;
			auto mouse = c_memory->read<uint32_t>(clientdll + dwMouseEnable);
			mouse ^= xored;
			return *reinterpret_cast<bool*>(&mouse);
		}
		void cclient::set_sens(float f) {
			auto xorsens = clientdll + dwSensitivityPtr;
			auto sens = *reinterpret_cast<uint32_t*>(&f) ^ xorsens;
			c_memory->write<uint32_t>(clientdll + dwSensitivity, sens);
		}
	}
}