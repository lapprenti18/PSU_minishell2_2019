/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my.h"

char *test(char *str, char opt)
{
    int lenght = my_strlen(str) - 1;
    char *result;

    for (; lenght > 0; lenght -= 1) {
        if (str[lenght] == opt && str[lenght - 1] == opt)
            break;
    }
    result = malloc(sizeof(char) * lenght + 1);
    for (int temp = 0; temp < lenght; temp += 1)
        result[temp] = str[temp];
    result[lenght - 1] = '\0';
    return (result);
}

char *parse_left(char *str, int size_str, char opt)
{
    char *left = malloc(sizeof(char) * (size_str + 2));
    int temp = 0;

    for (; str[temp] != opt; temp += 1) {
        if (str[temp] != ' ' && str[temp] != '\n')
            break;
    }
    if (str[temp] == opt) {
        return (NULL);
    }
    left[size_str + 1] = '\0';
    left[size_str] = '\n';
    for (int size = 0; size < size_str ; size += 1)
        left[size] = str[size];
    return (left);
}

char *parse_right(char *str, int size_str, int size_tot)
{
    char *left = malloc(sizeof(char) * (size_tot + 2));

    left[size_tot + 1] = '\0';
    for (int temp = 0; str[size_str]; size_str += 1) {
        left[temp] = str[size_str];
        temp += 1;
    }
    if (left[size_tot - 1] == '\n')
        left[size_tot] = '\0';
    else
        left[size_tot] = '\n';
    return (left);
}