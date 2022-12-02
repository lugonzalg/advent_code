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

			if p2 == "Y":
				p2_score += game[p1]["score"] + 3
				print("draw")
			elif p2 == "X":
				if p1 == "A":
					p2_score += game["C"]["score"] + 0
				if p1 == "B":
					p2_score += game["A"]["score"] + 0
				if p1 == "C":
					p2_score += game["B"]["score"] + 0
				print("loose")
			else:
				if p1 == "A":
					p2_score += game["B"]["score"] + 6
				if p1 == "B":
					p2_score += game["C"]["score"] + 6
				if p1 == "C":
					p2_score += game["A"]["score"] + 6
				print("win")
			print(p2_score)

	print(p1_score)
	print(p2_score)

if __name__ == "__main__":
	main()

