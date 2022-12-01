elf_max = [0,0,0]
curr_sum = 0
place_holder = 0

with open("output_bonus.txt") as fd:
#with open("test_output.txt") as fd:
    while True:
        line = fd.readline()
        if not line:
            break
        try:
            curr_sum += int(line.rstrip('\n'))
        except:
            for i, elem in enumerate(elf_max):
                if elf_max[i] < curr_sum:
                    place_holder = elf_max[i]
                    elf_max[i] = curr_sum
                    curr_sum = place_holder
            curr_sum = 0

for i, elem in enumerate(elf_max):
    if elf_max[i] < curr_sum:
        place_holder = elf_max[i]
        elf_max[i] = curr_sum
        curr_sum = place_holder
print("MAX ELF: ", end="")
print(elf_max)
print(sum(elf_max))
