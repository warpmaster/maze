#include "minilibmx.h"

int mx_get_max_dist(t_cell **maze, int cols, int rows) {
    int max_dist = 0;
    int filed_size = cols*rows;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (maze[row][col].type != obstacle && maze[row][col].dist < filed_size && maze[row][col].dist > max_dist) {
            	max_dist = maze[row][col].dist;
            }
        }
    }
    return max_dist;
}
