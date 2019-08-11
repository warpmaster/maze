#include "minilibmx.h"

int mx_get_dist_exit(t_cell **maze, int cols, int rows, int x1_col, int y1_row) {
    int dist_exit = 0;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (maze[row][col].col == x1_col && maze[row][col].row == y1_row) {
            	dist_exit = maze[row][col].dist;
            }
        }
    }
    return dist_exit;
}
