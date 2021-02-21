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

void place_boat2(char *buff, int z, char *map, int tmp)
{
    int f = 0;
    int i = 36;
    int *pos;
    int nb = 2;

    z = z + 3;
    if (z > 10) nb = 3;
    if (z > 20) nb = 4;
    if (z > 28) nb = 5;
    f = open("enemymap.txt", O_RDWR), pos = get_pos(buff, pos, z);
    i = i + (pos[1] - 1) * 18, i = i + pos[0] * 2;
    if (tmp - i > -17) {
        while (tmp < i)
            tmp = tmp + 2, map[tmp] = nb + '0';
    }
    else {
        while (tmp < i)
            tmp = tmp + 18, map[tmp] = nb + '0';
    }
    write(f, map, my_strlen(map)), close (f);
}

void create_map2(char *fp, char *whomp)
{
    int f = 0;
    char buf[4096 + 1];
    char map[4096 + 1];
    char *flm = whomp;
    int tmp = 0;
    int z = 2;
    int nb = 2;
    int i = 36;
    int *pos;

    f = open(flm, O_RDWR), tmp = read(f, map, 4096), map[tmp] = '\0', close (f);
    f = open(fp, O_RDWR), tmp = read(f, buf, 4096), buf[tmp] = '\0', close (f);
    while (z < 40) {
        f = open(flm, O_RDWR), pos = get_pos(buf, pos, z);
        i = i + (pos[1] - 1) * 18;
        i = i + pos[0] * 2, map[i] = nb + '0', tmp = i;
        write(f, map, my_strlen(map)), close (f);
        place_boat2(buf, z, map, tmp), i = 36, z = z + 8, nb++, tmp = 0;
        if (z > 32) break;
    }
}

void place_boat(char *buff, int z, char *map, int tmp)
{
    int f = 0;
    int i = 36;
    int *pos;
    int nb = 2;

    z = z + 3;
    if (z > 10) nb = 3;
    if (z > 20) nb = 4;
    if (z > 28) nb = 5;
    f = open("mymap.txt", O_RDWR), pos = get_pos(buff, pos, z);
    i = i + (pos[1] - 1) * 18, i = i + pos[0] * 2;
    if (tmp - i > -17) {
        while (tmp < i)
            tmp = tmp + 2, map[tmp] = nb + '0';
    }
    else {
        while (tmp < i)
            tmp = tmp + 18, map[tmp] = nb + '0';
    }
    write(f, map, my_strlen(map)), close (f);
}

void create_map(char *fp, char *whomp)
{
    int f = 0;
    char buf[4096 + 1];
    char map[4096 + 1];
    char *flm = whomp;
    int tmp = 0;
    int z = 2;
    int nb = 2;
    int i = 36;
    int *pos;

    f = open(flm, O_RDWR), tmp = read(f, map, 4096), map[tmp] = '\0', close (f);
    f = open(fp, O_RDWR), tmp = read(f, buf, 4096), buf[tmp] = '\0', close (f);
    while (z < 40) {
        f = open(flm, O_RDWR), pos = get_pos(buf, pos, z);
        i = i + (pos[1] - 1) * 18;
        i = i + pos[0] * 2, map[i] = nb + '0', tmp = i;
        write(f, map, my_strlen(map)), close (f);
        place_boat(buf, z, map, tmp), i = 36, z = z + 8, nb++, tmp = 0;
        if (z > 32) break;
    }
}

int write_in_map(char *filepath, char val, char *map, int *pos)
{
    int fd;
    int i = 36;

    fd = open(filepath, O_RDWR);
    if (fd == -1)
        return (84);
    i = i + (pos[1] - 1) * 18;
    i = i + pos[0] * 2;
    map[i] = val;
    write(fd, map, my_strlen(map));
    close(fd);
}