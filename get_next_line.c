/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:59 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/21 15:06:04 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_build_line(t_find *file, t_gnl **root)
{
	int	len;

	len = 0;
	while (file->pos < BUFFER_SIZE)
	{
		if (file->buffer[file->pos] == '\n' || file->buffer[file->pos] == '\0')
		{
			ft_insert_end(root, file->buffer[file->pos]);
			len++;
			file->pos++;
			break ;
		}
		ft_insert_end(root, file->buffer[file->pos]);
		len++;
		file->pos++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static t_find	file;
	t_gnl			*root;
	char			*line;
	int				bytes;
	int				len;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	root = NULL;
	len = 0;
	while (ft_lstchr(root) == 0)
	{
		if (file.pos == BUFFER_SIZE)
			file.pos = 0;
		else if (file.pos != 0)
		{
			len += ft_build_line(&file, &root);
			continue ;
		}
		bytes = read(fd, file.buffer, BUFFER_SIZE);
		file.buffer[bytes] = '\0';
		if (bytes <= 0)
			break ;
		len += ft_build_line(&file, &root);
	}
	line = ft_transform(root, len);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str;
	// char    *test;

	fd = open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close (fd);
	return (0);
}
