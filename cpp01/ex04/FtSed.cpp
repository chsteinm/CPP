#include "FtSed.hpp"

FtSed::FtSed(std::string s1, std::string s2) : _s1(s1), _s2(s2) {
	std::cout << "Constuctor called" << std::endl;
}

FtSed::~FtSed() {
	std::cout << "Destructor called" << std::endl;
}

bool	FtSed::openFile(const char* filename) {
	this->_file.open(filename);
	return (this->_file.is_open());
}

bool	FtSed::createFileReplace(const char* filename) {
	std::string filenameReplace = filename;
	filenameReplace.append(".replace");
	this->_fileReplace.open(filenameReplace.c_str());
	return (this->_fileReplace.is_open());
}

void	FtSed::ftsed() {
	std::string::size_type lenS1 = this->_s1.size();
	std::string::size_type lenS2 = this->_s2.size();
	std::string::size_type found;
	std::string	line;

	while (std::getline(this->_file, line)) {
		found = 0;
		found = line.find(this->_s1);
		while (found != std::string::npos) {
			line.erase(found, lenS1);
			line.insert(found, this->_s2);
			found = line.find(this->_s1, found + lenS2);
		}
		this->_fileReplace << line << std::endl;
	}
}

void	FtSed::closeFiles() {
	this->_file.close();
	this->_fileReplace.close();
}