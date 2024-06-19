/*
** EPITECH PROJECT, 2023
** MySokoban
** File description:
** Project Sokoban
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <curses.h>
#include <stdbool.h>
#include "sokoban.h"

int check_win(Mov *mov)
{
    for (int i = 0; i < mov->rows; i++) {
        for (int j = 0; j < mov->cols; j++) {
            if (mov->map[i][j] == TARGET) {
                return 0;
            }
        }
    }
    return 1;
}

static int check(int cols, int i)
{
    if (cols == 0) {
        cols = i;
    }
    return cols;
}

static void check_sup(Mov *mov)
{
    int rows = 0;
    int cols = 0;

    for (int i = 0; mov->buffer[i] != '\0'; i++) {
        if (mov->buffer[i] == '\n') {
            rows++;
            cols = check(cols, i);
        }
    }
    mov->cols = cols;
    mov->rows = rows;
}

static void check_two(Mov *mov, int j, int i, int k)
{
    if (mov->buffer[k] == PLAYER) {
        mov->player_x = j;
        mov->player_y = i;
    }
}

void display_game(char **map, int rows, int cols)
{
    clear();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mvprintw(i, j, "%c", map[i][j]);
        }
    }
    refresh();
}

static void move_box(Mov *mov, int newposx, int newposy)
{
    int newboxposx = newposx + mov->dx;
    int newboxposy = newposy + mov->dy;
    char nextboxcell = mov->map[newboxposy][newboxposx];

    if (newboxposx >= 0 && newboxposx < mov->cols &&
        newboxposy >= 0 && newboxposy < mov->rows) {
        if (nextboxcell == EMPTY || nextboxcell == TARGET) {
            mov->map[mov->player_y][mov->player_x] = EMPTY;
            mov->map[newposy][newposx] = PLAYER;
            mov->map[newboxposy][newboxposx] = CASE;
            mov->player_x = newposx;
            mov->player_y = newposy;
        }
    }
}

void check_three(Mov *mov)
{
    if (mov->nextcell == CASE) {
        move_box(mov, mov->newposx, mov->newposy);
    } else {
        mov->map[mov->player_y][mov->player_x] = mov->targetstate;
        mov->map[mov->newposy][mov->newposx] = PLAYER;
        mov->player_x = mov->newposx;
        mov->player_y = mov->newposy;
    }
}

int init_soko(Mov *mov)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    while (1) {
        display_game(mov->map, mov->rows, mov->cols);
        choice_key(mov);
        if (check_win(mov)) {
            endwin();
            my_printf("WIN\n");
            exit(0);
        }
        refresh();
    }
    endwin();
    check_clean(mov);
    exit(0);
}

static void init_sokotwo(Mov *mov)
{
    int k = 0;

    mov->map = malloc(sizeof(char *) * (mov->rows + 1));
    for (int i = 0; i < mov->rows; i++) {
        mov->map[i] = malloc(sizeof(char) * mov->cols + 1);
        for (int j = 0; j < mov->cols; j++) {
            mov->map[i][j] = mov->buffer[k];
            check_two(mov, j, i, k);
            k++;
        }
        k++;
    }
    free(mov->buffer);
    init_soko(mov);
}

int my_sokoban(int argc, char *argv[])
{
    Mov *mov = malloc(sizeof(Mov));
    struct stat sfile;
    int fd = open(argv[1], O_RDONLY);

    stat(argv[1], &sfile);
    mov->buffer = malloc(sizeof(char) * (sfile.st_size + 1));
    for (int i = 0; i < (sfile.st_size + 1); i++) {
        mov->buffer[i] = '\0';
    }
    read(fd, mov->buffer, sfile.st_size);
    close(fd);
    check_sup(mov);
    init_sokotwo(mov);
    return 0;
}
