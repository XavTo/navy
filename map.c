/*
** EPITECH PROJECT, 2020
** navy
** File description:
** display map
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include "include/navy.h"

int *create_pos(int *pos, char **av)
{
    pos = malloc(sizeof(int *) * 2);
    pos[0] = av[2][0] - 65 + 1;
    pos[1] = av[2][1] - '0';
    return (pos);
}

char *read_map(char *buff, char *fl)
{
    int fd;
    int ret = 0;

    fd = open(fl, O_RDWR);
    ret = read(fd, buff, 4096), buff[ret] = '\0';
    return (buff);
}

char *read_enemy_map(char *buff, char *fl)
{
    int fd;
    int ret = 0;

    fd = open(fl, O_RDWR);
    ret = read(fd, buff, 4096), buff[ret] = '\0';
    close (fd);
    return (buff);
}

int display_map(char *map)
{
    my_printf("%s\n", map);
    return (0);
}

void clear_map(void)
{
    int f = 0;
    char map[4096 + 1];
    int tmp = 0;

    f = open("clearmap.txt", O_RDWR);
    tmp = read(f, map, 4096), map[tmp] = '\0', close (f);
    f = open("mymap.txt", O_WRONLY);
    write(f, map, my_strlen(map));
    close (f);
    f = open("enemymap.txt", O_WRONLY);
    write(f, map, my_strlen(map));
    close (f);
    f = open("ene2.txt", O_WRONLY);
    write(f, map, my_strlen(map));
    close (f);
    f = open("map2.txt", O_WRONLY);
    write(f, map, my_strlen(map)), close (f);
}