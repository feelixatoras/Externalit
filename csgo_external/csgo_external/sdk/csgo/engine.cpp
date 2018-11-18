#include "engine.h"
namespace sdk {
	using namespace offys;
	namespace csgo {
		cengine* c_engine = new cengine();
		uint32_t cengine::client_state() {
			return c_memory->read<int>(enginedll + dwClientState);
		}
		vec3 cengine::get_viewang() {
			return c_memory->read<vec3>(client_state() + dwClientState_ViewAngles);
		}
		void cengine::set_viewang(vec3 ang) {
			c_memory->write<vec3>(client_state() + dwClientState_ViewAngles, ang);
		}
		const char* cengine::get_mapdir() {
			static auto map = c_memory->read<std::array<char, 0x120>>(client_state() + dwClientState_MapDirectory);
			return map.data();
		}
		const char* cengine::get_mapname() {
			static auto map = c_memory->read<std::array<char, 0x80>>(client_state() + dwClientState_Map);
			return map.data();
		}
		const char* cengine::get_gamedir() {
			static auto game = c_memory->read<std::array<char, 0x120>>(enginedll + dwGameDir);
			return game.data();
		}
	}
}
