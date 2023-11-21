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
	static t_find	file;
	char			*line;
	int				bytes;
	int				i;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file.root = NULL;
	while (ft_lstchr(file.root) == 0)
	{
		i = -1;
		bytes = read(fd, file.buffer, BUFFER_SIZE);
		file.buffer[bytes] = '\0';
		if (bytes <= 0)
			return (NULL);
		while (++i < BUFFER_SIZE)
		{
			if (file.buffer[i] == '\n' || file.buffer[i] == '\0' )
			{
				file.len++;
				ft_insert_end(&file.root, file.buffer[i]); 
				break ;
			}
			ft_insert_end(&file.root, file.buffer[i]);
			file.len++;
		}
		file.max =+ BUFFER_SIZE;
	}
	file.cursor = file.max - file.len;
	line = ft_transform(file.root, file.len);
	return (line);
}
int    main(void)
{
    int        fd;
    char    *str;
    // char    *test;

    fd = open("teste.txt", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s\n", str);
        free(str);
    }
    close (fd);
    return (0);
}
