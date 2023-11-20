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
	char			*line;
	int				bytes;
	int				i;

	search.len = 0;
	search.max = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	search.root = NULL;
	while (ft_lstchr(&search.root) == 0)
	{
		i = -1;
		bytes = read(fd, search.buffer, BUFFER_SIZE);
		search.buffer[bytes] = '\0';
		if (bytes <= 0)
			return (NULL);
		while (++i < BUFFER_SIZE)
		{
			if (search.buffer[i] == '\n' || search.buffer[i] == '\0' )
			{
				search.len++;
				ft_insert_end(&search.root, search.buffer[i]); 
				break ;
			}
			ft_insert_end(&search.root, search.buffer[i]);
			search.len++;
		}
		search.max =+ BUFFER_SIZE;
	}
	search.cursor = search.max - search.len;
	line = ft_transform(search.root, search.len);
	ft_position(search);
	return (line);
}
void	ft_position(t_find search)
{
	search.cursor = search.max - search.len;
	if (search.cursor == 0)
		search.root = NULL;
	else 
		search.root = search.root;
}
int    main(void)
{
    int        fd;
    char    *str;
    // char    *test;

    fd = open("teste.txt", O_RDONLY);
    while ((str = get_next_line(fd)) != NULL)
    {
        printf("%s \n", str);
        free(str);
    }
    close (fd);
    return (0);
}
