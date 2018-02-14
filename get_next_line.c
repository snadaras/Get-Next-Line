/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 18:45:10 by snadaras          #+#    #+#             */
/*   Updated: 2018/02/14 19:50:38 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"

static int		find_endline(char *buff)
{
	int			eval_lengh;

	eval_lengh = 0;
	while (buff[eval_lengh] != ENDL && buff[eval_lengh])
		eval_lengh++;
	if (buff[eval_lengh] == ENDL)
	{
		buff[eval_lengh] = END;
		return (eval_lengh);
	}
	else
		return (-1);
}

static char		*join_datas(char *buff, char *tab)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tab, j);
	ptr[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (ptr);
}

static int		check_case(char **buff, char **tab, char **line)
{
	char		*ptr;
	int			final;

	*buff = join_datas(*buff, *tab);
	final = find_endline(*buff);
	if (final > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + final + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*buff[12000];
	char		*tmp;
	int			trt_case;
	int			something;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (something = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((something = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		trt_case = check_case(&buff[fd], &tmp, line);
		free(tmp);
		if (trt_case == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((trt_case = check_case(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (trt_case);
}
