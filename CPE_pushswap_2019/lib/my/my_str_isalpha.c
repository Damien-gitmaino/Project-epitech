/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return (0) it is not alphabetic
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')))
            return (0);
        i++;
    }
    if (i == 0)
        return (1);
    return (1);
}