/*
** EPITECH PROJECT, 2023
** strdup
** File description:
** emacs strdup
*/

#include "stdlib.h"
#include "sokoban.h"

char *my_strdup(char *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
