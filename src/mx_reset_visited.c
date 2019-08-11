#include "minilibmx.h"

void mx_reset_visited(t_cell **maze, int cols, int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            maze[row][col].is_visited = false;
        }
    }
}
