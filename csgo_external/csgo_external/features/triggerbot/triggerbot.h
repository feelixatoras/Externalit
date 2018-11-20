#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace triggerbot {
		class ctriggerbot {
		public:
			ctriggerbot();
			void think();
		private:
			bool first;
		}; extern ctriggerbot* c_triggerbot;
	}
}