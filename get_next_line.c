/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:59 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/22 14:34:07 by bda-mota         ###   ########.fr       */
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
	if (file->pos == BUFFER_SIZE)
	file->pos = 0;
	return (len);
}

char	*get_next_line(int fd)
{
	static t_find	file;
	t_gnl			*root;
	char			*line;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	root = NULL;
	len = 0;
	while (ft_lstchr(root) == 0)
	{
		if (file.pos > 0 && file.pos != file.bytes && file.bytes != 0)
		{
			len += ft_build_line(&file, &root, file.bytes);
			continue ;
		}
		file.bytes = read(fd, file.buffer, BUFFER_SIZE);
		if (file.bytes < 0)
		{
			ft_dealloc(&root);
			return (NULL);
		}
		if (file.bytes == 0)
			break ;
		file.buffer[file.bytes] = '\0';
		len += ft_build_line(&file, &root, file.bytes);
	}
	line = ft_transform(root, len);
	return (line);
}
int	main(void)
{
	int		fd, fd1;
	char	*str, *str1;
	// char    *test;

	fd = open("teste.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
	printf("\n");
	fd1 = open("teste copy.txt", O_RDONLY);
	while ((str1 = get_next_line(fd1)))
	{
		if (str == NULL)
			break ;
		printf("%s", str1);
		free(str1);
	}
	close(fd1);
	return (0);
}
