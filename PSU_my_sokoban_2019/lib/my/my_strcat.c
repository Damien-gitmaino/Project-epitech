/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** lib
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int u = 0;

    while (dest[i] != '\0')
        i++;
        while (src[u] != '\0') {
            dest[i] = src[u];
            u++;
            i++;
        }
    dest[i] = '\0';
    return (dest);
}
