// to use std::getenv()
#define _CRT_SECURE_NO_WARNINGS

#include "headers/Init.h"
#include <iostream>
#include <regex>
#include <memory>
#include <cstdlib>
#include <string>

std::string const LOCALAPP = std::string(std::getenv("LOCALAPPDATA"));
std::string const HOME = std::string(std::getenv("USERPROFILE"));

std::string WALLPAPER_PATH = LOCALAPP + "\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets";
std::string LIST_PATH = LOCALAPP + "\\SaveLockImage\\";
std::string OUTPUT_PATH = HOME + "\\SaveLockImage\\";

namespace {
	template<typename T>
	void save_image(T t) {
		auto size = std::filesystem::file_size(t);
		// 300000byte -> 300kb
		if (size <= 300000) {
			return;
		}
		else {
			bool a = std::filesystem::copy_file(t, std::filesystem::path(OUTPUT_PATH + t.filename().string() + ".jpg"));
		}
	}
}

Init::Init() {
	// check these Dir's exists and make them if not
	std::filesystem::create_directories(LIST_PATH);
	std::filesystem::create_directories(OUTPUT_PATH);
	LIST_PATH += "\\list.txt";
	ofs_list = std::ofstream(LIST_PATH, std::ios::app);
}

Init* Init::scan() {
	for (const std::filesystem::directory_entry& x : std::filesystem::directory_iterator(WALLPAPER_PATH)) {
		std::string filename = x.path().filename().string();
		std::string temp;
		bool exists = true;
		std::ifstream ifs(LIST_PATH, std::ios::in);
		while (!ifs.eof()) {
			std::getline(ifs, temp);
			if (temp.find(filename) != std::string::npos) {
				goto MATCH;
			}
		}
		save_image(x.path());
		ofs_list << filename << std::endl;
	}
MATCH:
	return this;
}