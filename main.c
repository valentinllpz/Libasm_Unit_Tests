/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:36:27 by vlugand-          #+#    #+#             */
/*   Updated: 2020/06/02 18:27:09 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libasm.h"

void	red() 
{
  printf("\033[0;31m");
}

void	green()
{
  printf("\033[0;32m");
}

void	yellow()
{
  printf("\033[0;33m");
}

void	magenta()
{
	printf("\033[0;35m");
}

void	cyan()
{
	printf("\033[0;36m");
}

void	reset() 
{
  printf("\033[0m");
}

void	int_diff_check(int res1, int res2)
{
	if (res1 == res2)
	{
		green();
		printf("%*s\n\n", 80,"Diff OK :D");
	}
	else
	{
		red();
		printf("%*s\n\n", 80,"Diff KO :(");
	}
	reset();
}

void	str_diff_check(char *res1, char *res2)
{
	if (strcmp(res1, res2) == 0)
	{
		green();
		printf("%*s\n\n", 80,"Diff OK :D");
	}
	else
	{
		red();
		printf("%*s\n\n", 80,"Diff KO :(");
	}
	reset();	
}

void	strcmp_diff_check(int res1, int res2)
{
	if (res1 == res2)
	{
		green();
		printf("%*s\n\n", 80,"Diff OK :D");
	}
	else if ((res1 < 0 && res2 < 0) || (res1 > 0 && res2 > 0))
	{
		green();
		printf("%*s\n\n", 80,"Diff OK :D");
		yellow();
		printf("The only thing guaranteed by the original strcmp is\
 to return an integer greater\nthan, equal to, or less than 0. Note that when\
 using string literals (instead of\nactual variables) the return value may be\
 automatically replaced with -1, 0 or 1\nby your compiler. As long as your output\
 and the original strcmp share the same\nsign it should not be an issue.\n\n");
	}
	else
	{
		red();
		printf("%*s\n\n", 80,"Diff KO :(");
	}
	reset();
}

void	cmp_files(char *s1, char *s2)
{
	char 		ch1 = '\0';
	char 		ch2 = '\0'; 
	FILE * 		fptr1;
	FILE * 		fptr2;

	fptr1 = fopen(s1, "r");
	fptr2 = fopen(s2, "r");
	while(ch1 != EOF && ch2 != EOF)
	{
		ch1 = getc(fptr1);
		ch2 = getc(fptr2);
		if (ch1 != ch2)
		{
			fclose(fptr1);
			fclose(fptr2);
			red();
			printf("%*s\n\n", 80,"Diff K0 :(");
			reset();
			return;
		}
	}
	fclose(fptr1);
	fclose(fptr2);
	green();
	printf("%*s\n\n", 80,"Diff OK :D");
	reset();
}

void	test_ft_strlen(char *s1, char *s2)
{
	int 		res1;
	int 		res2;

	cyan();
	printf("================================== ft_strlen ===================================\n\n");
	reset();
	printf("Testing your ft_strlen with an empty string:\n\n");
	res1 = ft_strlen(s1);
	res2 = strlen(s1);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	int_diff_check(res1, res2);
	printf("Testing your ft_strlen with a long string:\n");
	res1 = ft_strlen(s2);
	res2 = strlen(s2);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	int_diff_check(res1, res2);
}

void	test_ft_strcpy(char *s1, char *s2)
{
	char dst[1816];
	char *res1;
	char *res2;


	cyan();
	printf("================================== ft_strcpy ===================================\n\n");
	reset();
	printf("Testing your ft_strcpy with an empty string:\n\n");
	res1 = strdup(ft_strcpy(dst, s1));
	res2 = strdup(strcpy(dst, s1));
	printf("Your output : %s\n", res1);
	printf("Expected    : %s\n", res2);
	str_diff_check(res1, res2);
	free(res1);
	free(res2);
	printf("Testing your ft_strcpy with a long string:\n\n");
	res1 = strdup(ft_strcpy(dst, s2));
	res2 = strdup(strcpy(dst, s2));
	printf("Your output : \n%s\n", res1);
	printf("Expected    : \n%s\n", res2);
	str_diff_check(res1, res2);
	free(res1);
	free(res2);
}

void	test_ft_strcmp(char *s1, char *s2)
{
	int			res1;
	int			res2;
	char 		s[] = "Don't panic!";
	
	cyan();
	printf("================================== ft_strcmp ===================================\n\n");
	reset();
	printf("Testing your ft_strcmp with 2 empty strings:\n\n");
	res1 = ft_strcmp(s1, s1);
	res2 = strcmp(s1, s1);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with an empty string for the first argument:\n\n");
	res1 = ft_strcmp(s1, s);
	res2 = strcmp(s1, s);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with an empty string for the second argument:\n\n");
	res1 = ft_strcmp(s, s1);
	res2 = strcmp(s, s1);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with two identical long strings:\n\n");
	res1 = ft_strcmp(s2, s2);
	res2 = strcmp(s2, s2);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with two different strings:\n\n");
	res1 = ft_strcmp(s, s2);
	res2 = strcmp(s, s2);
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	strcmp_diff_check(res1, res2);
	printf("Testing your ft_strcmp with string literals:\n\n");
	res1 = ft_strcmp("Yayy", "Nope");
	res2 = strcmp("Yayy", "Nope");
	printf("Your output : %d\n", res1);
	printf("Expected    : %d\n", res2);
	strcmp_diff_check(res1, res2);
}

void	test_ft_write(char *s)
{
	int		 	fd1;
	int			fd2;
	int			ret1;
	int			ret2;

	cyan();
	printf("================================== ft_write ====================================\n\n");
	reset();
	printf("Testing your ft_write with stdout:\n\n");
	write(1, "Your output:\n", 13);
	ft_write(1, s, 2144);
	write(1, "Expected   :\n", 13);
	write(1, s, 2144);
	fd1 = open("./tmp1",O_RDWR);
	fd2 = open("./tmp2",O_RDWR);
	ft_write(fd1, s, 2144);
	write(fd2, s, 2144);
	cmp_files("./tmp1", "./tmp2");
	close(fd1);
	close(fd2);
	printf("Testing your ft_write with an opened file:\n\n");
	fd1 = open("./tmp3", O_RDWR);
	fd2 = open("./tmp4", O_RDWR);
	ft_write(fd1, "Test1", 5);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	ret1 = errno;
	write(fd2, "Test1", 5);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	if (ret1 == errno)
		cmp_files("./tmp3", "./tmp4");
	else
	{
		red();
		printf("%*s\n\n", 80,"Diff K0 :(");
		reset();
	}
	close(fd1);
	close(fd2);
	fd1 = open("./tmp5", O_RDWR);
	printf("Testing your ft_write with a wrong file descriptor:\n\n");
	ft_write(-42, "Test2", 5);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	ret1 = errno;
	write(-42, "Test2", 5);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	int_diff_check(ret1, errno);
	printf("Testing your ft_write's return value:\n\n");
	ret1 = ft_write(fd1, "123456789123456789123456789123456789123456", 42);
	printf("Your output: %d\n\n", ret1);
	ret2 = write(fd1, "123456789123456789123456789123456789123456", 42);
	printf("Expected   : %d\n\n", ret2);
	int_diff_check(ret1, ret2);
	close(fd1);
}

void	test_ft_read(void)	
{
	int 		fd;
	int			ret1;
	int			ret2;
	int			error;
	char		buf[7];

	cyan();
	printf("=================================== ft_read ====================================\n\n");
	reset();
	printf("Testing your ft_read with stdin. ");
	yellow();
	printf("Please type in \"libasm\" and press enter:\n\n");
	reset();
	write(1, "Your output: ", 13);
	ft_read(0, buf, 6);
	buf[6] = '\0';
	printf("\n\nExpected   : libasm\n\n");
	str_diff_check(buf, "libasm");
	printf("Testing your ft_read with an opened file:\n\n");
	fd = open("./tmp6", O_RDONLY);
	ret1 = 1;
	while (ret1)
		ret1 = ft_read(fd, buf, 1);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	error = errno;
	close(fd);
	fd = open("./tmp6", O_RDONLY);
	ret2 = 1;
	while (ret2)
		ret2 = ft_read(fd, buf, 1);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	if (ret1 == ret2)
		int_diff_check(error, errno);
	else
	{
		red();
		printf("%*s\n\n", 80,"Diff K0 :(");
		reset();
	}
	printf("Testing your ft_read with a wrong file descriptor:\n\n");
	ft_read(-42, buf, 1);
	printf("Your output: Error no %i - %s\n\n", errno, strerror(errno));
	ret1 = errno;
	read(-42, buf, 1);
	printf("Expected   : Error no %i - %s\n\n", errno, strerror(errno));
	int_diff_check(ret1, errno);
	printf("Testing your ft_read's return value:\n\n");
	ret1 = ft_read(fd, buf, 1);
	printf("Your output: %d\n\n", ret1);
	ret2 = read(fd, buf, 1);
	printf("Expected   : %d\n\n", ret2);
	int_diff_check(ret1, ret2);
	close(fd);
}

void	test_ft_strdup(char *s1, char *s2)
{
	char 		*res1;
	char 		*res2;


	cyan();
	printf("================================== ft_strdup ===================================\n\n");
	reset();
	printf("Testing your ft_strdup with an empty string:\n\n");
	res1 = ft_strdup(s1);
	printf("Your output : %s\n", res1);
	res2 = strdup(s1);
	printf("Expected    : %s\n", res2);
	str_diff_check(res1, res2);
	free(res1);
	free(res2);
	printf("Testing your ft_strdup with a long string:\n\n");
	res1 = ft_strdup(s2);
	printf("Your output : \n%s\n", res1);
	res2 = strdup(s2);
	printf("Expected    : \n%s\n", res2);
	str_diff_check(res1, res2);
	free(res1);
	free(res2);
}


int 	main(int ac, char **av)
{
	char		s1[] = "";
	char		s2[] = "                                       /@\n\
                       __        __   /\\/\n\
                      /==\\      /  \\_/\\/  \n\
                    /======\\    \\/\\__ \\__ \n\
                  /==/\\  /\\==\\    /\\_|__ \\\n\
               /==/    ||    \\=\\ / / / /_/\n\
             /=/    /\\ || /\\   \\=\\/ /     \n\
          /===/   /   \\||/   \\   \\===\\\n\
        /===/   /_________________ \\===\\\n\
     /====/   / |                /  \\====\\\n\
   /====/   /   |  _________    /  \\   \\===\\    THE LEGEND OF \n\
   /==/   /     | /   /  \\ / / /  __________\\_____      ______       ___\n\
  |===| /       |/   /____/ / /   \\   _____ |\\   /      \\   _ \\      \\  \\\n\
   \\==\\             /\\   / / /     | |  /= \\| | |        | | \\ \\     / _ \\\n\
   \\===\\__    \\    /  \\ / / /   /  | | /===/  | |        | |  \\ \\   / / \\ \\\n\
     \\==\\ \\    \\\\ /____/   /_\\ //  | |_____/| | |        | |   | | / /___\\ \\\n\
     \\===\\ \\   \\\\\\\\\\\\\\/   /////// /|  _____ | | |        | |   | | |  ___  |\n\
       \\==\\/     \\\\\\\\/ / //////   \\| |/==/ \\| | |        | |   | | | /   \\ |\n\
       \\==\\     _ \\\\/ / /////    _ | |==/     | |        | |  / /  | |   | |\n\
         \\==\\  / \\ / / ///      /|\\| |_____/| | |_____/| | |_/ /   | |   | |\n\
         \\==\\ /   / / /________/ |/_________|/_________|/_____/   /___\\ /___\\\n\
           \\==\\  /               | /==/\n\
           \\=\\  /________________|/=/    \n\
             \\==\\     _____     /==/ \n\
            / \\===\\   \\   /   /===/\n\
           / / /\\===\\  \\_/  /===/\n\
          / / /   \\====\\ /====/\n\
         / / /      \\===|===/\n\
         |/_/         \\===/\n\
                        =  \n";
	char		s3[] = "\
                 .\"-,.__\n\
                 `.     `.  ,\n\
              .--'  .._,'\"-' `.\n\
             .    .'         `'\n\
             `.   /          ,'\n\
               `  '--.   ,-\"'\n\
                `\"`   |  \\\n\
                   -. \\, |\n\
                    `--Y.'      ___.\n\
                         \\     L._, \\\n\
               _.,        `.   <  <\\                _\n\
             ,' '           `, `.   | \\            ( `\n\
          ../, `.            `  |    .\\`.           \\ \\_\n\
         ,' ,..  .           _.,'    ||\\l            )  '\".\n\
        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n\
      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n\
    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n\
    |  '          ..         `-...-\"  |  `-'      / /        . `.\n\
    | /           |L__           |    |          / /          `. `.\n\
   , /            .   .          |    |         / /             ` `\n\
  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \\\n\
 / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n\
.  '         .-f    ,'   `    '.       \\__.---'     _   .'   '     \\ \\\n\
' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n\
|'      _.-\"\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \\\n\
||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n\
||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n\
|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n\
||/            _,-------7 '              . |  `-'    l         /    `||\n\
. |          ,' .-   ,' ||               | .-.        `.      .'     ||\n\
 `'        ,'    `\".'    |               |    `.        '. -.'       `'\n\
          /      ,'      |               |,'    \\-.._,.'/'\n\
          .     /        .               .       \\    .''\n\
        .`.    |         `.             /         :_,'.'\n\
          \\ `...\\   _     ,'-.        .'         /_.-'\n\
           `-.__ `,  `'   .  _.>----''.  _  __  /\n\
                .'        /\"'          |  \"'   '_\n\
               /_|.-'\\ ,\".             '.'`__'-( \\\n\
                 / ,\"'\"\\,'               `/  `-.|\"\n\n ";
	char s4[] = "            _,..-\"\"\"--' `,.-\".\n\
          ,'      __.. --',  |\n\
        _/   _.-\"' |    .' | |       ____\n\
  ,.-\"\"'    `-\"+.._|     `.' | `-..,',--.`.\n\
 |   ,.                      '    j 7    l \\__\n\
 |.-'                            /| |    j||  .\n\
 `.                   |         / L`.`\"\"','|\\  \\\n\
   `.,----..._       ,'`\"'-.  ,'   \\ `\"\"'  | |  l\n\
     Y        `-----'       v'    ,'`,.__..' |   .\n\
      `.                   /     /   /     `.|   |\n\
        `.                /     l   j       ,^.  |L\n\
          `._            L       +. |._   .' \\|  | \\\n\
            .`--...__,..-'\"\"'-._  l L  \"\"\"    |  |  \\\n\
          .'  ,`-......L_       \\  \\ \\     _.'  ,'.  l\n\
       ,-\"`. / ,-.---.'  `.      \\  L..--\"'  _.-^.|   l\n\
 .-\"\".'\"`.  Y  `._'   '    `.     | | _,.--'\"     |   |\n\
  `._'   |  |,-'|      l     `.   | |\"..          |   l\n\
  ,'.    |  |`._'      |      `.  | |_,...---\"\"\"\"\"`    L\n\
 /   |   j _|-' `.     L       | j ,|              |   |\n\
`--,\"._,-+' /`---^..../._____,.L',' `.             |\\  |\n\
   |,'      L                   |     `-.          | \\j\n\
            .                    \\       `,        |  |\n\
             \\                __`.Y._      -.     j   |\n\
              \\           _.,'       `._     \\    |  j\n\
              ,-\"`-----\"\"\"\"'           |`.    \\  7   |\n\
             /  `.        '            |  \\    \\ /   |\n\
            |     `      /             |   \\    Y    |\n\
            |      \\    .             ,'    |   L_.-')\n\
             L      `.  |            /      ]     _.-^._\n\
              \\   ,'  `-7         ,-'      / |  ,'      `-._\n\
             _,`._       `.   _,-'        ,',^.-            `.\n\
          ,-'     v....  _.`\"',          _:'--....._______,.-'\n\
        ._______./     /',,-'\"'`'--.  ,-'  `.\n\
                 \"\"\"\"\"`.,'         _\\`----...' \n\
                        --------\"\"'\n\n";

	if (ac > 2)
		return (0);
	if (av[1][0] == '1')
		test_ft_strlen(s1, s2);
	else if (av[1][0] == '2')
		test_ft_strcpy(s1, s4);
	else if (av[1][0] == '3')
		test_ft_strcmp(s1, s2);
	else if (av[1][0] == '4')
		test_ft_write(s3);
	else if (av[1][0] == '5')
		test_ft_read();
	else if (av[1][0] == '6')
		test_ft_strdup(s1, s2);
	else 
	{
		test_ft_strlen(s1, s2);
		test_ft_strcpy(s1, s4);
		test_ft_strcmp(s1, s2);
		test_ft_write(s3);
		test_ft_read();
		test_ft_strdup(s1, s2);
	}
	printf("\nThanks for using this tester. Hope it helped!\n\n");
}
