#include "minilibmx.h"

void mx_print_to_file(int dst, t_cell **maze, int cols, int rows, int max_dist, int x1_exit, int y1_exit) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (maze[row][col].type == obstacle) {
                write(dst, "#", 1);
            } else if (maze[row][col].dist == max_dist && maze[row][col].is_route) {
                write(dst, "X", 1);
            } else if (maze[row][col].dist == max_dist) {
                write(dst, "D", 1);
            }  else if (maze[row][col].col == x1_exit && maze[row][col].row == y1_exit) {
                write(dst, "*", 1);
            } else if (maze[row][col].is_route == true) {
                write(dst, "*", 1);
            } else if ((maze[row][col].type == path || maze[row][col].type == maze_exit) && maze[row][col].is_route == false) {
                write(dst, ".", 1);
            }
        }
        write(dst, "\n", 1);
    }
}
