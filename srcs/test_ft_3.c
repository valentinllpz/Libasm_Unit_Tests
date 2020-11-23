/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:39:34 by vlugand-          #+#    #+#             */
/*   Updated: 2020/11/20 15:52:21 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_ft_read(void)
{
	int		fd;
	char	buf[7];

	printf(CYAN);
	printf("===================================");
	printf(" ft_read ====================================\n\n");
	printf(RESET);
	printf("Testing your ft_read with stdin. ");
	printf(YELLOW);
	printf("Please type in \"libasm\" and press enter:\n\n");
	printf(RESET);
	write(1, "Your output: ", 13);
	ft_read(0, buf, 6);
	buf[6] = '\0';
	printf("\n\nExpected   : libasm\n\n");
	str_diff_check(buf, "libasm");
	printf("Testing your ft_read with an opened file:\n\n");
	fd = open("./tmp6", O_RDONLY);
	if (fd > 0)
		test_ft_read_2(fd, 1, 1, buf);
	else
		printf("Can't open tmp files. Make sure you used the script.\n\n");
}

void	test_ft_read_2(int fd, int ret1, int ret2, char *buf)
{
	int		error;

	ret1 = 1;
	while (ret1)
		ret1 = ft_read(fd, buf, 1);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	error = errno;
	close(fd);
	fd = open("./tmp6", O_RDONLY);
	ret2 = 1;
	while (ret2)
		ret2 = read(fd, buf, 1);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	if (ret1 == ret2)
		int_diff_check(error, errno);
	else
		print_diff(KO);
	printf("Testing your ft_read with a wrong file descriptor:\n\n");
	ft_read(-42, buf, 1);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	ret1 = errno;
	read(-42, buf, 1);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	int_diff_check(ret1, errno);
	test_ft_read_3(fd, ret1, ret2, buf);
}

void	test_ft_read_3(int fd, int ret1, int ret2, char *buf)
{
	printf("Testing your ft_read's return value:\n\n");
	ret1 = ft_read(fd, buf, 1);
	ret2 = read(fd, buf, 1);
	printf("Your output: %d\n\nExpected   : %d\n\n", ret1, ret2);
	int_diff_check(ret1, ret2);
	close(fd);
}
