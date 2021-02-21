/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** racine carré
*/

int my_compute_square_root(int nb)
{
    int i;
    int a;

    a = 0;
    i = nb;
    if (nb <= 0) {
        return (0);
    }
    if (nb == 1) {
        return (1);
    }
    while (i != a) {
        a = i;
        i = (nb/a + a) / 2;
    }
    if (a * a == nb) {
        return (a);
    }
    return (0);
}
