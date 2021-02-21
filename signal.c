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

extern int x;

void usage(void)
{
    my_printf("USAGE\n      ");
    my_printf("./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n      first_player_pid: ");
    my_printf("only for the 2nd player. pid of the first player.\n      navy");
    my_printf("_positions: file representing the positions of the ships.\n");
}

void my_handler(int sig, siginfo_t *info, void *context)
{
    my_printf("enemy connected\n\n");
    x = info->si_pid;
}

void my_handler2(int sig, siginfo_t *info, void *context)
{
    my_printf("successfully connected\n");
    x++;
}

int my_first(struct sigaction sa, char **av, int ac)
{
    int ret = 0;
    int pid = 0;
    char buff[4096 + 1];

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    sa.sa_sigaction = &my_handler;
    sigaction(SIGUSR1, &sa, NULL);
    while (1)
        if (x != 0) break;
    pid = x;
    x = 0;
    kill(pid, SIGUSR2);
    create_map(av[1], "mymap.txt");
    connected(ac, av, pid);
}

int main(int ac, char **av)
{
    struct sigaction sa;
    int f = 0;
    int pid = 0;
    char *c;

    f = open(av[ac - 1], O_RDWR);
    if (f == -1) return 84;
    close(f), clear_map();
    if (ac == 2) my_first(sa, av, ac);
    else if (ac == 3) {
        my_printf("my_pid: %d\n", getpid());
        sa.sa_sigaction = &my_handler2, sa.sa_flags = SA_RESTART | SA_SIGINFO;
        sigaction(SIGUSR2, &sa, NULL), kill(my_getnbr(av[1]), SIGUSR1);
        while (1)
            if (x != 0) break;
        x = 0, create_map2(av[2], "enemymap.txt");
        connected2(ac, av, my_getnbr(av[1]));
    } return (0);
}