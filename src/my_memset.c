/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_str_to_word_array.c
*/

#include "../my.h"

char *my_memset(char *str, int size)
{
    for (int temp = 0; temp < size; temp += 1) {
        str[temp] = '\0';
    }
    return (str);
}