#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cnoflash {
		public:
			cnoflash() = default;
			void think();
		}; extern cnoflash* c_noflash;
	}
}