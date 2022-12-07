with open("sum.txt") as fd:
	num_sum = 0
	while (1):
		num = fd.readline().rstrip('\n')
		if not num:
			break
		try:
			num_sum += int(num)
		except:
			pass
	print(num_sum)
