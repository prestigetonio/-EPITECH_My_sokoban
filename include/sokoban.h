/*
** EPITECH PROJECT, 2023
** my.sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H
    #define WALL '#'
    #define EMPTY ' '
    #define PLAYER 'P'
    #define TARGET 'O'
    #define CASE 'X'

typedef struct {
    char **map;
    int line;
    int cols;
} Game;

typedef struct mov {
    char **map;
    int rows;
    int cols;
    int player_x;
    int player_y;
    int dx;
    int dy;
    int key;
    char *buffer;
    int newboxposx;
    int newboxposy;
    int newposx;
    int newposy;
    int box_newposx;
    int box_newposy;
    char nextcell;
    char targetstate;
    int i;
    int j;
} Mov;

int check_win(Mov *mov);
int move_position_two(Mov *mov, int new_x, int new_y, char nextcell);
void check_three(Mov *mov);
void move_player_two(Mov *mov);
void key_pos(Mov *mov);
int my_strlen_soko(char *str);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
int my_sokoban(int argc, char *argv[]);
int check_clean(Mov *mov);
int choice_key(Mov *mov);
int my_putstr(char const *str);
int my_putchar(char c);
int my_put_nbr(int nb);
unsigned int my_put_nbru(unsigned int nb);
#endif
