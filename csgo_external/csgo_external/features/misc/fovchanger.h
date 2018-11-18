#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cfovchanger {
		public:
			cfovchanger() = default;
			void think();
		}; extern cfovchanger* c_fovchanger;
	}
}