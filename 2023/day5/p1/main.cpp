#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

# define DST	0
# define SRC	1
# define RANGE  2

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;

	ifstream file(argv[1]);
	vector<int> seeds;
	vector<vector<int> > v;
	string line;
	size_t idx = -1;

	getline(file, line);
	cout << line << endl;
	v.push_back({});
	for (size_t i = 7; i < line.size(); i++) {
		seeds.push_back(stoi(&line[i]));
		while (isdigit(line[i])) i++;
	}
	getline(file, line);

	for (; getline(file, line);) {
		if (line.find("map") != -1) {
			v.push_back({});
			idx++;
		}
		else if (line.size() != 1){

			for (size_t i = 0; i < line.size(); i++) {
				v[idx].push_back(stoi(&line[i]));
				while (isdigit(line[i])) i++;
			}

		}
		cout << line << endl;
	}
	int dst;
	for (auto seed: seeds) {
		dst = seed;
		cout << seed << endl;
		for (auto &data: v) {
			for (size_t i = 0; i < data.size(); i += 3) {
				if (abs(data[SRC] - seed) <= data[RANGE]) {
					cout << "Seed: " << seed << endl;
				}
			}
		}
	}

	return 0;
}
