/*
** EPITECH PROJECT, 2023
** B-CPE-110-NAN-1-1-BSQ-thomas.cluseau
** File description:
** my
*/
#include "struct.h"

#ifndef MY_H_
    # define MY_H_

int get_cols(char *map);
int	get_lines(char *buffer, int i);
int my_strlen(char const *str);
int my_putstr(char const *str);
void	bsq(char *buffer, int cols);
int	**init_arr_first_line(char **tab, int **arr);
struct_t init_arr(struct_t st, char **tab, int **arr);

#endif /* !MY_H_ */
