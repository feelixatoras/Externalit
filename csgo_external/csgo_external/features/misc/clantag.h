#pragma once
#include "../../sdk/sdk.h"
namespace features {
	namespace misc {
		class cclantag {
		public:
			cclantag() = default;
			void think();
		}; extern cclantag* c_clantag;
	}
}