/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** Lowcase alphabetic return 1.
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!((str[i] >= 'a' && str[i] <= 'z')))
            return (0);
        i++;
    }
    if (i == 0)
        return (1);
    return (1);
}
