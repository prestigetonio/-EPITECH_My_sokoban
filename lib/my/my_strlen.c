/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** strlen
*/

#include "../../include/sokoban.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
