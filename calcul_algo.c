/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** calcul_algo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib/my/bsq.h"

void print_res(square_t *square, int ** tab, int x, int y);

int my_put_nbr(int nb);

void my_putchar(char c);

void print_spec(int **tab, int col, int length);

int check_lower(int **div, int x, int y)
{
    int c[3] = {div[x][y - 1], div[x - 1][y], div[x - 1][y - 1]};
    for (int i = 0; i < 3; i++) {
        if (c[0] > c[i])
            c[0] = c[i];
    }
    if (div[x][y] == 0)
        return 0;
    return (c[0] + 1);
}

square_t *init_square(void)
{
    square_t *square = malloc(sizeof(square_t) * 1);

    square->x = 0;
    square->y = 0;
    square->w = 0;
    return square;
}

square_t *best_rectangle(square_t *square, int pos, int x, int y)
{
    if (pos > square->w) {
        square->w = pos;
        square->x =  x;
        square->y = y;
    } else if (pos == square->w) {
        int z = 0;
        if (x < square->x) {
            square->x = x;
            square->y = y;
        }
    }
    return (square);
}

void pure_algo(int **divide, int columns, int length)
{
    square_t *square = init_square();
    int x = 0;
    int y = 0;

    if (columns == 1 || length == 1) {
        print_spec(divide, columns, length);
        return;
    }
    for (x = 0; x < length; x++) {
        for (y = 0; y < columns; y++) {
            if (x != 0 && y != 0) {
                divide[x][y] = check_lower(divide, x, y);
                square = best_rectangle(square, divide[x][y], x, y);
            }
        }
    }
    print_res(square, divide, columns, length);
}