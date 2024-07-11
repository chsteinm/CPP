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
	this->fileReplace.open(filenameReplace.c_str());
	return (this->fileReplace.is_open());
}

void	FtSed::ftsed() {
	std::string::size_type lenS1 = this->s1.size();
	std::string::size_type lenS2 = this->s2.size();
	std::string::size_type found;
	std::string	line;

	std::getline(this->file, line);
	while (line.size()) {
		found = 0;
		found = line.find(this->s1);
		while (found != std::string::npos) {
			line.erase(found, lenS1);
			line.insert(found, this->s2);
			found = line.find(this->s1, found + lenS2);
		}
		this->fileReplace << line << std::endl;
		std::getline(this->file, line);
	}
}