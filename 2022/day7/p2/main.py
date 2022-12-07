#!/bin/python3

from dataclasses import dataclass

@dataclass
class Dir:
	name : str
	size : int
	dir_list : list
	prev : object

	def new_dir(self, dir_name):
		self.dir_list.append(Dir(dir_name, 0, [], self));

	def incr_size(self, size):
		self.size += size

	def get_name(self):
		return self.name

	def get_dir(self, dir_name):
		for elem in self.dir_list:
			if elem.get_name() == dir_name:
				return elem
		return None

	def get_prev(self):
		return self.prev

	def get_size(self):
		return self.size

	def get_dir_list(self):
		return self.dir_list

def ls(line : str, Dir : object) -> None:
	if (line[0] == "dir"):
		Dir.new_dir(line[1])
	elif line[1] != "ls":
		Dir.incr_size(int(line[0]))

def print_size(path : object):
	for elem in path.get_dir_list():
		print_size(elem)
		size = elem.get_size()
		print(size)

def get_size(path, size):
	for elem in path.get_dir_list():
		get_size(elem, size)
		size += elem.get_size()
	return size

def find_lowest_sum(cap, need, root):
	for elem in root.get_dir_list():
		size = get_size(elem, 0)
		print(size)

def get_root_size(root : object, size):
	for elem in root.get_dir_list():
		size += get_root_size(elem, size)
	print(root.get_size())
	return root.get_size()

def main() -> None:

	root = Dir("/", 0, [], None)
	path = root
	with open("output.txt") as fd:
	#with open("test_output.txt") as fd:
		fd.readline()
		while True:
			line = fd.readline().rstrip("\n").split(" ")
			if len(line) == 1:
				break ;
			if line[1] == "cd":
				if line[2] == "..":
					#size = path.get_size()
					path = path.get_prev()
					#path.incr_size(size)
				else:
					path = path.get_dir(line[2])
			else:
				ls(line, path)
	print(get_root_size(root, 0))
	#print_size(root)
	#find_lowest_sum(70000000, 30000000, root)
	#print(f"ROOT: {root.get_size()}")

if __name__ == "__main__":
	main()

