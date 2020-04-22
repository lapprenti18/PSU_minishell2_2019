/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

char *str_cpy(char *str_two)
{
    char *str = malloc(sizeof(char) * (my_strlen(str_two) + 1));

    str[my_strlen(str_two)] = '\0';

    for (int temp = 0; str_two[temp]; temp += 1)
        str[temp] = str_two[temp];
    return (str);
}

char **str_cpy_tab(char **tab)
{
    return (tab);
}