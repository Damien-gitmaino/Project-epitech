/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** That puts every letter of every word in it in uppercase.
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    int u = 32;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + u;
        i++;
    }
    return (str);
}
