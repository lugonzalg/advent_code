#include <iostream>
#include <deque>
#include <fstream>

using namespace std;

typedef struct s_coords {

	int x;
	int y;
	int steps;

	int xdir;
	int ydir;

}	t_coords;

static bool	moves(t_coords &p, deque<string> &matrix) {


	cout << "Position: " << matrix[p.y][p.x] << endl;
	if (matrix[p.y][p.x] == 'F') {

		if (p.xdir == -1) {
			p.xdir = 0;
			p.ydir = 1;
		} else {
			p.xdir = 1;
			p.ydir = 0;
		}

	}
	else if (matrix[p.y][p.x] == '7') {

		if (p.xdir == 1) {
			p.xdir = 0;
			p.ydir = 1;
		} else {
			p.xdir = -1;
			p.ydir = 0;
		}

	}
	else if (matrix[p.y][p.x] == 'J') {

		if (p.xdir == 1) {
			p.xdir = 0;
			p.ydir = -1;
		} else {
			p.xdir = -1;
			p.ydir = 0;
		}
	}
	else if (matrix[p.y][p.x] == 'L') {

		if (p.xdir == -1) {
			p.xdir = 0;
			p.ydir = -1;
		} else {
			p.xdir = 1;
			p.ydir = 0;
		}
	}
	else if (matrix[p.y][p.x] == '-') {

		if (p.xdir == 1) {
			p.xdir = 1;
			p.ydir = 0;
		} else {
			p.xdir = -1;
			p.ydir = 0;
		}
	}
	else if (matrix[p.y][p.x] == '|') {

		if (p.ydir == 1) {
			p.xdir = 0;
			p.ydir = 1;
		} else {
			p.xdir = 0;
			p.ydir = -1;
		}
	} else
		return false;

	p.x += (p.xdir * 1);
	p.y += (p.ydir * 1);
	p.steps++;
	return true;

}

static void find_path(t_coords p1, t_coords p2, deque<string> &matrix) {

	while (1) {

		moves(p1, matrix);
		moves(p2, matrix);

		if (p1.x == p2.x and p1.y == p2.y)
			break ;
	}
	cout << "Score: " << p1.steps << endl;
	cout << "Score: " << p2.steps << endl;

}

static void set_position(t_coords &p1, t_coords &p2, deque<string> matrix) {

	t_coords tmp1;
	t_coords tmp2;
	bool found = false;

	tmp1 = p1;
	tmp2 = p2;

	if (matrix[p1.y + 1][p1.x] != '.') {

		cout << "pos: " << matrix[p1.y + 1][p1.x] << endl;
		if (matrix[p1.y + 1][p1.x] == '|' or matrix[p1.y + 1][p1.x] == 'L' or
		matrix[p1.y + 1][p1.x] == 'J') {

			tmp1.y++;
			tmp1.ydir = 1;
			found = true;

		}

	}
	if (matrix[p1.y - 1][p1.x] != '.') {

		if (matrix[p1.y - 1][p1.x] == '|' or matrix[p1.y - 1][p1.x] == 'F' or
		matrix[p1.y - 1][p1.x] == '7') {
			if (found) {
				tmp2.y--;
				tmp2.ydir = -1;
			} else {
				tmp1.y--;
				tmp1.ydir = -1;
			}
			found = true;
		}

	}
	if (matrix[p1.y][p1.x + 1] != '.') {

		if (matrix[p1.y][p1.x + 1] == '-' or matrix[p1.y][p1.x + 1] == 'J' or
		matrix[p1.y][p1.x + 1] == '7') {
		if (found) {
			tmp2.x++;
			tmp2.xdir = 1;
		} else {
			tmp1.x++;
			tmp1.xdir = 1;
		}
		found = true;
		}

	}
	if (matrix[p1.y][p1.x - 1] != '.') {

		if (matrix[p1.y][p1.x - 1] == '-' or matrix[p1.y][p1.x - 1] == 'L' or
		matrix[p1.y][p1.x - 1] == 'F') {

			if (found) {
				tmp2.x--;
				tmp2.xdir = -1;
			} else {
				tmp1.x--;
				tmp1.xdir = -1;
			}
			found = true;

		}

	}

	p1 = tmp1;
	p2 = tmp2;


}

static void program(char *path) {

	ifstream		file(path);
	deque<string>  matrix;
	t_coords		p1 = {0};
	t_coords		p2 = {0};

	p1.x = -1;
	for (string line; getline(file, line); ) {

		line = "." + line + ".";
		matrix.push_back(line);
		cout << line << endl;
		if (p1.x == -1) {

			p1.x = line.find('S');
			p1.y++;

		}

	}
	matrix.push_back("..................................................................................................................................................");
	matrix.push_front("..................................................................................................................................................");

	cout << "(p1) Start position: " << matrix[p1.y][p1.x] << endl;
	p2 = p1;

	cout << "(p1) Start position: " << matrix[p1.y][p1.x] << endl;
	cout << "(p2) Start position: " << matrix[p2.y][p2.x] << endl;
	set_position(p1, p2, matrix);
	cout << "(p1) Start position: " << matrix[p1.y][p1.x] << endl;
	cout << "(p2) Start position: " << matrix[p2.y][p2.x] << endl;
	find_path(p1, p2, matrix);

}

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;

	program(argv[1]);

	return 0;
}
