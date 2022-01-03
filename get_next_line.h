/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:03:10 by aalvarez          #+#    #+#             */
/*   Updated: 2021/07/25 16:30:37 by aalvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *full, char *buffer);
int		ft_slen(char *string, char c);
char	*ft_linejoin(char *full);
char	*ft_substr(char *full, int start, int len);
char	*ft_strchr(char *full, char c);
char	*ft_linefree(char *line);
char	*ft_bufffree(char *buff);

#endif
