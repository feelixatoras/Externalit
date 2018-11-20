#include "clantag.h"

using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		cclantag* c_clantag = new cclantag();
		void cclantag::think() {
			uint8_t shellcode[] =
				"\xB9\x00\x00\x00\x00"   
				"\xBA\x00\x00\x00\x00"     
				"\xB8\x00\x00\x00\x00"    
				"\xFF\xD0"               
				"\xC3"                    
				"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"; 

			auto clan_tag = settings_t.misc.clan_tag_animate ? c_utils->animate_string(settings_t.misc.clan_tag_string) : settings_t.misc.clan_tag_string;


			constexpr auto shellcode_size = sizeof(shellcode);
			auto clan_tag_size = clan_tag.size() > 15 ? 15 : clan_tag.size();

			auto shellcode_remote = c_memory->allocate(shellcode_size);
			auto tag_remote = reinterpret_cast<DWORD>(shellcode_remote) + 18;

			memcpy(shellcode + 1, &tag_remote, 4);
			memcpy(shellcode + 6, &tag_remote, 4);
			memcpy(shellcode + 11, &dwSetClanTag, 4); //"53 56 57 8B DA 8B F9 FF 15"
			memcpy(shellcode + 18, clan_tag.c_str(), clan_tag_size);

			c_memory->write((DWORD)shellcode_remote, shellcode, shellcode_size);
			c_memory->execute(shellcode_remote);
			c_memory->free_memory(shellcode_remote);
		}
	}
}
