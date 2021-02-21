/*
** EPITECH PROJECT, 2020
** navy
** File description:
** whit theo
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"
#include "include/navy.h"

int *get_pos(char *buff, int *pos, int z)
{
    pos = malloc(sizeof(int) * 2);
    pos[0] = buff[z] - 65 + 1;
    pos[1] = buff[z + 1] - '0';
    return (pos);
}

int connected(int ac, char **av, int pid)
{
    int *pos;
    int *hit;
    char map[4096 + 1];
    char map2[4096 + 1];

    read_map(map, "mymap.txt");
    read_enemy_map(map2, "ene2.txt");
    my_printf("my positions:\n"), display_map(map);
    my_printf("\nenemy's positions:\n"), display_map(map2), my_printf("\n");
    if (check_boat(map, map2, pid) == 1) return (1);
    pos = get_sigs(pos);
    sig_sender(pos, pid), reverse_tradpos(pos);
    if (check_if_hit() == 1) write_in_map("ene2.txt", 'x', map2, pos);
    else write_in_map("ene2.txt", 'o', map2, pos);
    my_printf("\nwaiting for enemy's attack...\n");
    hit = recup_sig(), reverse_tradpos(hit);
    if (recup_hit(hit, map, pid) == 1) write_in_map("mymap.txt", 'x', map, hit);
    else write_in_map("mymap.txt", 'o', map, hit);
    return (connected(ac, av, pid));
}

int connected2(int ac, char **av, int pid)
{
    int *pos;
    int *hit;
    char map[4096 + 1];
    char map2[4096 + 1];

    read_map(map, "enemymap.txt");
    read_enemy_map(map2, "map2.txt");
    my_printf("\nmy positions:\n"), display_map(map);
    my_printf("\nenemy's positions:\n"), display_map(map2);
    if (check_boat(map, map2, pid) == 1) return (1);
    my_printf("\nwaiting for enemy's attack...\n");
    hit = recup_sig();
    reverse_tradpos(hit);
    if (recup_hit(hit, map, pid) == 1)
        write_in_map("enemymap.txt", 'x', map, hit);
    else write_in_map("enemymap.txt", 'o', map, hit);
    pos = get_sigs(pos), sig_sender(pos, pid), reverse_tradpos(pos);
    if (check_if_hit() == 1) write_in_map("map2.txt", 'x', map2, pos);
    else write_in_map("map2.txt", 'o', map2, pos);
    return (connected2(ac, av, pid));
}