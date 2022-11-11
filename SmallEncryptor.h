#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>


class Encryptor {
public:
	std::string ReadFile(std::string file);
	void Encrypt(std::string buffer, std::string file_path_to_write);
};


std::string Encryptor::ReadFile(std::string file) {
	std::ifstream f(file);
	std::string ret;
	if (f) {
		std::ostringstream ss;
		ss << f.rdbuf();
		ret = ss.str();
	}
	f.close();
	return ret;
}

void Encryptor::Encrypt(std::string buffer, std::string file_path_to_write) {
	// generate a number
	srand((unsigned)time(0));
	int key = (rand() % 100) + 1;
	std::cout << "Key for encryption is " << key << std::endl;

	Encryptor k;
	std::string foo = k.ReadFile(file_path_to_write);

	std::ofstream f(file_path_to_write);
	for (int i = 0; i != file_path_to_write.length(); i++) {
		std::cout << char(file_path_to_write[i] + key);
		if (f) {
			f << char(file_path_to_write[i] + key);
		}
	}
	f.close();
}
