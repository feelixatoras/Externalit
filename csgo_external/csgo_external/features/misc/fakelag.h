#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cfakelag {
		public:
			cfakelag() = default;
			void think();
		}; extern cfakelag* c_fakelag;
	}
}