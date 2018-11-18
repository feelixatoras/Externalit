#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class crankreveal {
		public:
			crankreveal() = default;
			void think();
		}; extern crankreveal* c_rankreveal;
	}
}