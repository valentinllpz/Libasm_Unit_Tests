/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:45:10 by user42            #+#    #+#             */
/*   Updated: 2021/01/11 18:29:13 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "libasm.h"
# include "get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define OK 1
# define KO 0

void	run_tests(char **av, char *s1, char *s2, char *s3);
void	free_and_set_to_null(char *s);
char	*join_new_line(char *s1, char *s2);
char	*load_long_str(char *path);
int		clean_exit(char *s1, char *s2, char *s3, int ret);
void	print_diff(int flag);
void	int_diff_check(int res1, int res2);
void	str_diff_check(char *res1, char *res2);
void	strcmp_diff_check(int res1, int res2);
void	cmp_files(char *s1, char *s2);
void	test_ft_strlen(char *s1, char *s2);
void	test_ft_strcpy(char *s1, char *s2);
void	test_ft_strcmp_2(char *s1, char *s2, char *s3);
void	test_ft_strcmp(char *s1, char *s2, char *s3);
void	test_ft_strdup(char *s1, char *s2);
void	test_ft_write(char *s);
void	test_ft_write_2(void);
void	test_ft_write_3(void);
void	test_ft_read(void);
void	test_ft_read_2(int fd, int ret1, int ret2, char *buf);
void	test_ft_read_3(int fd, int ret1, int ret2, char *buf);

#endif
