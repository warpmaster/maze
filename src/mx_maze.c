#include "minilibmx.h"

int main(int argc, char *argv[]) {
    int fd = -1;
    int cols = 0;
    int rows = 0;
    int max_dist = 0;
    int dist_exit = 0;
    t_cell **maze = NULL;
    int x1 = 0; // entry point x
    int y1 = 0; // entry point y
    int x2 = 0; // exit point x
    int y2 = 0; // exit point y

    if (argc != 6) {
        mx_printerr("error\n");
        exit(0);
    }
    x1 = mx_atoi(argv[2]);
    y1 = mx_atoi(argv[3]);
    x2 = mx_atoi(argv[4]);
    y2 = mx_atoi(argv[5]);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    mx_error_check(fd, &rows, &cols);

    if (close(fd) < 0) {
        mx_printerr("file error\n");
        exit(0);
    }

    fd = -1;
    fd = open(argv[1], O_RDONLY);
    maze = mx_maze_initializer(fd, cols, rows);
    close(fd);

    if (x1 >= cols || x1 < 0 || y1 >= rows || y1 < 0) {
        mx_printerr("points are out of map range\n");
        exit(0);
    }

    if (x2 >= cols || x2 < 0 || y2 >= rows || y2 < 0) {
        mx_printerr("points are out of map range\n");
        exit(0);
    }

    if (maze[y1][x1].type == obstacle) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }
    if (maze[y2][x2].type == obstacle) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }
    
    mx_dist_calc(maze, cols, rows, y1, x1);

    mx_reset_visited(maze, cols, rows);

    max_dist = mx_get_max_dist(maze, cols, rows);
    mx_printstr("dist=");
    mx_printint(max_dist);
    mx_printchar('\n');
    dist_exit = mx_get_dist_exit(maze, cols, rows, x2, y2);
    mx_printstr("exit=");
    mx_printint(dist_exit);
    mx_printchar('\n');

    mx_pathmarker(maze, x1, y1, x2, y2);
    //mx_print_maze(maze, cols, rows);

    fd = -1;
    fd = open("path.txt", O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);

    mx_print_to_file(fd, maze, cols, rows, max_dist, x2, y2);

    if (close(fd) < 0) {
        mx_printerr(strerror(errno));
        exit(0);
    }

    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}
