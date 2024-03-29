/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snadaras <snadaras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:28:37 by snadaras          #+#    #+#             */
/*   Updated: 2018/02/14 19:51:17 by snadaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFF_SIZE 20
# define ENDL '\n'
# define END '\0'

int		get_next_line(const int fd, char **line);

#endif
