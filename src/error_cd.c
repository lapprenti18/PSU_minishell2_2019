/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void err_cd(char *cmd)
{
    if (errno == 2) {
        my_putstr(cmd, 0, 0);
        my_putstr(": Command not found.", 0, 1);
        return;
    }
    if (errno == 20) {
        my_putstr(cmd, 0, 0);
        my_putstr(": Not a directory.", 0, 1);
        return;
    }
}