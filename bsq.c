/*
** EPITECH PROJECT, 2023
** B-CPE-110-NAN-1-1-BSQ-thomas.cluseau
** File description:
** bsq
*/
#include <stdlib.h>
#include "include/struct.h"
#include "include/my.h"

char **str_to_tab(char *str, char **tab, int cmp)
{
    int	val = 0;
    int	arr[2] = {0};

    tab = malloc(sizeof(char**) * cmp + 100);
    while (str[arr[0]] != '\0') {
        tab[arr[1]] = malloc(sizeof(char*) * get_lines(str, arr[0]) + 1);
        while (str[arr[0]] != '\n') {
            tab[arr[1]][val] = str[arr[0]];
            val = val + 1;
            arr[0] = arr[0] + 1;
        }
        tab[arr[1]][val] = '\n';
        tab[arr[1]][val + 1] = '\0';
        arr[0] = arr[0] + 1;
        arr[1] = arr[1] + 1;
        val = 0;
    }
    return tab;
}

char **add_biggest_square(char **tab, struct_t st)
{
    int	sqr_line = st.value;
    int	sqr_col = st.value;
    int	y = st.line;
    int	x = st.col;

    for (int sqr_line = st.value; sqr_line != 0; sqr_line--) {
        x = st.col;
        sqr_col = st.value;
        for (sqr_col; sqr_col != 0; sqr_col--) {
            tab[y][x] = 'x';
            x--;
        }
        y--;
    }
    return tab;
}

void bsq(char *buffer, int cols)
{
    char **tab;
    int	**arr;
    struct_t st;

    st.value = 0;
    tab = str_to_tab(buffer, tab, cols);
    arr = malloc(sizeof(int **) * 10000);
    arr = init_arr_first_line(tab, arr);
    st = init_arr(st, tab, arr);
    tab = add_biggest_square(tab, st);
    for (int i = 0; tab[i]; i++)
        my_putstr(tab[i]);
}
