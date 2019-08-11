#include "minilibmx.h"

void mx_print_maze(t_cell **maze, int cols, int rows) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            //mx_printint(maze[row][col].type);
            // if (maze[row][col].type == obstacle) {
            //     mx_printstr("#");
            // } else {
            //     mx_printint(maze[row][col].dist);
            // }
            // mx_printchar('\t'); // <- delete
            mx_printint(maze[row][col].is_route == true ? 1 : 0);
        }
        mx_printchar('\n');
    }
}
