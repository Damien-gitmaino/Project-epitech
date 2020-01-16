/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** Reproduce the behavior of function.
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int u = 0;

    while (str[i] != '\0') {
        while (str[i] == to_find[u] && to_find[u]) {
            i++;
            u++;
        }
        if (to_find[u] == '\0')
            return (str + i - u);
        i -= u;
        u = 0;
        i++;
    }
    return (0);
}
