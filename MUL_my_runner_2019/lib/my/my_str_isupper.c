/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** return 1 for uppercase alphabetic
*/

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] >= 'A' && str[i] <= 'Z')))
            return (0);
        i++;
    }
    if (i == 0)
        return (1);
    return (1);
}