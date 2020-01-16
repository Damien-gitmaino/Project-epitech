/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compares  the two strings s1 and s2.
*/

int my_strcmp(char  const *s1, char const *s2)
{
    char i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
}