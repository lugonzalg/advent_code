#!/bin/python3

game = {
	"A" : {
	"score" : 1,
	"type" : "rock"
	},
	"B" : {
	"score" : 2,
	"type" : "paper"
	},
	"C" : {
	"score" : 3,
	"type" : "scissor"
	},
	"X" : {
	"score" : 1,
	"type" : "rock"
	},
	"Y" : {
	"score" : 2,
	"type" : "paper"
	},
	"Z" : {
	"score" : 3,
	"type" : "scissor"
	}
}

def main() -> None:
	score = [0, 0]
	p1_score = 0
	p2_score = 0
	#with open("test_output.txt") as fd:
	with open("output.txt") as fd:
		while (1):
			line = fd.readline().rstrip('\n')
			if not line:
				break
			p1 = line[0]
			p2 = line[2]

			if game[p1]["type"] == game[p2]["type"]:
				p1_score += 3 + game[p1]["score"]
				p2_score += 3 + game[p2]["score"]
				print("draw")
			elif game[p1]["type"] == "rock":
				if game[p2]["type"] == "scissor":
					p1_score += game[p1]["score"] + 6
					p2_score += game[p2]["score"] + 0
				else:
					p1_score += game[p1]["score"] + 0
					p2_score += game[p2]["score"] + 6
			elif game[p1]["type"] == "paper":
				if game[p2]["type"] == "rock":
					p1_score += game[p1]["score"] + 6
					p2_score += game[p2]["score"] + 0
				else:
					p1_score += game[p1]["score"] + 0
					p2_score += game[p2]["score"] + 6
			elif game[p1]["type"] == "scissor":
				if game[p2]["type"] == "paper":
					p1_score += game[p1]["score"] + 6
					p2_score += game[p2]["score"] + 0
				else:
					p1_score += game[p1]["score"] + 0
					p2_score += game[p2]["score"] + 6

	print(p1_score)
	print(p2_score)

if __name__ == "__main__":
	main()

