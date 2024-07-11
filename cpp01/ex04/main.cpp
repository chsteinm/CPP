#include "FtSed.hpp"

int	main(int argc, char** argv) {
	if (argc != 4)
		return 1;
	FtSed sed(argv[2], argv[3]);
	if (sed.openFile(argv[1]) == false) {
		std::cout << argv[1] << ": file not found" << std::endl;
		return 2;
	}
	
	return 0;
}