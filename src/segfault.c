/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

void segfault(int pid)
{
    int signal = WTERMSIG(pid);

    if (signal == SIGFPE) {
        my_putstr("Floating exception",0 ,0);
        if (__WCOREDUMP(pid))
            my_putstr(" (core dumped)",0 ,0);
        write(1, "\n", 1);
    }
    else if (signal != 0) {
        my_putstr(strsignal(signal),0, 0);
        if (__WCOREDUMP(pid))
            my_putstr(" (core dumped)",0 ,0);
        write(1, "\n", 1);
    }
}