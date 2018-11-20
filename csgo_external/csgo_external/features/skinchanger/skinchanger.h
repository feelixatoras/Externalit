#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace skinchanger {
		class cskinchanger {
		public:
			cskinchanger() = default;
			void think();
		}; extern cskinchanger* c_skinchanger;
	}
}