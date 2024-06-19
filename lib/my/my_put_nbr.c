/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** recurcive
*/

#include "sokoban.h"

int recursive_put_nbr(int nbr)
{
    char c;
    int n;

    if (nbr == 0) {
        return 0;
    }
    n = nbr % 10;
    c = n + 48;
    recursive_put_nbr(nbr / 10);
    my_putchar(c);
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = nb + 2000000000;
        nb = -nb;
    }
    if (nb < 0) {
        nb = -nb;
        my_putchar('-');
    }
    if (nb == 0) {
        my_putchar(48);
    } else {
        return (recursive_put_nbr(nb));
    }
    return 0;
}
