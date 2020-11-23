/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:36:27 by vlugand-          #+#    #+#             */
/*   Updated: 2020/11/23 15:39:39 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	run_tests(char **av, char *s1, char *s2, char *s3)
{
	if (av[1][0] == '1')
		test_ft_strlen("", s2);
	else if (av[1][0] == '2')
		test_ft_strcpy("", s1);
	else if (av[1][0] == '3')
		test_ft_strcmp("", s1, s2);
	else if (av[1][0] == '4')
		test_ft_write(s2);
	else if (av[1][0] == '5')
		test_ft_read();
	else if (av[1][0] == '6')
		test_ft_strdup("", s3);
	else
	{
		test_ft_strlen("", s2);
		test_ft_strcpy("", s1);
		test_ft_strcmp("", s1, s2);
		test_ft_write(s2);
		test_ft_read();
		test_ft_strdup("", s3);
	}
}

int		main(int ac, char **av)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = NULL;
	s2 = NULL;
	s3 = NULL;
	if (!(s1 = load_long_str("txt_files/venausaur.txt"))
		|| !(s2 = load_long_str("txt_files/blastoise.txt"))
		|| !(s3 = load_long_str("txt_files/charizard.txt")))
		return (clean_exit(s1, s2, s3, 1));
	if (ac > 2)
		return (0);
	run_tests(av, s1, s2, s3);
	printf("\nThanks for using this tester. Hope it helped!\n\n");
	return (clean_exit(s1, s2, s3, 0));
}
