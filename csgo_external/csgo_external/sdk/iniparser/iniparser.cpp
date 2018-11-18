#include "iniparser.h"
namespace sdk {
	creader* c_reader = new creader("config.ini");
	cwriter* c_writer = new cwriter("config.ini");
	creader::creader(std::string file)
	{
		memset(filename, 0x00, 255);
		memcpy(filename, file.c_str(), strlen(file.c_str()));
	}
	int creader::read_int(std::string section, std::string var)
	{
		return GetPrivateProfileInt(section.c_str(), var.c_str(), 0, filename);
	}
	float creader::read_float(std::string section, std::string var) {
		char result[255];
		char defaultvar[255];
		sprintf_s(defaultvar, "%f", 0.f);
		GetPrivateProfileString(section.c_str(), var.c_str(), defaultvar, result, 255, filename);
		return std::stof(result);
	}
	bool creader::read_bool(std::string section, std::string var) {
		char result[255];
		char defaultvar[255];
		bool end;
		sprintf_s(defaultvar, "%s", false ? "True" : "False");
		GetPrivateProfileString(section.c_str(), var.c_str(), defaultvar, result, 255, filename);
		end = (strcmp(result, "True") == 0 ||
			strcmp(result, "true") == 0) ? true : false;
		return end;
	}
	std::string creader::read_string(std::string section, std::string var) {
		std::string end;
		GetPrivateProfileString(section.c_str(), var.c_str(), "Eror", (LPSTR)end.c_str(), 255, filename);
		return end;
	}


	cwriter::cwriter(std::string file)
	{
		memset(filename, 0x00, 255);
		memcpy(filename, file.c_str(), strlen(file.c_str()));
	}
	void cwriter::write_int(std::string section, std::string var, int value) {
		char val[255];
		sprintf_s(val, "%d", value);
		WritePrivateProfileString(section.c_str(), var.c_str(), val, filename);
	}
	void cwriter::write_float(std::string section, std::string var, float value) {
		char val[255];
		sprintf_s(val, "%f", value);
		WritePrivateProfileString(section.c_str(), var.c_str(), val, filename);
	}
	void cwriter::write_bool(std::string section, std::string var, bool value) {
		char val[255];
		sprintf_s(val, "%s", value ? "True" : "False");
		WritePrivateProfileString(section.c_str(), var.c_str(), val, filename);
	}
	void cwriter::write_string(std::string section, std::string var, std::string value) {
		WritePrivateProfileString(section.c_str(), var.c_str(), value.c_str(), filename);
	}
}
