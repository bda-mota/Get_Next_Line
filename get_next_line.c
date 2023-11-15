/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:59 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/15 18:24:36 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_find	search;
	t_gnl			*root;
	char			*line;
	int				bytes;
	int				i;

	i = 0;
	search.len = 0;
	if (ft_strchr(search.buffer, '\n') == 0)
	{
		bytes = read(fd, search.buffer, BUFFER_SIZE);
		while (ft_strchr(search.buffer, '\n') == 0)
		{
			// insert end
			search.max += BUFFER_SIZE;
			bytes = read(fd, search.buffer, BUFFER_SIZE);
		}
		while (ft_strchr(search.buffer, '\n') == 0)
			search.len++;
	}
	line = ft_transform(root, search.len);
	search.max = search.max - search.cursor;
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	close (fd);
	printf("%s\n", str);
	return (0);
}
