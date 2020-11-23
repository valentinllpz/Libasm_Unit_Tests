/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:57:42 by vlugand-          #+#    #+#             */
/*   Updated: 2020/11/20 17:04:39 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_ft_strlen(char *s1, char *s2)
{
	int		res1;
	int		res2;

	printf(CYAN);
	printf("==================================");
	printf(" ft_strlen ===================================\n\n");
	printf(RESET);
	printf("Testing your ft_strlen with an empty string:\n\n");
	res1 = ft_strlen(s1);
	res2 = strlen(s1);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	int_diff_check(res1, res2);
	printf("Testing your ft_strlen with a long string:\n");
	res1 = ft_strlen(s2);
	res2 = strlen(s2);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	int_diff_check(res1, res2);
}

void	test_ft_strcpy(char *s1, char *s2)
{
	char	dst[1918];
	char	*res1;
	char	*res2;

	printf(CYAN);
	printf("==================================");
	printf(" ft_strcpy ===================================\n\n");
	printf(RESET);
	printf("Testing your ft_strcpy with an empty string:\n\n");
	res1 = strdup(ft_strcpy(dst, s1));
	res2 = strdup(strcpy(dst, s1));
	printf("Your output : %s\nExpected    : %s\n", res1, res2);
	str_diff_check(res1, res2);
	free_and_set_to_null(res1);
	free_and_set_to_null(res2);
	printf("Testing your ft_strcpy with a long string:\n\n");
	res1 = strdup(ft_strcpy(dst, s2));
	res2 = strdup(strcpy(dst, s2));
	printf("Your output : \n%s\nExpected    : \n%s\n", res1, res2);
	str_diff_check(res1, res2);
	free_and_set_to_null(res1);
	free_and_set_to_null(res2);
}

void	test_ft_strcmp_2(char *s1, char *s2, char *s3)
{
	int			res1;
	int			res2;

	res1 = ft_strcmp(s3, s1);
	res2 = strcmp(s3, s1);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with two identical long strings:\n\n");
	res1 = ft_strcmp(s3, s3);
	res2 = strcmp(s3, s3);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with two different strings:\n\n");
	res1 = ft_strcmp(s3, s2);
	res2 = strcmp(s3, s2);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with string literals:\n\n");
	res1 = ft_strcmp("Yayy", "Nope");
	res2 = strcmp("Yayy", "Nope");
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	strcmp_diff_check(res1, res2);
}

void	test_ft_strcmp(char *s1, char *s2, char *s3)
{
	int			res1;
	int			res2;

	printf(CYAN);
	printf("==================================");
	printf(" ft_strcmp ===================================\n\n");
	printf(RESET);
	printf("Testing your ft_strcmp with 2 empty strings:\n\n");
	res1 = ft_strcmp(s1, s1);
	res2 = strcmp(s1, s1);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with an empty string for the");
	printf(" first argument:\n\n");
	res1 = ft_strcmp(s1, s3);
	res2 = strcmp(s1, s3);
	printf("Your output : %d\nExpected    : %d\n", res1, res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with an empty string for the");
	printf(" second argument:\n\n");
	test_ft_strcmp_2(s1, s2, s3);
}

void	test_ft_strdup(char *s1, char *s2)
{
	char		*res1;
	char		*res2;

	printf(CYAN);
	printf("==================================");
	printf(" ft_strdup ===================================\n\n");
	printf(RESET);
	printf("Testing your ft_strdup with an empty string:\n\n");
	res1 = ft_strdup(s1);
	res2 = strdup(s1);
	printf("Your output : %s\nExpected    : %s\n", res1, res2);
	str_diff_check(res1, res2);
	free_and_set_to_null(res1);
	free_and_set_to_null(res2);
	printf("Testing your ft_strdup with a long string:\n\n");
	res1 = ft_strdup(s2);
	res2 = strdup(s2);
	printf("Your output : \n%s\nExpected    : \n%s\n", res1, res2);
	str_diff_check(res1, res2);
	free_and_set_to_null(res1);
	free_and_set_to_null(res2);
}
