/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** replace
*/

#include <stdlib.h>

int **replace_0_1(int **divide, char *tab)
{
    int x = 0;
    int j = 0;
    int w = 0;

    for (x; tab[x] != '\n'; x++);
    x++;
    for (x; tab[x] != '\0'; x++) {
        if (tab[x] == 'o' || tab[x] == '.') {
            if (tab[x] == 'o')
                divide[w][j] = 0;
            if (tab[x] == '.')
                divide[w][j] = 1;
        } else if (tab[x] == '\n') {
            divide[w][j] = '\0';
            w++;
            j = -1;
        }
        j++;
    }
    free(tab);
}

int columns_error(char *tab, int cols)
{
    int x = 0;
    int j = 0;
    int z = 0;
    int curr = 0;

    for (z; tab[z] != '\n'; z++);
    z++;
    for (x = z; tab[x] != '\0'; x++) {
        if (tab[x] == '\n') {
            if (curr != cols)
                return (84);
            else
                curr = 0;
            x++;
        }
    curr++;
    }
    return (0);
}

int error_handling(char *tab, int cols, int len)
{
    int i = 0;
    int x = 0;

    if (columns_error(tab, cols) == 84)
        return (84);
    for (i; tab[i] != '\0'; i++) {
        if (tab[i] == '\n')
            x++;
    }
    if (x - 1 != len)
        return (84);
    else
        return (0);
}