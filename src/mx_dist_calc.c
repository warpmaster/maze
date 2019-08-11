#include "minilibmx.h"

void mx_dist_calc(t_cell **maze, int cols, int rows, int y1_row, int x1_col) {
    int unfilled_cell_found = 1;

    maze[y1_row][x1_col].dist = 0;
    maze[y1_row][x1_col].is_visited = true;

    while (unfilled_cell_found != 0) {
        unfilled_cell_found = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (maze[row][col].type != obstacle && maze[row][col].dist == MAX_DIST) {
                    maze[row][col].dist = mx_get_min_dist(maze, cols, rows, row, col);
                    if (maze[row][col].dist != MAX_DIST) {
                        maze[row][col].is_visited = true;
                        unfilled_cell_found = 1;
                    }
                }
            }
        }
    }
}
