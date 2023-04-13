#include <iostream>
#include <fstream>
#include <string>
#include <thread>

void write_function(std::string file_name, std::string text) {
	std::ofstream out;
	out.open(file_name, std::ios::app);
	if (out.is_open()) {
		out << text << std::endl;

	}
}


int main() {
	std::string file_name;
	std::cout << "File name is ";
	std::cin >> file_name;
	std::string r;
	getline(std::cin, r);
	std::cout << "write something to the file;" << std::endl;
	std::cout << "write \'e\' to finish;" << std::endl;
	std::cout << "-------------" << std::endl;
	while (true) {
		std::string text;
		getline(std::cin, text);
		if (text == "e") {
			break;
		}
		std::thread wthr(write_function, file_name, text);
		wthr.join();
	}
}

