#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cautopistol {
		public:
			cautopistol() = default;
			void think();
		}; extern cautopistol* c_autopistol;
	}
}