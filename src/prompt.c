/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void display_prompt(void)
{
    if (isatty(0))
        my_putstr("$>", 1, 0);
}
