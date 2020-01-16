/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** Compare the string with n how paramenter.
*/

int my_strncmp(char  const *s1, char const *s2, int n)
{
    char i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && i < n) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
}
