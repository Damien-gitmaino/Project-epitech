/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** write the equal.
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return (nb);
    return (my_find_prime_sup(nb + 1));
}
