/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_putnbr_base
*/

char *my_revstr(char *str);

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *str)
{
    int str_len = 0;
    while (str[str_len])
        str_len++;
    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr == 0)
        return (0);
    else
        my_putnbr_base(nbr / str_len, str);
    my_putchar(str[nbr % str_len]);
    return (0);
}