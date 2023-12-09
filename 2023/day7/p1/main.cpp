#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 Tengo que calcular un score en base a unas manos de poker que recibo como input
 Hay 5 tipos de combinaciones:

 	5 iguales
	full house
	tripe
	doble
	par
	max

 Tengo que crear una estructura de datos que guarde las manos y crear un score
 con la carta mas alta. El score sera la multiplicacion de cualquier pareja superior
 a 2.

 Para guardar la carta mas alta simplemente guarda el caracter mas grande y si es
 un A, darle prioridad.

 Fail de intento por no pensar bien.

 El metodo de guardar el score funciona bien, ahora necesito otro score para las
 manos que son iguales, como puedo diferenciar las cartas altas?

 Lo primero que se me ha ocurrido es utilizar operaciones matematicas para conseguir
 algun resultado.

 Aunque creo que cada player debe guardar un track la lista de sus cartas mas altas
 como maximo se van a buscar 3 cartas en el peor de los casos.

 Anadirle un vector de 3 a cada usuario para guarda sus cartas.
 */

typedef struct s_player {

	int score; //combinacion
	int bet; //apuesta
	vector<pair<int, int> > cards; //mayores cartas

}	t_player;

static bool sort_hand(pair<int, int> card1, pair<int, int> card2) {
	if (card1.first < card2.first) return false;
	if (card1.second >= card2.second) return false;
	return true;
}

static bool sort_players(t_player &p1, t_player &p2) {

	if (p1.score > p2.score) return false;
	if (p1.score < p2.score) return true;
	for (size_t i = 0; i < p1.cards.size() and i < p2.cards.size(); i++) {
		if (p1.score >= p2.score and p1.cards[i].second > p2.cards[i].second) return false;
		if (p1.score >= p2.score and p1.cards[i].second < p2.cards[i].second) return true;
	}
	return true;
}

int main(int argc, char *argv[]) {

	if (argc != 2)
		return 1;

	ifstream file(argv[1]);
	unordered_map<char, pair<int, int>> uom;
	vector<t_player> scores;

	uom['2'] = make_pair(0, 1);
	uom['3'] = make_pair(0, 2);
	uom['4'] = make_pair(0, 3);
	uom['5'] = make_pair(0, 4);
	uom['6'] = make_pair(0, 5);
	uom['7'] = make_pair(0, 6);
	uom['8'] = make_pair(0, 7);
	uom['9'] = make_pair(0, 8);
	uom['T'] = make_pair(0, 9);
	uom['J'] = make_pair(0, 10);
	uom['Q'] = make_pair(0, 11);
	uom['K'] = make_pair(0, 12);
	uom['A'] = make_pair(0, 13);

	scores.reserve(1000);
	size_t idx;
	for (string line; getline(file, line); ) {

		t_player p;

		p.score = 1;

		for (idx = 0; line[idx] != ' '; idx++) {
			uom[line[idx]].first++;

			if (uom[line[idx]].first > 1)
				p.score *= uom[line[idx]].first;
		}
		while (!isdigit(line[idx])) idx++;
		p.bet = stoi(&line[idx]);

		for (auto &elem: uom) {
			if (elem.second.first)
				p.cards.push_back(make_pair(elem.second.first, elem.second.second));
			elem.second.first = 0;
		}

		sort(p.cards.begin(), p.cards.end(), sort_hand);
		scores.push_back(p);
		cout << line << endl;
	}
	cout << "Scores: " << scores.size() << endl;
	sort(scores.begin(), scores.end(), sort_players);
	int final_scores = 0;
	for (size_t i = 0; i < scores.size(); i++) {
		final_scores += scores[i].bet * (i + 1);
		cout << "score: " << scores[i].score;
		cout << "bet: " << scores[i].bet << endl;
	}
	cout<<final_scores;

	return 0;
}
