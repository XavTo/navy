/*
** EPITECH PROJECT, 2020
** attack utils funcs
** File description:
** attack
*/

#include "include/my.h"
#include "include/navy.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int *trad_pos(char *pos, int *sigtosend)
{
    sigtosend = malloc(sizeof(int) * 2);
    if (pos[0] == '\0' || pos == NULL) {
        usleep(10000);
        return (trad_pos(pos, sigtosend));
    }
    if ((pos[0] < 'A' || pos[0] >= 'I') || (pos[1] > '8' || pos[1] <= '0')) {
        write(2, "wrong position\n", 16), usleep(10000);
        return (get_sigs(sigtosend));
    }
    for (int i = 'A' - 1; i != pos[0]; i++)
        sigtosend[0] += 1;
    for (int i = 0; i != pos[1] - 48; i++)
        sigtosend[1] += 1;
    return (sigtosend);
}

int *get_sigs(int *sigtosend)
{
    int valid = 0;
    char *buffer = NULL;
    size_t buffsize = 0;
    while (!valid) {
        my_putstr("attack: ");
        getline(&buffer, &buffsize, stdin);
        sigtosend = trad_pos(buffer, sigtosend);
        valid = 1;
    }
    free(buffer);
    return (sigtosend);
}

void sig_sender(int *sigtosend, int pid)
{
    for (int i = 0; i != sigtosend[0]; i++)
        kill(pid, SIGUSR1), usleep(2000);
    usleep(2000);
    kill(pid, SIGUSR2), usleep(2000);
    for (int a = 0; a != sigtosend[1]; a++)
        kill(pid, SIGUSR1), usleep(2000);
    usleep(2000);
    kill(pid, SIGUSR2);
}

char *reverse_tradpos(int *sigtosend)
{
    char pos[3] = {'@', '0'};
    for (int i = 0; i != sigtosend[0]; i++)
        pos[0] += 1;
    for (int i = 0; i != sigtosend[1]; i++)
        pos[1] += 1;
    my_printf("%s: ", pos);
}