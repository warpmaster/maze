NAME = race04

SRCS = src/mx_maze.c \
			src/mx_atoi.c \
			src/mx_isdigit.c \
			src/mx_isspace.c \
			src/mx_printint.c \
			src/mx_printchar.c \
			src/mx_strcmp.c \
			src/mx_printstr.c \
			src/mx_strlen.c \
			src/mx_strcpy.c \
			src/mx_strncpy.c \
			src/mx_printerr.c \
			src/mx_strnew.c \
			src/mx_readline.c \
			src/mx_count_words.c \
			src/mx_strsplit.c \
			src/mx_maze_initializer.c \
			src/mx_print_maze.c \
			src/mx_get_min_dist.c \
			src/mx_sort_distances.c \
			src/mx_dist_calc.c \
			src/mx_pathmarker.c \
			src/mx_reset_visited.c \
			src/mx_error_check.c \
			src/mx_print_to_file.c \
			src/mx_get_max_dist.c \
			src/mx_get_dist_exit.c \

INC = inc/minilibmx.h

SRCBIN = mx_maze.c \
			mx_atoi.c \
			mx_isdigit.c \
			mx_isspace.c \
			mx_printint.c \
			mx_printchar.c \
			mx_strcmp.c \
			mx_printstr.c \
			mx_strlen.c \
			mx_strcpy.c \
			mx_strncpy.c \
			mx_printerr.c \
			mx_strnew.c \
			mx_readline.c \
			mx_count_words.c \
			mx_strsplit.c \
			mx_maze_initializer.c \
			mx_print_maze.c \
			mx_get_min_dist.c \
			mx_sort_distances.c \
			mx_dist_calc.c \
			mx_pathmarker.c \
			mx_reset_visited.c \
			mx_error_check.c \
			mx_print_to_file.c \
			mx_get_max_dist.c \
			mx_get_dist_exit.c \

HEADBIN = minilibmx.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install uninstall
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) $(SRCBIN)
clean: uninstall
	@rm -rf $(NAME)
uninstall:
	@rm -rf $(HEADBIN)
	@rm -rf $(SRCBIN)
reinstall: clean all