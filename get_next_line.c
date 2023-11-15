/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:59 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/15 15:19:40 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("teste.txt", "r");
	str = get_next_line(fd);
	printf("%s\n", str);
	close (fd);
	return (0);
}
