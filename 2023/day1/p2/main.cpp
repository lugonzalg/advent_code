#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

# define TARGET_FILE "sample.txt"

/*

   Los digitos pueden estart en formato numero como hasta ahora
   o pueden seguir el siguente patron:

   one, two, three, four, five, six, seven, eight, nine

   hacer una funcion para buscar algune de estos patrones

 */

int main() {

	std::ifstream file(TARGET_FILE);
	int n1, n2, res = 0;
	std::vector<std::pair<std::string, int> > v(9);

	v[0] = std::make_pair("one", '1');
	v[1] = std::make_pair("two", '2');
	v[2] = std::make_pair("three", '3');
	v[3] = std::make_pair("four", '4');
	v[4] = std::make_pair("five", '5');
	v[5] = std::make_pair("six", '6');
	v[6] = std::make_pair("seven", '7');
	v[7] = std::make_pair("eight", '8');
	v[8] = std::make_pair("nine", '9');

	for (std::string line; std::getline(file, line);) {

		n1 = -1;
		n2 = -1;

	std::cout << "line: " << line << std::endl;
		for (size_t i = 0; i < line.size(); i++) {

			if (isdigit(line[i])) {
				if (n1 == -1)
					n1 = line[i];
				else
					n2 = line[i];
			} else {
				for (auto digit: v) {
					if (!strncmp(line.c_str() + i, digit.first.c_str(), digit.first.size())) {
						std::cout << digit.first << std::endl;
						if (n1 == -1)
							n1 = digit.second;
						else
							n2 = digit.second;
					}
				}
			}
		}
	std::cout << "n1: " << n1 - '0' << " n2: " << n2 - '0' << std::endl;
	std::cout << "res: " << res << std::endl;
		if (n2 == -1)
			res += (n1 -'0') * 10 + (n1 - '0');
		else
			res += (n1 - '0') * 10 + (n2 - '0');
	std::cout << "res: " << res << std::endl;
	}


	return 0;
}
