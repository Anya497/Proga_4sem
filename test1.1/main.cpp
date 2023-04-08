#include <iostream>
#include <fstream>
#include <string>
#include <thread>

void write_function(std::string file_name, std::string text) {
	/*std::cout << "write something to the file" << std::endl;
	std::cout << "-------------" << std::endl;*/
	std::ofstream out;
	out.open(file_name, std::ios::app);
	if (out.is_open()) {
		/*std::string line;
		getline(std::cin, line);*/
		out << text << std::endl;

	}
}

void read_function(std::string file_name) {
	std::cout << "file content" << std::endl;
	std::cout << "-------------" << std::endl;
	std::ifstream in;
	in.open(file_name);
	if (in.is_open()) {
		std::string line;
		while (getline(in, line)) {
			std::cout << line << std::endl;
		}
	}
}

int main() {
	std::string file_name;
	std::cout << "File name is ";
	std::cin >> file_name;
	std::string r;
	getline(std::cin, r);
	while (true) {
		std::cout << "write something to the file;" << std::endl;
		std::cout << "write \'e\' to finish;" << std::endl;
		std::cout << "-------------" << std::endl;
		std::string text;
		getline(std::cin, text);
		if (text == "e") {
			break;
		}
		std::thread wthr(write_function, file_name, text);
		wthr.join();
		std::thread rthr(read_function, file_name);
		rthr.join();
	}
}

