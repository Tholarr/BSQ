/*
** EPITECH PROJECT, 2023
** B-CPE-110-NAN-1-1-BSQ-thomas.cluseau
** File description:
** init
*/
#include <stdlib.h>
#include "include/struct.h"
#include "include/my.h"

int	**init_arr_first_line(char **tab, int **arr)
{
    arr[0] = malloc(sizeof(int *) * my_strlen(tab[0]));
    for (int i = 0; tab[0][i] != '\n'; i++) {
        if (tab[0][i] == 'o')
            arr[0][i] = 0;
        if (tab[0][i] == '.')
            arr[0][i] = 1;
    }
    return arr;
}

struct_t check_first_line(struct_t st, int **arr)
{
    int i = 0;

    for (i; arr[0][i] == 0; i++);
    if (arr[0][i] == 1) {
        st.value = 1;
        st.line = 0;
        st.col = i;
    }
    return st;
}

int	check(int **arr, int y, int x)
{
    int	up;
    int	left;
    int	up_left;

    if (x == 0)
        return 1;
    else {
        up = arr[y - 1][x];
        left = arr[y][x - 1];
        up_left = arr[y - 1][x - 1];
        if (up <= left && up <= up_left)
            return (up + 1);
        if (left <= up && left <= up_left)
            return (left + 1);
        return (up_left + 1);
    }
}

int **attribution(struct_t *st, char **tab, int **arr, int y)
{
    int x = 0;
    for (x; tab[y][x] != '\n'; x++) {
        if (tab[y][x] == '.')
            arr[y][x] = check(arr, y, x);
        if (tab[y][x] == 'o')
            arr[y][x] = 0;
        if (st->value < arr[y][x]) {
            st->value = arr[y][x];
            st->line = y;
            st->col = x;
        }
    }
    return arr;
}

struct_t init_arr(struct_t st, char **tab, int **arr)
{
    st = check_first_line(st, arr);
    for (int y = 1; tab[y]; y++) {
        arr[y] = malloc(sizeof(int *) * my_strlen(tab[y]) + 1);
        arr = attribution(&st, tab, arr, y);
    }
    return st;
}
