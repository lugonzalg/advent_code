#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

static void find_path(char *filepath) {

	ifstream	file(filepath);
	unordered_map<string, pair<string, string> > uom;
	string line, steps, key, left, right;
	size_t count = 1;

	getline(file, steps);
	getline(file, line);

	for (; getline(file, line); ) {
		key = line.substr(0, 3);
		//cout << "Key(1): " << key << endl;

		left = line.substr(7, 3);
		//cout << "Key(2): " << left << endl;

		right = line.substr(12, 3);
		//cout << "Key(3): " << right << endl;
		uom[key] = make_pair(left, right);

	}

	key = "AAA";
	for (size_t idx = 0; ; idx = (idx + 1) % steps.size()) {


		if (steps[idx] == 'L')
			key = uom[key].first;
		else
			key = uom[key].second;

		if (key == "ZZZ")
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
