#include <iostream>
#include <string>
#include <fstream>

# define TARGET_FILE "sample.txt"

int main() {

	std::ifstream file(TARGET_FILE);
	int n1, n2, res = 0;

	for (std::string line; std::getline(file, line);) {

		n1 = -1;
		n2 = -1;

	std::cout << "line: " << line << std::endl;
		for (auto c: line) {

			if (isdigit(c)) {
				if (n1 == -1)
					n1 = c;
				else
					n2 = c;
			}
		}
	std::cout << "res: " << res << std::endl;
		if (n2 == -1)
			res += (n1 -'0') * 10 + (n1 - '0');
		else
			res += (n1 - '0') * 10 + (n2 - '0');
	std::cout << "res: " << res << std::endl;
	}


	return 0;
}
