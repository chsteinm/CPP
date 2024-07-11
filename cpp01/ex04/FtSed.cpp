#include "FtSed.hpp"

FtSed::FtSed(std::string s1, std::string s2) : s1(s1), s2(s2) {
	std::cout << "Constuctor called" << std::endl;
}

FtSed::~FtSed() {
	std::cout << "Destructor called" << std::endl;
}

bool	FtSed::openFile(const char* filename) {
	this->file.open(filename);
	return (this->file.is_open());
}

bool	FtSed::createFileReplace(const char* filename) {
	std::string filenameReplace = filename;
	filenameReplace.append(".replace");
	this->fileReplace.open(filenameReplace);
	return (this->fileReplace.is_open());
}