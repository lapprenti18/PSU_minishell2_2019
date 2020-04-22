/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** ok
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_putchar12(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str, int space, int slash)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar12(str[i]);
        i++;
    }
    if (space == 1)
        write(1, " ", 1);
    if (slash == 1)
        write(1, "\n", 1);
}
