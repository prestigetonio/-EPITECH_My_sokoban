/*
** EPITECH PROJECT, 2023
** my_putstr.c
** File description:
** emacs
*/

#include "sokoban.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
    return 0;
}
