#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

static void find_path(char *filepath) {

	ifstream	file(filepath);
	unordered_map<string, pair<string, string> > uom;
	vector<string>	position;
	string line, steps, key, left, right;
	size_t count = 1;

	getline(file, steps);
	getline(file, line);

	for (; getline(file, line); ) {
		key = line.substr(0, 3);
		if (key[2] == 'A')
			position.push_back(key);
		//cout << "Key(1): " << key << endl;

		left = line.substr(7, 3);
		//cout << "Key(2): " << left << endl;

		right = line.substr(12, 3);
		//cout << "Key(3): " << right << endl;
		uom[key] = make_pair(left, right);

	}

	for (auto &pos: position) {
		cout << "pos: " << pos << endl;
	}
	cout << "position size: " << position.size() << endl;
	size_t end;
	for (size_t idx = 0; ; idx = (idx + 1) % steps.size()) {

		end = 0;
		for (auto &pos: position) {

			if (steps[idx] == 'L')
				pos = uom[pos].first;
			else
				pos = uom[pos].second;

			if (pos[2] == 'Z')
				end++;
		}

		if (end > 4)
			cout << "End: " << end << endl;

		if (end == position.size())
			break ;

		count++;
	}
	cout << "Count: " << count << endl;
}

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;
	find_path(argv[1]);

	return 0;
}
