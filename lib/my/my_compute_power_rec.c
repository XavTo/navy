/*
** EPITECH PROJECT, 2020
** my_compute_rec
** File description:
** recursive puissance
*/

int my_compute_power_rec(int nb, int power)
{
    if (power == 0) {
        return (1);
    }
    if (power < 0) {
        return (0);
    }
    if (power != 1) {
        return (nb * my_compute_power_rec(nb , power - 1));
    }
}
