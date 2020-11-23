/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:44:34 by vlugand-          #+#    #+#             */
/*   Updated: 2020/11/20 17:34:42 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_ft_write(char *s)
{
	int		fd1;
	int		fd2;

	printf(CYAN);
	printf("==================================");
	printf(" ft_write ====================================\n\n");
	printf(RESET);
	printf("Testing your ft_write with stdout:\n\n");
	printf("Your output:\n");
	ft_write(1, s, 1837);
	printf("\nExpected   :\n");
	write(1, s, 1837);
	write(1, "\n\n", 2);
	fd1 = open("./tmp1", O_RDWR);
	fd2 = open("./tmp2", O_RDWR);
	ft_write(fd1, s, 1837);
	write(fd2, s, 1837);
	if (fd1 > 0 && fd2 > 0)
		cmp_files("./tmp1", "./tmp2");
	close(fd1);
	close(fd2);
	test_ft_write_2();
}

void	test_ft_write_2(void)
{
	int		ret1;
	int		fd1;
	int		fd2;

	printf("Testing your ft_write with an opened file:\n\n");
	fd1 = open("./tmp3", O_RDWR);
	fd2 = open("./tmp4", O_RDWR);
	ft_write(fd1, "Test1", 5);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	ret1 = errno;
	write(fd2, "Test1", 5);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	if (ret1 == errno && fd1 > 0 && fd2 > 0)
		cmp_files("./tmp3", "./tmp4");
	else if (fd1 < 1 || fd2 < 1)
		printf("Can't open tmp files. Make sure you used the script.\n\n");
	else
		print_diff(KO);
	close(fd1);
	close(fd2);
	test_ft_write_3();
}

void	test_ft_write_3(void)
{
	int		ret1;
	int		ret2;
	int		fd1;

	printf("Testing your ft_write with a wrong file descriptor:\n\n");
	ft_write(-42, "Test2", 5);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	ret1 = errno;
	write(-42, "Test2", 5);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	int_diff_check(ret1, errno);
	fd1 = open("./tmp5", O_RDWR);
	printf("Testing your ft_write's return value:\n\n");
	if (fd1 > 0)
	{
		ret1 = ft_write(fd1, "123456789123456789123456789123456789123456", 42);
		printf("Your output: %d\n\n", ret1);
		ret2 = write(fd1, "123456789123456789123456789123456789123456", 42);
		printf("Expected   : %d\n\n", ret2);
		int_diff_check(ret1, ret2);
	}
	else
		printf("Can't open tmp files. Make sure you used the script.\n\n");
	close(fd1);
}
