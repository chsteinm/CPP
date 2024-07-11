# ifndef FTSED_HPP
#define FTSED_HPP

#include <iostream>
#include <string>
#include <fstream>

class FtSed {

private :
	std::ifstream	file;
	std::ofstream	fileReplace;
	std::string		s1;
	std::string		s2;

public :
	FtSed(std::string s1, std::string s2);
	~FtSed();
	void	setS1AndS2(std::string& s1, std::string& s2);
	bool	openFile(const char* filename);
	bool	createFileReplace(const char* filename);
	void	ftsed();
};

#endif