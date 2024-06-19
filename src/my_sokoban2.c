/*
** EPITECH PROJECT, 2023
** sokoban2
** File description:
** fonction 2 sokoban
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <curses.h>
#include "sokoban.h"

void key_pos(Mov *mov)
{
    switch (mov->key) {
        case KEY_UP:
            mov->dx = 0;
            mov->dy = -1;
            break;
        case KEY_DOWN:
            mov->dx = 0;
            mov->dy = 1;
            break;
        case KEY_LEFT:
            mov->dx = -1;
            mov->dy = 0;
            break;
        case KEY_RIGHT:
            mov->dx = 1;
            mov->dy = 0;
            break;
    }
}

static void update_map(Mov *mov)
{
    if (mov->map[mov->newposy][mov->newposx] == CASE) {
        mov->map[mov->box_newposy][mov->box_newposx] = CASE;
    }
    mov->map[mov->player_y][mov->player_x] = EMPTY;
    mov->player_x = mov->newposx;
    mov->player_y = mov->newposy;
    mov->map[mov->newposy][mov->newposx] = PLAYER;
}

static void move_position(Mov *mov)
{
    int new_x = mov->player_x + mov->dx;
    int new_y = mov->player_y + mov->dy;
    char nextcell;

    if (new_x >= 0 && new_x < mov->cols && new_y >= 0 && new_y < mov->rows) {
        nextcell = mov->map[new_y][new_x];
        move_position_two(mov, new_x, new_y, nextcell);
    }
}

int move_position_three(Mov *mov, int new_x, int new_y)
{
    int box_new_x = new_x + mov->dx;
    int box_new_y = new_y + mov->dy;
    char box_next_cell;

    if (box_new_x >= 0 && box_new_x < mov->cols &&
        box_new_y >= 0 && box_new_y < mov->rows) {
        box_next_cell = mov->map[box_new_y][box_new_x];
        if (box_next_cell != WALL && box_next_cell != CASE) {
            mov->box_newposx = box_new_x;
            mov->box_newposy = box_new_y;
            update_map(mov);
        }
    }
    return 0;
}

int move_position_two(Mov *mov, int new_x, int new_y, char nextcell)
{
    if (nextcell != WALL) {
        mov->newposx = new_x;
        mov->newposy = new_y;
        if (nextcell == CASE) {
            move_position_three(mov, new_x, new_y);
        } else {
            update_map(mov);
        }
    }
    return 0;
}

static void move_player(Mov *mov)
{
    move_position(mov);
}

int choice_key(Mov *mov)
{
    mov->key = getch();
    key_pos(mov);
    move_player(mov);
    return 0;
}

int check_clean(Mov *mov)
{
    for (int i = 0; i < mov->rows; i++) {
        free(mov->map[i]);
    }
    free(mov->map);
    return 0;
}
