/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:08:56 by bda-mota          #+#    #+#             */
/*   Updated: 2023/11/17 16:22:54 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

typedef struct s_gnl
{
	char			c;
	struct s_gnl	*next;
}	t_gnl;

typedef struct s_find
{
	char	buffer[BUFFER_SIZE];
	int		max;
	int		len;
	int		cursor;
	t_gnl	*root;
}	t_find;

char	*get_next_line(int fd);
char	*ft_transform(t_gnl *root, int len);
int		ft_lstchr(t_gnl *root, int c);
void	ft_insert_end(t_gnl **root, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
