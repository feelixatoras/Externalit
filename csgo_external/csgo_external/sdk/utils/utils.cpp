#include "utils.h"
namespace sdk {
	cutils* c_utils = new cutils();
	std::string cutils::weapon_config(int weaponid)
	{
		switch (weaponid)
		{
		case weapon_deagle:
			return "Deagle";
		case weapon_elite:
			return "Elite";
		case weapon_fiveseven:
			return "Fiveseven";
		case weapon_glock:
			return "Glock18";
		case weapon_ak47:
			return "Ak47";
		case weapon_aug:
			return "Aug";
		case weapon_awp:
			return "Awp";
		case weapon_famas:
			return "Famas";
		case weapon_g3sg1:
			return "G3sg1";
		case weapon_galilar:
			return "Galil";
		case weapon_m249:
			return "M249";
		case weapon_mp5:
			return "MP5-SD";
		case weapon_m4a1:
			return "M4a4";
		case weapon_mac10:
			return "Mac10";
		case weapon_p90:
			return "P90";
		case weapon_ump45:
			return "Ump45";
		case weapon_xm1014:
			return "Xm1014";
		case weapon_bizon:
			return "Bizon";
		case weapon_mag7:
			return "Mag7";
		case weapon_negev:
			return "Negev";
		case weapon_sawedoff:
			return "Sawedoff";
		case weapon_tec9:
			return "Tec9";
		case weapon_hkp2000:
			return "P2000";
		case weapon_mp7:
			return "Mp7";
		case weapon_mp9:
			return "Mp9";
		case weapon_nova:
			return "Nova";
		case weapon_p250:
			return "P250";
		case weapon_scar20:
			return "Scar20";
		case weapon_sg556:
			return "Sg556";
		case weapon_ssg08:
			return "Ssg08";
		case weapon_m4a1_silencer:
			return "M4a1s";
		case weapon_usp_silencer:
			return "Usps";
		case weapon_cz75a:
			return "Cz75a";
		case weapon_r8revolver:
			return "Revolver";
		default:
			return "";
		}
		return "";
	}
	std::vector<std::string> cutils::split(const std::string& str, const std::string& delimiter)
	{
		std::vector<std::string> strings;

		std::string::size_type pos = 0;
		std::string::size_type prev = 0;
		while ((pos = str.find(delimiter, prev)) != std::string::npos)
		{
			strings.push_back(str.substr(prev, pos - prev));
			prev = pos + 1;
		}

		// To get the last substring (or only, if delimiter is not found)
		strings.push_back(str.substr(prev));

		return strings;
	}
	std::string cutils::animate_string(std::string string) {
		return string;
	}
}