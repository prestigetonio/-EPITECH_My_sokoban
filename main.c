/*
** EPITECH PROJECT, 2023
** mai
** File description:
** mai
*/

#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        my_putstr("ERROR");
        my_putchar('\n');
        return 84;
    }
    my_sokoban(argc, argv);
}
