#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace visuals {
		class cchams {
		public:
			cchams() = default;
			void think();
		}; extern cchams* c_chams;
	}
}