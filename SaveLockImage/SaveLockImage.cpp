#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>

std::string wallpaper_path = "C:\\Users\\minio\\AppData\\Local\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets";

void find() {
	std::ofstream ofs("C:\\Users\\minio\\Desktop\\result.txt", std::ios::out);
	ofs << std::endl;
	for (const std::filesystem::directory_entry& x : std::filesystem::directory_iterator(wallpaper_path)) {
		/*std::cout << x.path() << std::endl;*/
		std::ofstream ofs("C:\\Users\\minio\\Desktop\\result.txt", std::ios::app);
		ofs << x.path() << std::endl;
	}
}

int main()
{
	std::cout << "Image Dir Path is here; " << wallpaper_path << std::endl;
	find();
}