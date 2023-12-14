#include <deque>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

static long long get_value(deque<long> &v) {

	long long value;
	long long isZero;
	deque<deque<long>> vv;
	deque<long> tmp(v);

	vv.push_back(v);
	while (true) {

		deque<long> holder;
		isZero = 0;
		for (size_t n = tmp.size() - 1; n > 0; n--) {
			value = tmp[n] - tmp[n - 1];
			holder.push_front(value);

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
		auto rval = rit->begin();

		cout << "Size: " << rit->size() << endl;
		cout << "Values: " << last_val << endl;
		cout << "rval: " << *rval << endl;
		last_val = *rval - last_val;
	}
	return last_val;
}

static void resolve(char *path) {

	long long total = 0;
	ifstream file(path);
	deque<long> v;

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
