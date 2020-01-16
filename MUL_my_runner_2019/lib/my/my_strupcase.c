/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** That puts every letter of every word in it in uppercase.
*/

char *my_strupcase(char *str)
{
    int i = 0;
    int u = 32;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - u;
        i++;
    }
    return (str);
}