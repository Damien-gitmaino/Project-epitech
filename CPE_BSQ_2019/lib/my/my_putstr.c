/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** write the characters of a string, one by one.
*/

void my_putchar(char letter);

int my_putstr(char const *str)
{
    for (int n = 0; str[n] != '\0'; n++)
        my_putchar(str[n]);
    return (0);
}
