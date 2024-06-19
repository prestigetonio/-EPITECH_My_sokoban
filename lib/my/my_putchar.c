/*
** EPITECH PROJECT, 2023
** my_putchar.c
** File description:
** emacs
*/

#include <unistd.h>
#include "sokoban.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}
