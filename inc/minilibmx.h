#ifndef MAZE_H
#define MAZE_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>

#define MAX_DIST 1073741824

enum types {
    obstacle,
    path,
    maze_exit
};

typedef struct s_cell {
    int col;
    int row;
    int dist;
    bool is_visited;
    bool is_route;
    enum types type;

} t_cell;

bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_atoi(const char *str);
int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);
void mx_printerr(const char *s);
int mx_getchar(int fd);
char *mx_strnew(const int size);
char *mx_readline(int fd);
int mx_count_words(const char *s, char c);
char **mx_strsplit(char const *s, char c);
t_cell **mx_maze_initializer(int fd, int cols, int rows);
void mx_print_maze(t_cell **maze, int cols, int rows);
int mx_get_min_dist(t_cell **maze, int cols, int rows, int y1_row, int x1_col);
void mx_sort_distances(int *arr, int size);
void mx_dist_calc(t_cell **maze, int cols, int rows, int y1_row, int x1_col);
int mx_pathmarker(t_cell **maze, int x1_col, int y1_row, int x2_col, int y2_row);
void mx_reset_visited(t_cell **maze, int cols, int rows);
void mx_error_check(int fd, int *lines, int *rows);
int mx_get_max_dist(t_cell **maze, int cols, int rows);
void mx_print_to_file(int dst, t_cell **maze, int cols, int rows, int max_dist, int x1_exit, int y1_exit);
int mx_get_dist_exit(t_cell **maze, int cols, int rows, int x1_col, int y1_row);

#endif
