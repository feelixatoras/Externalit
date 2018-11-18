#pragma once
#include "../sdk.h"
namespace sdk {
	class creader
	{
	public:
		creader(std::string file);
		~creader() = default;
		int read_int(std::string section, std::string var);
		float read_float(std::string section, std::string var);
		bool read_bool(std::string section, std::string var);
		std::string read_string(std::string section, std::string var);
	private:
		char filename[255];
	}; extern creader* c_reader;
	class cwriter
	{
	public:
		cwriter(std::string filte);
		~cwriter() = default;
		void write_int(std::string section, std::string var, int value);
		void write_float(std::string section, std::string var, float value);
		void write_bool(std::string section, std::string var, bool value);
		void write_string(std::string section, std::string var, std::string value);
	private:
		char filename[255];
	}; extern cwriter* c_writer;
}