#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cbunnyhop {
		public:
			cbunnyhop() = default;
			void think();
		}; extern cbunnyhop* c_bunnyhop;
	}
}