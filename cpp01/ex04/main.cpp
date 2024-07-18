#include "FtSed.hpp"

int	main(int argc, char** argv) {
	if (argc != 4 || !*argv[2])
		return 1;
	FtSed sed(argv[2], argv[3]);
	if (sed.openFile(argv[1]) == false) {
		std::cout << argv[1] << " can't be open" << std::endl;
		return 2;
	}
	if (sed.createFileReplace(argv[1]) == false) {
		std::cout << "Can't create the replace file" << std::endl;
		return 3;
	}
	sed.ftsed();
	sed.closeFiles();
	return 0;
}