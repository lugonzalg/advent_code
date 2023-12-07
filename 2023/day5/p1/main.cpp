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
	vector<long> seeds;
	vector<vector<long> > v;
	string line;
	size_t idx = -1;

	getline(file, line);
	cout << line << endl;
	v.push_back({});
	for (size_t i = 7; i < line.size(); i++) {
		seeds.push_back(stol(&line[i]));
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
				v[idx].push_back(stol(&line[i]));
				while (isdigit(line[i])) i++;
			}

		}
		cout << line << endl;
	}
	long dst = 2147483647;
	long diff;
	for (auto seed: seeds) {
		cout << seed << endl;

		for (auto &data: v) {
			for (size_t i = 0; i < data.size(); i += 3) {
				diff = abs(data[i + SRC] - seed);
				if (diff <= data[i + RANGE] and data[i + SRC] <= seed) {
					cout << "range: " << diff << endl;
					seed = data[i + DST] + diff;
					cout << "Seed: " << seed << endl;
					break ;
				}
			}
		}

		cout << "Seed: " << seed << endl;
		dst = min(dst, seed);
	}
	cout << "Min: " << dst << endl;

	return 0;
}
