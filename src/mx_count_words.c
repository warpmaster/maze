#include "minilibmx.h"

int mx_count_words(const char *s, char c) {
    char cur = 0;
    char prev = 0;
    int len = mx_strlen(s);
    int words = 0;

    if (len == 0) return 0;
    prev = s[0];
    if (prev != c) {
        words++;
    }
    for (int i = 1; (cur = s[i]) != '\0'; i++) {
        if (cur != c && prev == c) {
            words++;
        }
        prev = cur;
    }
    return words;
}
