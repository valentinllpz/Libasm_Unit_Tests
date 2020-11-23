/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:28:54 by vlugand-          #+#    #+#             */
/*   Updated: 2020/11/20 17:13:26 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	print_diff(int flag)
{
	if (flag == OK)
	{
		printf(GREEN);
		printf("%*s\n\n", 80, "Diff OK :D");
	}
	else
	{
		printf(RED);
		printf("%*s\n\n", 80, "Diff KO :(");
	}
	printf(RESET);
}

void	int_diff_check(int res1, int res2)
{
	if (res1 == res2)
		print_diff(OK);
	else
		print_diff(KO);
}

void	str_diff_check(char *res1, char *res2)
{
	if (strcmp(res1, res2) == 0)
		print_diff(OK);
	else
		print_diff(KO);
}

void	strcmp_diff_check(int res1, int res2)
{
	if (res1 == res2)
		print_diff(OK);
	else if ((res1 < 0 && res2 < 0) || (res1 > 0 && res2 > 0))
	{
		print_diff(OK);
		printf(YELLOW);
		printf("The only thing guaranteed by the original strcmp is to return");
		printf(" an integer greater\nthan, equal to, or less than 0. Note ");
		printf("that when using string literals (instead of\nactual variables");
		printf(") the return value may be automatically replaced with -1, 0 ");
		printf("or 1\nby your compiler. As long as your output and the origin");
		printf("al strcmp share the same\nsign it should not be an issue.\n\n");
		printf(RESET);
	}
	else
		print_diff(KO);
}

void	cmp_files(char *s1, char *s2)
{
	char	ch1;
	char	ch2;
	FILE	*fptr1;
	FILE	*fptr2;

	fptr1 = fopen(s1, "r");
	fptr2 = fopen(s2, "r");
	ch1 = '\0';
	ch2 = '\0';
	while (ch1 != EOF && ch2 != EOF)
	{
		ch1 = getc(fptr1);
		ch2 = getc(fptr2);
		if (ch1 != ch2)
		{
			fclose(fptr1);
			fclose(fptr2);
			print_diff(KO);
			return ;
		}
	}
	fclose(fptr1);
	fclose(fptr2);
	print_diff(OK);
}
