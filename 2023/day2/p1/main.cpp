#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>

using namespace std;

bool	get_token(const string &line, const string &delimiter, string token[2]) {
	size_t idx;

	idx = line.find(delimiter);
	//cout << "idx: " << idx << endl;
	if (idx == -1)
		return true;
	token[0] = line.substr(0, idx);
	token[1] = line.substr(idx + 1, line.size() - idx);
	return false;
}

# define RED	12
# define GREEN 	13
# define BLUE 	14

static void split(const string &src, const string &delimiter, vector<string> &dst) {

	string token;
	size_t start = 0;
	size_t end = 0;

	while (delimiter.find(delimiter.c_str(), start, delimiter.size()) != -1) start++;

	while (true) {
		end = src.find(delimiter, start);
		if (end == -1) {
			token = src.substr(start, src.size() - start);
			dst.push_back(token);
			break;
		}

		token = src.substr(start, end - start);
		dst.push_back(token);
		start = end + 1;
		//cout << dst.size();
	}
}

static bool is_valid_set(int sum[3]) {
	if (sum[0] > RED)
		return false;
	if (sum[1] > GREEN)
		return false;
	if (sum[2] > BLUE)
		return false;

	return true;
}

static bool	is_valid_game(const string &game, unordered_map<string, int> uom) {
	vector<string> data;
	size_t n;
	int sum[3] = {0};
	int holder = -1;

	split(game, " ", data);
	cout << data.size();
	for (auto elem: data) {

		n = elem.size();

		if (holder == -1)
			holder = stoi(elem);
		else {
			//cout << "elem: " << elem << endl;
			n = 0;
			for (auto colors: uom) {

				//cout << colors.first << endl;
				if (elem.find(colors.first) != -1) {
					sum[n] += holder;
					holder = -1;
					break ;
				}
				n++;
			}
			if (!is_valid_set(sum))
				return false;
			if (elem[elem.size() - 1] == ';') {
				sum[0] = 0;
				sum[1] = 0;
				sum[2] = 0;
			}
		}
	}
	if (!is_valid_set(sum))
		return false;
	return true;
}

int main(int argc, char *argv[]) {

	unordered_map<string, int> uom;
	string game[2];
	int id;
	int res = 0;

	if (argc != 2) {
		cerr << "No arguments given.\n";
		return 1;
	}

	uom["blue"] = 14;
	uom["green"] = 13;
	uom["red"] = 12;

	ifstream	file(argv[1]);

	for (string line; getline(file, line);) {
		get_token(line, ":", game);
		//cout << "First part: " << game[0] << endl;
		//cout << "Second part: " << game[1] << endl;
		if (is_valid_game(game[1], uom)) {
			res += stoi(&game[0][5]);
			cout << game[1] << " is valid!\n";
		}

	}
	cout << "Result: " << res << endl;

	return 0;
}
