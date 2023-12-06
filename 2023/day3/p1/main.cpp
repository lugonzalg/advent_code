#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

/*
Problema:
	Tengo que buscar dentro de un input de texto, numeros aislados, el
	objetivo es devolver la suma de todos los numeros que son adyacentes
	a cualquier signo ademas de puntos.

	i.e

		..1...2.
		.@......

	Para este caso 1 tendria como elementos adyacente . y @
	El numero 2 solo tendria como adyacente . (puntos), por lo que
	hay que omitirlo.
 */

int g_total = 0;

static size_t check_matrix_num(std::vector<std::string> matrix, size_t y, size_t x) {
	int num = 0;

	num = std::stoi(&matrix[y][x]);

	if (matrix[y - 1][x - 1] != '.' or
	matrix[y][x - 1] != '.' or
	matrix[y + 1][x - 1] != '.') {
		g_total += num;
		while (isdigit(matrix[y][x])) x++;
		return x;
	}

	for (; isdigit(matrix[y][x]); x++) {

		if (matrix[y - 1][x] != '.' or
		matrix[y + 1][x] != '.') {
			g_total += num;
			while (isdigit(matrix[y][x])) x++;
			return x;
		}
	}

	if (matrix[y - 1][x] != '.' or
	matrix[y][x] != '.' or
	matrix[y + 1][x] != '.')
		g_total += num;
	return x;
}

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;

	std::ifstream	file(argv[1]);
	std::vector<std::string> matrix;
	std::string tmp = "...............................................................................................................................................";
	int sum = 0;

	matrix.push_back(tmp);
	for (std::string line; getline(file, line);)
		matrix.push_back("." + line + ".");
	matrix.push_back(tmp);

	for (size_t y = 1; y < matrix.size() - 1; y++) {

		for (size_t x = 0; x < matrix[y].size();) {
			if (isdigit(matrix[y][x]))
				x = check_matrix_num(matrix, y, x);
			else
				x++;
		}

	}
	std::cerr << "Total:" << g_total << std::endl;

	return 0;
}
