#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;

	ifstream file(argv[1]);
	vector<int>	time;
	vector<int>	distance;

	time.reserve(3);
	distance.reserve(3);
	string line;
	getline(file, line);
	for (size_t idx = 5; idx < line.size(); idx++) {
		if (isdigit(line[idx])) {
			time.push_back(stoi(&line[idx]));
			while (isdigit(line[idx])) idx++;
		}
	}
	getline(file, line);
	for (size_t idx = 5; idx < line.size(); idx++) {
		if (isdigit(line[idx])) {
			distance.push_back(stoi(&line[idx]));
			while (isdigit(line[idx])) idx++;
		}
	}

	int minv;
	int holder;
	int count = 1;
	int count_holder;
	for (size_t idx = 0; idx < distance.size(); idx++) {

		minv = distance[idx] / time[idx];
		if (distance[idx] % time[idx])
			minv++;
		time[idx] -= minv;
		while (time[idx] * minv <= distance[idx]) {
			time[idx]--;
			minv++;
		}
		holder = minv;
		count_holder = 0;
		while (time[idx] >= holder) {
			count_holder++;
			time[idx]--;
			minv++;
		}
		cout << "count holder: " << count_holder << endl;
		count *= count_holder;
	}
	cout << "count: " << count << endl;
}
