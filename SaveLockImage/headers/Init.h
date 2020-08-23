#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>

class Init {
public:
	Init();
	Init* scan();
private:
	std::ofstream ofs_list;
};
