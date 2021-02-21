/*
** EPITECH PROJECT, 2020
** navy
** File description:
** whit theo
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include "include/my.h"
#include "include/navy.h"

int x = 0;

void my_handlernew(int sig)
{
    if (sig == SIGUSR1)
        x++;
    if (sig == SIGUSR2)
        x = -1;
}

int check_if_hit(void)
{
    struct sigaction sa;

    x = 0;
    sa.sa_handler = &my_handlernew;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        if (x == 1) {
            my_printf("hit\n"), x = 0;
            return (1);
        }
        if (x == -1) {
            my_printf("missed\n"), x = 0;
            return (0);
        }
    }
}

int recup_hit(int *hit, char *map, int pid)
{
    int i = 36;

    i = i + (hit[1] - 1) * 18;
    i = i + hit[0] * 2;
    if (map[i] >= '2' && map[i] <= '5') {
        kill(pid, SIGUSR1), usleep(2000), my_printf("hit\n\n");
        return (1);
    }
    else
        kill(pid, SIGUSR2), usleep(2000), my_printf("missed\n\n");
    return (0);
}

int *recup_sig(void)
{
    struct sigaction sa;
    int *save = malloc(sizeof(int) * 2);

    x = 0, sa.sa_handler = &my_handlernew, sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL), sigaction(SIGUSR2, &sa, NULL);
    while (1) {
        if (x == -1) {
            x = 0;
            break;
        }
        else save[0] = x, usleep(20000);
    }
    usleep(20000);
    while (1) {
        if (x == -1) {
            x = 0;
            break;}
        else save[1] = x, usleep(20000);
    }
    return (save);
}

int check_boat(char *map, char *map2, int pid)
{
    int a = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'x') a++;
    }
    if (a == 14) {
        my_printf("\nEnemy won\n");
        return (1);
    }
    a = 0;
    for (int z = 0; map2[z] != '\0'; z++) {
        if (map2[z] == 'x') a++;
    }
    if (a == 14) {
        my_printf("\nI won\n");
        return (1);
    }
    return (0);
}