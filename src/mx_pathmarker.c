#include "minilibmx.h"

int mx_pathmarker(t_cell **maze, int x1_col, int y1_row, int x2_col, int y2_row) {
    int south_echo = 0;
    int north_echo = 0;
    int west_echo = 0;
    int east_echo = 0;

    maze[y1_row][x1_col].is_visited = true;

    if (maze[y1_row][x1_col].col == x2_col && maze[y1_row][x1_col].row == y2_row) {
        maze[y1_row][x1_col].is_route = true;
        return 1;
    }
    if (maze[y1_row][x1_col].type == maze_exit ) {
        return 0;
    }
    // go east
    if (maze[y1_row][x1_col+1].type != obstacle && maze[y1_row][x1_col+1].is_visited == false && (maze[y1_row][x1_col+1].dist - maze[y1_row][x1_col].dist) == 1) {
        east_echo = mx_pathmarker(maze, x1_col+1, y1_row, x2_col, y2_row);
    }
    // go south
    if (maze[y1_row+1][x1_col].type != obstacle && maze[y1_row+1][x1_col].is_visited == false && (maze[y1_row+1][x1_col].dist - maze[y1_row][x1_col].dist) == 1) {
        south_echo = mx_pathmarker(maze, x1_col, y1_row+1, x2_col, y2_row);
    }
    // go north
    if (maze[y1_row-1][x1_col].type != obstacle && maze[y1_row-1][x1_col].is_visited == false && (maze[y1_row-1][x1_col].dist - maze[y1_row][x1_col].dist) == 1) {
        north_echo = mx_pathmarker(maze, x1_col, y1_row-1, x2_col, y2_row);
    }
    // go west
    if (maze[y1_row][x1_col-1].type != obstacle && maze[y1_row][x1_col-1].is_visited == false && (maze[y1_row][x1_col-1].dist - maze[y1_row][x1_col].dist) == 1) {
        west_echo = mx_pathmarker(maze, x1_col-1, y1_row, x2_col, y2_row);
    }
    if (south_echo == 1 || east_echo == 1 || north_echo == 1 || west_echo == 1) {
        maze[y1_row][x1_col].is_route = true;
        return 1;
    } else {
        maze[y1_row][x1_col].is_route = false;
        maze[y1_row][x1_col].is_visited = false;
    }
    return 0;
}
