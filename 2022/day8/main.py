#!/usr/bin/python3

def get_map() -> list:
    #with open("test_output.txt") as fd:
    with open("output.txt") as fd:
        tree_map = []
        view_map = []
        while True:
            line = fd.readline().rstrip("\n")
            if not line:
                break
            tree_map.append(line)
            view_map.append(list('0' * len(line)))
    return tree_map, view_map, len(tree_map[0])

def get_horizontal_sum(tline : list, vmap : list, tlen : int) -> int:
    max_left = -1
    max_right = -1
    for i in range(0, tlen):
        if (int(tline[i]) > max_left):
            max_left = int(tline[i])
            vmap[i] = '1'
        if (int(tline[tlen - i - 1]) > max_right):
            max_right = int(tline[tlen - i - 1])
            vmap[tlen - i - 1] = '1'

def main() -> int:

    tmap, vmap, map_len = get_map()
    for i in range(0, map_len):
        get_horizontal_sum(tmap[i], vmap[i], map_len)

        max_up = -1
        if (vmap[0][i] == '1'):
            max_up = int(tmap[0][i])
        max_down = -1
        if (vmap[map_len - 1][i] == '1'):
            max_down = int(tmap[map_len - 1][i])

        for j in range(0, map_len):
            if int(tmap[j][i]) > max_up:
                max_up = int(tmap[j][i])
                if vmap[j][i] == '0':
                    vmap[j][i] = '1'

            if int(tmap[map_len - j - 1][i]) > max_down:
                max_down = int(tmap[map_len - j - 1][i])
                vmap[map_len - j - 1][i] = '1'
    total = 0
    for row in vmap:
        for char in row:
            if char == '1':
                total += 1
    print(total)
    #print(vmap)
    return 0;

if __name__ == "__main__":
    main()
