#include <string.h>

#include <vector>
#include <iostream>
#include <fstream>

static void	handle_vector(int i, int from, int to, std::vector<char> v[3])
{
	char	tmp;
	int		j;
	std::vector<char> v_tmp;

	j = i;
	for (; j; j--)
	{
		tmp = v[from].front();
		v[from].erase(v[from].begin());
		v_tmp.push_back(tmp);
	}
	for (; i; i--)
	{
		tmp = v_tmp.back();
		v_tmp.pop_back();
		v[to].insert(v[to].begin(), tmp);
	}
	(void)to;
}

int main(void)
{
	std::vector<char> v[10] = {{}, {'V','N','F', 'S', 'M', 'P', 'H', 'J'},{'Q','D','J', 'M', 'L', 'R', 'S'},{'B', 'W', 'S', 'C', 'H', 'D', 'Q', 'N'}, {'L', 'C', 'S', 'R'}, {'B', 'F', 'P', 'T', 'V', 'M'}, {'C', 'N', 'Q', 'R', 'T'}, {'R', 'V', 'G'}, {'R', 'L', 'D', 'P', 'S', 'Z', 'C'}, {'F', 'B', 'P', 'G', 'V', 'J', 'S', 'D'}};
	//std::vector<char> v[4] = {{}, {'N', 'Z'}, {'D', 'C', 'M'}, {'P'}};
	//std::ifstream	in("test_output.txt");
	std::ifstream	in("output.txt");
	char	buff[100];
	int		num_set[3];
	int		j;

	while (1)
	{
		memset(buff, 0, 100);
		in.getline(buff, 100);
		j = 0;
		memset(&num_set, 0, sizeof(int) * 3);
		for (size_t i = 0; i < strlen(buff); i++)
		{
			while (!isdigit(buff[i]))
					i++;
			while (isdigit(buff[i]))
			{
				num_set[j] = num_set[j] * 10 + buff[i] - 48;
				i++;
			}
			j++;
		}
		handle_vector(num_set[0], num_set[1], num_set[2], v);
		if (in.peek() == EOF)
			break ;
	}
	for (int i = 1; i < 10; i++)
	{
		std::cout << v[i][0];
		//std::cout << "[" << i << "]: " << v[i][0];
	}

	return (0);
}
