/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void siginthandler(int sig_num)
{
    (void)sig_num;
    signal(SIGINT, siginthandler);
    my_putstr("\n$>", 0, 0);
}