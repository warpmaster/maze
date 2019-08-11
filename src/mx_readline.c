#include "minilibmx.h"

char *mx_readline(int fd) {
    char buf[BUFSIZ];
    char *dst;
    int i = 0;
    int br = 0;

    for (int i = 0; i < BUFSIZ; i++)
        buf[i] = '\0';
    i = 0;
    br = read(fd, &buf[i], 1);
    while (br > 0 && buf[i] != '\n') {
        i++;
        br = read(fd, &buf[i], 1);
    }
    dst = mx_strnew(i);

    return mx_strncpy(dst, buf, i);
}
