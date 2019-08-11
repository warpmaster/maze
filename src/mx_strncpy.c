#include "minilibmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    for (; src[i] != '\0' && i < len; i++) {
        dst[i] = src[i];
    }
    return &dst[0];
}
