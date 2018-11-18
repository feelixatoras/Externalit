#include "rankreveal.h"
using namespace sdk;
using namespace sdk::offys;
namespace features {
	namespace misc {
		crankreveal* c_rankreveal = new crankreveal();
		void crankreveal::think() {
			auto memory = c_memory->allocate(12);
			c_memory->execute(reinterpret_cast<void*>(m_dwRankRevealAllFn), memory); // "C7 00 ? ? ? ? E8 ? ? ? ? 83 EC 08 8D 4E 74" + 2
			c_memory->free_memory(memory);
		}
	}

}