/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:59 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/17 17:48:06 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_find	search;
	t_gnl			*curr;
	char			*line;
	int				bytes;
	int				i;

	search.len = 0;
	search.time++;
	if (search.time == 1)
		search.root = NULL;
	while (ft_lstchr(search.root, '\n') == 0)
	{
		i = -1;
		bytes = read(fd, search.buffer, BUFFER_SIZE);
		search.buffer[bytes] = '\0';
		if (bytes <= 0)
			return (NULL);
		while (++i < BUFFER_SIZE && search.buffer[i] != '\0')
			ft_insert_end(&search.root, search.buffer[i]);
		search.max += BUFFER_SIZE;
	}
	curr = search.root;
	while (curr && curr->c != '\n')
	{
		search.len++;
		curr = curr->next;
	}
	search.cursor = search.max - search.len;
	line = ft_transform(search.root, search.len);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;
	char	*test;

	fd = open("teste.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s \n", str);
	str = get_next_line(fd);
	printf("%s \n", str);

	close (fd);
	return (0);
}
