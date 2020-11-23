/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:44:01 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 16:35:25 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	free_and_set_to_null(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}

char	*join_new_line(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (NULL);
	len1 = strlen(s1);
	len2 = strlen(s2);
	if (!(dst = (char*)malloc((len1 + len2 + 2) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	dst[i] = '\n';
	len1++;
	i = -1;
	while (s2[++i])
		dst[len1 + i] = s2[i];
	dst[len1 + i] = '\0';
	return (dst);
}

char	*load_long_str(char *path)
{
	int		fd;
	char	*tmp;
	char	*buf;
	char	*dst;

	if ((fd = open(path, O_RDONLY)) < 0)
	{
		printf("Erreur: Le fichier %s n'a pas pu être ouvert.\n", path);
		return (NULL);
	}
	tmp = NULL;
	buf = NULL;
	dst = NULL;
	while (get_next_line(fd, &buf) > 0)
	{
		if (dst)
			tmp = strdup(dst);
		free_and_set_to_null(dst);
		dst = join_new_line(tmp, buf);
		free_and_set_to_null(tmp);
		free_and_set_to_null(buf);
	}
	free_and_set_to_null(buf);
	close(fd);
	return (dst);
}

int		clean_exit(char *s1, char *s2, char *s3, int ret)
{
	free_and_set_to_null(s1);
	free_and_set_to_null(s2);
	free_and_set_to_null(s3);
	return (ret);
}
