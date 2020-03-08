/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** print_res
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/my/bsq.h"

void my_putchar(char c);

void print_spec(int **tab, int col, int length);

void columns(int **tab, int col, int len);

void lines(int **tab, int col, int len);

char check_square(square_t *square, int a, int z, int act)
{
    if (act == 0)
        return ('o');
    if (a >= (square->x - square->w) + 1 && a <= square->x &&
    z >= (square->y - square->w) + 1 && z <= square->y)
        return ('x');
    return ('.');
}

void print_res(square_t *square, int **tab, int x, int y)
{
    int a = 0;
    int z = 0;
    int i = 0;
    int weight = (x + 1) * (y + 1);
    char *buf = malloc(sizeof(char) * weight);
    int res = 0;
    for (a = 0; a < y; a++) {
        for (z = 0; z < x; z++) {
            buf[i] = check_square(square, a, z, tab[a][z]);
            i++;
        }
        buf[i] = '\n';
        i++;
    }
    buf[i] = '\0';
    write(1, buf, i);
    for (int t = 0; t <= y; t++)
        free(tab[t]);
    free(tab);
    free(buf);
}

void print_spec(int **tab, int col, int len)
{
    if (col == 1 && len == 1) {
        if (tab[0][0] == 1) {
            my_putchar('x');
        } else {
            my_putchar('o');
        }
        my_putchar('\n');
    } else {
        columns(tab, col, len);
    }
}

void columns(int **tab, int col, int len)
{
    int count = 0;

    if (col == 1) {
        for (int i = 0; i < len; i++) {
            if (tab[i][0] > 0 && count < 1) {
                my_putchar('x');
                count++;
            } else if (tab[i][0] > 0 && count == 1) {
                my_putchar('.');
            } else {
                my_putchar('o');
            }
            my_putchar('\n');
        }
    } else {
        lines(tab, col, len);
    }
}

void lines(int **tab, int col, int len)
{
    int count = 0;

    for (int i = 0; i < col; i++) {
        if (tab[0][i] > 0 && count < 1) {
            my_putchar('x');
            count++;
        } else if (tab[0][i] > 0 && count == 1) {
            my_putchar('.');
        } else {
            my_putchar('o');
        }
    }
    my_putchar('\n');
}