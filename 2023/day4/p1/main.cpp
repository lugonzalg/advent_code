#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {

	ifstream file(argv[1]);
	unsigned points = 0;
	int count;
	size_t idx;

	vector<int>	numbers;
	for (string line; getline(file, line);) {

		idx = line.find(":");

		count = 0;
		for (; idx < line.size(); idx++) {
			if (isdigit(line[idx])) {
				numbers.push_back(stoi(&line[idx]));
				while (isdigit(line[idx])) idx++;
			} else if (line[idx] == '|')
				break ;
		}

		count = 0;
		for (; idx < line.size(); idx++) {

			if (isdigit(line[idx])) {

				if (find(numbers.begin(), numbers.end(), stoi(&line[idx])) != numbers.end())
					count++;

				while (isdigit(line[idx])) idx++;
			}

		}
		if (count)
			points += (pow(2, count - 1));
		numbers.clear();
		std::cout << "Line: " << line << std::endl;
	}
	cout << "Points: " << points << std::endl;

	return 0;
}
