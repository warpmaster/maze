#include "minilibmx.h"

int mx_maze_walker(t_cell **maze, int x1, int y1, int x2, int y2, int steps) {
	int echo_north = 0;
	int echo_east = 0;
	int echo_south = 0;
	int echo_west = 0;

	maze[y1][x1].is_visited = true;
	printf("x1 = %d, y1 = %d, is_visited = %d, step = %d\n", x1, y1, ((maze[y1][x1].is_visited = true) ? 1 : 0), steps);

	if ((x1 == x2 && y1 == y2) || maze[y1][x1].type == maze_exit) {
		mx_printstr("success!  y = ");
		mx_printint(y1);
		mx_printstr("  x = ");
		mx_printint(x1);
		mx_printstr("\n");
		return 1;
	}

	// go north
	if (maze[x1-1][y1].type != obstacle && !(maze[x1-1][y1].is_visited)) {
		mx_printstr("debug1\n");
		echo_north = mx_maze_walker(maze, x1-1, y1, x2, y2, ++steps);
		// if (echo_north == 1)
		// 	maze[y1][x1].is_route = true;
		// return 1;
	}
	// go east
	if (maze[x1][y1+1].type != obstacle && !(maze[x1][y1+1].is_visited)) {
		mx_printstr("debug2\n");
		echo_east = mx_maze_walker(maze, x1, y1+1, x2, y2, ++steps);
		// if (echo_east == 1)
		// 	maze[y1][x1].is_route = true;
		// return 1;
	}
	// go south
	if (maze[x1+1][y1].type != obstacle && !(maze[x1+1][y1].is_visited)) {
		mx_printstr("debug3\n");
		echo_south = mx_maze_walker(maze, x1+1, y1, x2, y2, ++steps);
		// if (echo_south == 1)
		// 	maze[y1][x1].is_route = true;
		// return 1;
	}
	// go west
	if (maze[x1][y1-1].type != obstacle && !(maze[x1][y1-1].is_visited)) {
		mx_printstr("debug4\n");
		echo_west = mx_maze_walker(maze, x1, y1-1, x2, y2, ++steps);
		// if (echo_west == 1)
		// 	maze[y1][x1].is_route = true;
		//  return 1;
	}
	if (echo_north == 1 || echo_east == 1 || echo_south == 1 || echo_west == 1) {
		mx_printstr("debug5\n");
		maze[y1][x1].is_route = true;
		return 1;
	}
	
	mx_printstr("debug6\n");
	return 0;

}
