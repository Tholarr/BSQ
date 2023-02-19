/*
** EPITECH PROJECT, 2023
** B-CPE-110-NAN-1-1-BSQ-thomas.cluseau
** File description:
** main
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/struct.h"
#include "include/my.h"

char *remove_first_line(char *buffer)
{
    while (*buffer != '\n')
        buffer = buffer + 1;
    buffer = buffer + 1;
    return buffer;
}

void start_classic(char *filepath)
{
    struct stat sb;
    char *buffer;
    char **tab;
    int	cols = 0;

    stat(filepath, &sb);
    buffer = malloc(sizeof(char *) * sb.st_size);
    read(open(filepath, O_RDONLY), buffer, sb.st_size);
    cols = get_cols(buffer);
    buffer = remove_first_line(buffer);
    bsq(buffer, cols);
}

int main(int ac, char **av)
{
    int cmp = 0;
    if (ac != 2)
        return 84;
    for (int i = 0; av[1][i]; i++) {
        if (av[1][i] != '.' && av[1][i] != 'o')
            cmp++;
    }
    if (cmp == 0)
        my_putstr("map generation...\n");
    else
        start_classic(av[1]);
    return 0;
}
