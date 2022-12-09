#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "get_next_line.h"
#include "libft.h"

# define FNAME "test_output.txt"
# define MAP "map.txt"
# define H 0
# define T 1
//# define FNAME "output.txt"

typedef struct s_particle
{
	int		x;
	int		y;
	int		overlap;
}	t_particle;

static size_t	get_tab_len(char *fname)
{
	int		fd;
	size_t	len;
	char	*line;

	fd = open(fname, O_RDONLY);
	if (fd < 3)
		return (0);
	len = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len++;
	}
	close(fd);
	return (len);
}

static void	find_particle(char *line, t_particle p[2])
{
	char	*pos;

	if(p[H].overlap)
		return ;
	pos = strchr(line, 'H');
	if (pos)
	{
		p[H].x = pos - line;
		p[H].overlap = 1;
		p[T].overlap = 2;
		return ;
	}
	else
		p[H].y++;
	pos = strchr(line, 'T');
	if (pos)
	{
		p[T].x = pos - line;
		p[T].overlap = 1;
		p[H].overlap = 2;
	}
	else
		p[T].y++;
}

static char	**load_file(t_particle p[2])
{
	int		fd;
	size_t	len;
	char	*line;
	char	**tab;
	size_t	i;

	fd = open(MAP, O_RDONLY);
	if (fd < 3)
		return (NULL);
	len = get_tab_len(MAP) + 1;
	tab = calloc(sizeof(char *), len);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		line[len - 1] = 0;
		find_particle(line, p);
		tab[i++] = line;
		fprintf(stderr, "LINE: %s\n", line);
	}
	close(fd);
	return (tab);
}

static void	free_tab(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static char	**load_moves(void)
{
	int		fd;
	size_t	len;
	char	*line;
	char	**tab;
	size_t	i;

	fd = open(FNAME, O_RDONLY);
	if (fd < 3)
		return (NULL);
	len = get_tab_len(FNAME) + 1;
	tab = calloc(sizeof(char *), len);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = strlen(line);
		line[len - 1] = 0;
		tab[i++] = line;
		fprintf(stderr, "MOVES: %s\n", line);
	}
	close(fd);
	return (tab);
}

static void	horizontal_movement(char **map, t_particle p[2], int dir, int i)
{
	int	x;
	int	y;

	while (dir)
	{
		p[0].x -= i;
		y =  p[0].y;
		x =  p[0].x;

		dir--;
		if (dir > 0)
			map[y][x] = '#';
	}
}

static void	vertical_movement(char **map, t_particle p[2], int dir, int i)
{
	int	x;
	int	y;

	while (dir)
	{
		p[0].y -= i;
		y =  p[0].y;
		x =  p[0].x;

		dir--;
		if (dir > 0)
			map[y][x] = '#';
	}
}

static void	print_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		fprintf(stderr, "%s\n", map[i]);
}

static void	charge_moves(char **map, char **moves, t_particle p[2])
{
	size_t	i;
	char	dir;
	char	**tab;

	i = -1;
	while (moves[++i])
	{
		fprintf(stderr, "MOVE: %s\n", moves[i]);
		tab = ft_split(moves[i], ' ');
		dir = tab[0][0];
		if (dir == 'R' || dir == 'L')
		{
			if (dir == 'R')
				horizontal_movement(map, p, atoi(tab[1]), -1);
			else
				horizontal_movement(map, p, atoi(tab[1]), 1);
		}
		else 
		{
			if (dir == 'D')
				vertical_movement(map, p, atoi(tab[1]), -1);
			else
				vertical_movement(map, p, atoi(tab[1]), 1);
		}
		free_tab(tab);
		print_map(map);
	}
}

int main()
{
	char	**map;
	char	**moves;
	t_particle	p[2];

	memset(p, 0, sizeof(t_particle) * 2);
	map = load_file(p);
	moves = load_moves();
	charge_moves(map, moves, p);
	//fprintf(stderr, "P0\n");
	//fprintf(stderr, "X: %d\n", p[0].x);
	//fprintf(stderr, "Y: %d\n", p[0].y);
	//fprintf(stderr, "OVERLAP: %d\n", p[0].overlap);
	//fprintf(stderr, "P1\n");
	//fprintf(stderr, "X: %d\n", p[1].x);
	//fprintf(stderr, "Y: %d\n", p[1].y);
	//fprintf(stderr, "OVERLAP: %d\n", p[1].overlap);
	free_tab(map);
	free_tab(moves);
	return (0);
}
