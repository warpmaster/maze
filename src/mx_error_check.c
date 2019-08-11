#include "minilibmx.h"

void mx_error_check(int fd, int *lines, int *cols) {
	*lines = 0;
	*cols = 0;

	char *new_line = mx_readline(fd);
    int line_len = mx_strlen(new_line);
    int prev_len = line_len;

    for (int row = 0; line_len > 0; new_line = mx_readline(fd), line_len = mx_strlen(new_line), row++) {
        *cols = 0;
        if (line_len != prev_len) {
            mx_printerr("map error\n");
            exit(0);
        }
        for (int i = 0; new_line[i] != '\0'; i++) {
            if (new_line[i] != '#' && new_line[i] != '.' && new_line[i] != ',' && new_line[i] != '\n') {
                mx_printerr("map error\n");
                exit(0);
            }
            if (new_line[i] != ',' && new_line[i] != '\n') {
                (*cols)++;
            }
        }
        prev_len = line_len;
        free(new_line);
        (*lines)++;
    }
    free(new_line);

    // lseek(fd, 0, SEEK_SET);
}
