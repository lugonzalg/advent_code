#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

static long long get_value(vector<long> &v) {

	long long value;
	long long isZero;
	vector<vector<long>> vv;
	vector<long> tmp(v);

	vv.push_back(v);
	while (true) {

		vector<long> holder;
		isZero = 0;
		for (size_t i = 1; i < tmp.size(); i++) {
			value = tmp[i] - tmp[i - 1];
			holder.push_back(value);

			if (value)
				isZero = value;
		}
		if (!isZero)
			break ;
		vv.push_back(holder);
		tmp = holder;
	}

	long long last_val = 0;
	for (auto rit = vv.rbegin(); rit != vv.rend(); rit++) {
		auto rval = rit->rbegin();

		cout << "Size: " << rit->size() << endl;
		cout << "Values: " << last_val << endl;
		cout << "rval: " << *rval << endl;
		last_val += (*rval);
	}
	return last_val;
}

static void resolve(char *path) {

	long long total = 0;
	ifstream file(path);
	vector<long> v;

	for (string line; getline(file, line);) {

		cout << line << endl;
		for (size_t idx = 0; idx < line.size(); idx++) {

			while (!isdigit(line[idx]) and line[idx] != '-') idx++;
			v.push_back(stol(&line[idx]));
			while (isdigit(line[idx]) or line[idx] == '-') idx++;
		}

		//cout << "Size: " << v.size() << endl;
		total += get_value(v);
		v.clear();
	}
	cout << "Total: " << total << endl;

}

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;

	resolve(argv[1]);

	return 0;
}
