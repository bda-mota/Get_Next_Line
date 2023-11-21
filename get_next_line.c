/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:59 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/21 20:19:03 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_build_line(t_find *file, t_gnl **root, int bytes)
{
	int	len;

	len = 0;
	while (file->pos < bytes)
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

int	ft_verify_read(int bytes, t_gnl **root)
{
	if (bytes < 0)
	{
		if (*root != NULL)
			ft_dealloc(root);
		return (1);
	}
	else if (bytes == 0)
		return (0);
	return (2);
}

char	*get_next_line(int fd)
{
	static t_find	file;
	t_gnl			*root;
	char			*line;
	int				len;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	root = NULL;
	len = 0;
	while (ft_lstchr(root) == 0)
	{
		if (file.pos == BUFFER_SIZE)
			file.pos = 0;
		else if (file.pos > 0 && file.pos != file.bytes && file.bytes != 0)
		{
			len += ft_build_line(&file, &root, file.bytes);
			continue ;
		}
		file.bytes = read(fd, file.buffer, BUFFER_SIZE);
		if (ft_verify_read(file.bytes, &root) == 0)
			break ;
		else if (ft_verify_read(file.bytes, &root) == 1)
			return (NULL);
		file.buffer[file.bytes] = '\0';
		len += ft_build_line(&file, &root, file.bytes);
	}
	line = ft_transform(root, len);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*str;
	// char    *test;

	fd = open("teste.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close (fd);
	return (0);
} */
