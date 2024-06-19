/*
** EPITECH PROJECT, 2023
** my_strlen_soko.c
** File description:
** strlen_soko
*/

#include "../../include/sokoban.h"

int my_strlen_soko(char *str)
{
    int i = 0;

    while (str[i] != '\n') {
        i++;
    }
    return i;
}
