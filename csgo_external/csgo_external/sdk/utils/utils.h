#pragma once
#include "../sdk.h"
namespace sdk {
	class cutils {
	public:
		cutils() = default;
		std::string weapon_config(int weaponid);
		std::vector<std::string> split(const std::string& str, const std::string& delimiter);
		std::string animate_string(std::string string);
	}; extern cutils* c_utils;
}