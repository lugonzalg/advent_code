with open("sum.txt") as fd:
	num_sum = 0
	num_list = sorted(int(x.rstrip()) for x in fd.readlines())
	print(num_list)
	print(sum(num_list))
	print(max(num_list))
