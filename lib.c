/*
** EPITECH PROJECT, 2023
** B-CPE-110-NAN-1-1-BSQ-thomas.cluseau
** File description:
** lib
*/
#include "include/struct.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i ++;
    }
}

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;
    return count;
}

int get_cols(char *map)
{
    int cols = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] == '\n')
            cols++;
        }
    return cols - 1;
}

int	get_lines(char *buffer, int i)
{
    for (i; buffer[i] != '\n'; i++);
    return i;
}
