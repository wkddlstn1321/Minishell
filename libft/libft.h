/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:13:03 by hyunjung          #+#    #+#             */
/*   Updated: 2022/09/01 14:13:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void			*ft_memset(void *b, int c, size_t len);
char			**ft_split(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strndup(const char *s, size_t len);
char			*ft_strdup(char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_char(char *s1, char c);
void			ft_putstr_fd(char	*s, int fd);
int				ft_strncmp(const char	*str1, const char	*str2, size_t n);
void			ft_putstr_fd(char *s, int fd);
char			*ft_itoa(int n);
unsigned char	ft_atoi(const char *str, int *error);
char			**ft_free_split(char **mem);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_clip_split(char **str, int *nbrs);
char			**ft_double_strjoin(char	**s1, char	**s2);
void			error(char	*str, int error);
char			*ft_strchr(const char *str, int c);
char			*ft_strnstr(const char *str, const char *substr, int n);
char			*ft_strrchr(const char *s, int c);
int				count_strs(char	**strs);
char			*ft_join(char const *s1, char const *s2);

#endif
