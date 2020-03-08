/*
** EPITECH PROJECT, 2019
** CPool_Day09_2019
** File description:
** my.h
*/

int my_intlength (int value);

int my_str_to_int(char *str, int threshold);

int is_charac(char c);

int length_getter(char const *str, int th);

int word_counter(char *str);

int treshold_getter(char *str, int w_id);

char **my_str_to_word_array(char const *str);

char *my_strdup(char const *src);

int my_show_word_array(char * const *str);

int my_compute_square_root(int nb);

int my_compute_power_rec(int nb, int p);

int my_is_prime_sup(int n);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_is_prime(int num);

int my_isneg(int n);

int my_put_nbr(int nb);

int my_strlen(char const *str);

void my_putchar(char c);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

int my_putstr_handler(int n, char const *str);

int my_putstr(char const *str);

int my_strncpy_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void check_n_change(int *array, int i, int j);

void my_sort_int_array(int *array, int size);

int my_str_isalpha(char const *s);

int my_str_islower(char const *s);

int my_str_isnum(char const *s);

int my_str_isprintable(char const *s);

int my_str_isupper(char const *s);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

int **replace_0_1(int **replace, char *tab);

int separate_replace(char *tab);

int error_handling(char *tab, int cols, int len);