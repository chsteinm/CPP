# ifndef FTSED_HPP
#define FTSED_HPP

#include <iostream>
#include <string>
#include <fstream>

class FtSed {

private :
	std::ifstream	_file;
	std::ofstream	_fileReplace;
	std::string		_s1;
	std::string		_s2;

public :
	FtSed(std::string s1, std::string s2);
	~FtSed();
	bool	openFile(const char* filename);
	bool	createFileReplace(const char* filename);
	void	ftsed();
	void	closeFiles();
};

#endif