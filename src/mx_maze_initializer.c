#include "minilibmx.h"

t_cell **mx_maze_initializer(int fd, int cols, int rows) {
    lseek(fd, 0, SEEK_SET);

    char *new_line = mx_readline(fd);
    int line_len = mx_strlen(new_line);

    t_cell **maze = (t_cell **)malloc(rows * sizeof(t_cell *));
    for (int i = 0; i < rows; i++) {
        maze[i] = (t_cell *)malloc(cols * sizeof(t_cell));
    }

    for (int row = 0; line_len > 0; new_line = mx_readline(fd), line_len = mx_strlen(new_line), row++) {

        char **splitted_line = mx_strsplit(new_line, ',');

        for (int col = 0; splitted_line[col] != NULL; col++) {
            maze[row][col].col = col;
            maze[row][col].row = row;
            maze[row][col].dist = MAX_DIST;
            maze[row][col].is_visited = false;
            maze[row][col].is_route = false;
            if (mx_strcmp(splitted_line[col], "#") == 0) {
                maze[row][col].type = obstacle;
            } else if (col == 0 || col == cols - 1 || row == 0 || row == rows - 1) {
                 maze[row][col].type = maze_exit;
            } else {
                maze[row][col].type = path;
            }
            free(splitted_line[col]);
        }
        free(new_line);
        free(splitted_line);
    }
    free(new_line);

    return maze;
}
