#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>

/*
Problema:

	Necesito buscar cualquier * que tengo como adyacente dos numeros, donde
	adyacente es su 3x3.

	La primera idea que se me ocurre es buscar primero *. Ahora, basandome en
	las 8 posible posiciones buscar un numero.

	Dentro del 3x3 hay que revisar 8 posiciones. La idea es ...

	Rollback, mismo metodo de busqueda anterior, esta vez cuando se encuentre una
	*, voy a crear un objeto con los datos de coordenadas y elementos adyacentes.

 */

typedef struct s_gear {

	int x;
	int y;
	size_t count;
	size_t sum;

}	t_gear;

typedef struct s_number {

	int x[2];
	int y;
	int    num;

}	t_number;

std::vector<t_gear> gears;
std::vector<t_number> numbers;

static size_t create_number(std::vector<std::string> matrix, size_t y, size_t x) {
	t_number number;

	number.num = std::stoi(&matrix[y][x]);
	number.y = y;
	number.x[0] = x;
	while (isdigit(matrix[y][x])) x++;
	number.x[1] = x - 1;
	numbers.push_back(number);
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
				x = create_number(matrix, y, x);
			else if (matrix[y][x] == '*') {
				t_gear gear;

				gear.count = 0;
				gear.sum = 1;
				gear.x = x;
				gear.y = y;
				gears.push_back(gear);
				x++;
			}
			else
				x++;
		}

	}
	for (auto &gear: gears) {
		for (auto &number: numbers) {
			if (abs(number.y - gear.y) < 2 and (abs(number.x[0] - gear.x) < 2 or abs(number.x[1] - gear.x) < 2)) {
				gear.count++;
				gear.sum *= number.num;
			}
		}
	}

	int count = 0;
	for (auto &gear: gears) {
		if (gear.count == 2)
			sum += gear.sum;
	}

	return 0;
}
