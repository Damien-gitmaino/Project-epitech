/*
** EPITECH PROJECT, 2019
** my_is_prime
** File description:
** return one for first number or return 0
*/

int my_is_prime(int nb)
{
    int ens_number;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (0);
    for (ens_number = 2; ens_number < nb; ens_number++) {
        if (nb % ens_number == 0)
            return (0);
    }
    return (1);
}
