#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	std::fstream file;
	std::string line;

	if (argc != 4)
	{
		std::cout << "Wrong arguments" << std::endl;
		return (1);
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::cout << "File not found" << std::endl;
		return (1);
	}
	std::ofstream rep((std::string)argv[1] + ".replace");
	while(std::getline(file, line))
	{
		size_t pos = line.find(argv[2]);
   		if (pos != std::string::npos)
		{
			line.erase(pos, ((std::string)argv[2]).length());
			line.insert(pos, (std::string)argv[3]);
		}
		if (!std::cin.eof())
			rep << line << std::endl;
	}
	rep.close();
	file.close();
}
