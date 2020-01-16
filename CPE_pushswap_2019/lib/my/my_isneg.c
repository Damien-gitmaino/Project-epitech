/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** either N if the integer passed as parameter is negative.
*/

void my_putchar(char number);

int my_isneg(int n)
{
    if (n < 0)
    {
        my_putchar('N');
    }
    else if (n >= 0)
    {
        my_putchar('P');
    }
    return (0);
}
