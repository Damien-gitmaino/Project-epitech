/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** return 0 if chiffre
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] >= '0' && str[i] <= '9')))
            return (0);
        i++;
    }
    if (i == 0)
        return (1);
    return (1);
}
