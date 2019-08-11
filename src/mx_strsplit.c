#include "minilibmx.h"

char **mx_strsplit(char const *s, char c) {
    int words = mx_count_words(s, c);
    int start_pos[words];
    int lens[words];

    if (words == 0) return NULL;
    char prev_char = s[0];
    int start_index = 0;
    int current_len = 0;


    if (prev_char != c && prev_char != '\0') {
        start_pos[start_index] = 0;
        start_index++;
        current_len++;
    }

    for (int i = 1, k = 0; s[i] != '\0'; i++) {
        if (s[i] != c && prev_char == c) {
            start_pos[start_index] = i;
            start_index++;
        }
        if (s[i] != c) {
            current_len++;
        }
        if ((s[i] == c && prev_char != c) || s[i+1] == '\0') {
            lens[k] = current_len;
            k++;
            current_len = 0;
        }
        prev_char = s[i];
    }
    // printf("%d\n", words);
    // printf("%d\n", words);

    char **splitted = (char **)malloc((words + 1)* sizeof(char *));

    for (int i = 0; i < words; i++) {
        splitted[i] = mx_strnew(lens[i]);
        for (int j = start_pos[i], n = 0; n < lens[i]; j++, n++) {
            splitted[i][n] = s[j];
        }
    }
    splitted[words] = NULL;

    return splitted;
}
