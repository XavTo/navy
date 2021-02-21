/*
** EPITECH PROJECT, 2020
** navy
** File description:
** whit theo
*/

#ifndef NAVY_H
#define NAVY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

int check_boat(char *map, char *map2, int pid);
int display_empty_map(void);
void place_boat2(char *buff, int z, char *map, int tmp);
void place_boat(char *buff, int z, char *map, int tmp);
void create_map2(char *fp, char *whomp);
void create_map(char *fp, char *whomp);
char *read_map(char *buff, char *fl);
int *create_pos(int *pos, char **av);
char *read_enemy_map(char *buff, char *fl);
int display_map(char *map);
void my_handler(int sig, siginfo_t *info, void *context);
void my_handler2(int sig, siginfo_t *info, void *context);
int connected(int ac, char **av, int pid);
int connected2(int ac, char **av, int pid);
char *my_itoa(int nb);
int *get_pos(char *buff, int *pos, int z);
int *trad_pos(char *pos, int *sigtosend);
int *get_sigs(int *sigtosend);
char *reverse_tradpos(int *sigtosend);
void sig_sender(int *sigtosend, int pid);
int check_if_hit(void);
int recup_hit(int *hit, char *map, int pid);
int *recup_sig(void);
int write_in_map(char *filepath, char val, char *map, int *pos);
void clear_map(void);

#endif