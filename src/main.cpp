#include <mpEditor.hpp>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong amount of arguments" << std::endl;
		return 1;
	}

	struct stat file_stats;
	stat(argv[1], &file_stats);

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		assert(0);

	std::string data;

	data.resize(file_stats.st_size);
	std::cout << "SIZE" << file_stats.st_size << std::endl;

	read(fd, &data[0], file_stats.st_size);

	if (data.starts_with("ID3"))
		assert(0);
	else
		idv1_1_header out(data);

	return 0;

}