/*
** EPITECH PROJECT, 2019
** my_str_isprintable
** File description:
** It is printable or not.
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] >= 0 && str[i] <= 32)))
            return (0);
        i++;
    }
    if (i == 0)
        return (1);
    return (1);
}
