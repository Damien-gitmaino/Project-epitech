/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** write the characters of a string, one by one.
*/

void my_putchar(char letter);

int my_putstr(char const *str)
{
    int n;

    n = 0;
    while (str[n] != '\0') {
        my_putchar(str[n]);
        n++;
    }
    return (0);
}
