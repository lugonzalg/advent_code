#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
 Tengo las loterias. Cada match de numero en la loteria me da una copia de la
 siguiente loteria en forma incremental.

 	i.e

		En la primera loteria hay 4 matches. Se genera un copia de los siguientes
		4.

  En definicion tengo que guardar la cantidad de copias que tengo de cada loteria,
  porque afecta a la manera en que se multiplican.

  Recorrer el archivo una vez para crear un vector de matches.
 */

int main(int argc, char *argv[]) {

	ifstream file(argv[1]);
	unsigned points = 0;
	int count;
	size_t idx;
	size_t pos = 0;
	vector<int>	matches;

	for (string line; getline(file, line);)
		matches.push_back(1);

	ifstream file2(argv[1]);
	vector<int>	numbers;
	for (string line; getline(file2, line);) {

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

		for (size_t i = 0; i < count; i++) {
			matches[pos + i + 1] += matches[pos];
		}
		numbers.clear();
		std::cout << "Line: " << line << std::endl;
		pos++;
	}
	int sum = 0;
	for (auto match: matches)
		sum += match;
	cout << "Sum: " << sum << std::endl;

	return 0;
}
