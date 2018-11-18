#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace visuals {
		class cglow {
		public:
			cglow() = default;
			void think();
		}; extern cglow* c_glow;
	}
}