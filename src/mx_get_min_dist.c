#include "minilibmx.h"


int mx_get_min_dist(t_cell **maze, int cols, int rows, int y1_row, int x1_col) {
    int distances[4];
    int i;
    for (i = 0; i < 4; i++) {
        distances[i] = MAX_DIST;
    }
    i = 0;

    if (y1_row == 0) { // north look is forbidden
        // look at east
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col+1].type != obstacle && maze[y1_row][x1_col+1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col+1].dist + 1;
            i++;
        }
        // look at south
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row+1][x1_col].type != obstacle && maze[y1_row+1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row+1][x1_col].dist + 1;
            i++;
        }
        // look at west
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col-1].type != obstacle && maze[y1_row][x1_col-1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col-1].dist + 1;
            i++;
        }
    } else if (y1_row == rows - 1) { // south look is forbidden
        // look at east
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col+1].type != obstacle && maze[y1_row][x1_col+1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col+1].dist + 1;
            i++;
        }
        // look at north
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row-1][x1_col].type != obstacle && maze[y1_row-1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row-1][x1_col].dist + 1;
            i++;
        }
        // look at west
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col-1].type != obstacle && maze[y1_row][x1_col-1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col-1].dist + 1;
            i++;
        }
    } else if (x1_col == 0) { // west look is forbidden
        // look at south
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row+1][x1_col].type != obstacle && maze[y1_row+1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row+1][x1_col].dist + 1;
            i++;
        }
        // look at east
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col+1].type != obstacle && maze[y1_row][x1_col+1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col+1].dist + 1;
            i++;
        }
        // look at north
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row-1][x1_col].type != obstacle && maze[y1_row-1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row-1][x1_col].dist + 1;
            i++;
        }
    } else if (x1_col == cols - 1) { // east look is forbidden
        // look at south
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row+1][x1_col].type != obstacle && maze[y1_row+1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row+1][x1_col].dist + 1;
            i++;
        }
        // look at north
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row-1][x1_col].type != obstacle && maze[y1_row-1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row-1][x1_col].dist + 1;
            i++;
        }
        // look at west
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col-1].type != obstacle && maze[y1_row][x1_col-1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col-1].dist + 1;
            i++;
        }
    } else { // look around
        // look at south
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row+1][x1_col].type != obstacle && maze[y1_row+1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row+1][x1_col].dist + 1;
            i++;
        }
        // look at east
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col+1].type != obstacle && maze[y1_row][x1_col+1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col+1].dist + 1;
            i++;
        }
        // look at north
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row-1][x1_col].type != obstacle && maze[y1_row-1][x1_col].dist != MAX_DIST) {
            distances[i] = maze[y1_row-1][x1_col].dist + 1;
            i++;
        }
        // look at west
        if (maze[y1_row][x1_col].is_visited == false && maze[y1_row][x1_col-1].type != obstacle && maze[y1_row][x1_col-1].dist != MAX_DIST) {
            distances[i] = maze[y1_row][x1_col-1].dist + 1;
            i++;
        }
    }

    mx_sort_distances(distances, 4);
    return distances[0];
}
