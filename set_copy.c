/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** columns and rows
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib/my/my.h"
#include "lib/my/bsq.h"

int int_length(int nb);

int my_getnbr(char const *str);

int my_put_nbr(int nb);

int **replace_0_1(int **divide, char *tab);

int **pure_algo(int **divide, int columns, int length);

int get_number_first_line(char const *filepath)
{
    int i = 0;
    struct stat off_t;
    stat(filepath, &off_t);
    int weight = off_t.st_size + 2;
    char *tab = malloc(sizeof(char) * weight + 1);
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * weight + 1);
    int res = read(fd, buffer, 10);

    if (res == -1)
        return 84;
    if (fd < 0)
        return 84;
    for (i = 0; buffer[i] != '\n'; i++)
        tab[i] = buffer[i];
    res = my_getnbr(tab);
    free(buffer);
    free(tab);
    close(fd);
    return res;
}

int get_width(char *tab)
{
    int i = 0;
    int nb = 0;

    for (i; tab[i] != '\n'; i++);
    i++;
    for (i; tab[i] != '\n'; i++)
        nb++;
    return (nb);
}

int my_fill_buffer(char const *filepath)
{
    struct stat off_t;
    stat(filepath, &off_t);
    char *buffer = malloc(sizeof(char) * (off_t.st_size + 1));
    int fd = open(filepath, O_RDONLY);
    int res = read(fd, buffer, off_t.st_size);

    if (fd < 0 || res < 1)
        return (84);
    buffer[off_t.st_size] = '\0';
    close(fd);
    if (off_t.st_size == 0)
        return (84);
    if (separate_replace(buffer) == 84)
        return (84);
}

int separate_replace(char *tab)
{
    int columns = get_width(tab);
    int length =  my_getnbr(tab);
    int **divide = malloc(sizeof(int *) * (length + 1));
    int x = 0;
    int y = 0;

    for (int i = 0; i <= length; i++)
        divide[i] = malloc(sizeof(int) * (columns + 1));
    if (error_handling(tab, columns, length) == 84)
        return (84);
    replace_0_1(divide, tab);
    pure_algo(divide, columns, length);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (my_fill_buffer(av[1]) == 84)
            return (84);
    } else {
        return 84;
    }
}