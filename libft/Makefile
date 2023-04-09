# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjung <hyunjung@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 14:10:21 by hyunjung          #+#    #+#              #
#    Updated: 2022/09/01 14:10:21 by hyunjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
FLAGS	= -Wall -Wextra -Werror #-g3 #-fsanitize=address
AR		= ar rcs

SRCS	= ft_memset.c\
		  	ft_split.c\
		  	ft_strlcpy.c\
		  	ft_strlen.c\
		  	ft_strndup.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strjoin_char.c\
			ft_putstr_fd.c\
			ft_strncmp.c\
			ft_itoa.c\
			ft_free_split.c\
			ft_clip_split.c\
			ft_double_strjoin.c\
			ft_strnstr.c\
			ft_strrchr.c\
			error.c\
			ft_strchr.c\
			get_next_line.c\
			get_next_line_utils.c\
			count_strs.c\
			ft_atoi.c\
			ft_join.c
HEAD	= libft.h

OBJS	= $(SRCS:.c=.o)

	
$(NAME)	: $(OBJS)
		$(AR) $@ $^
		
%.o : %.c 
	gcc $(FLAGS) -c $(SRCS)

all		: $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		: fclean all


.PHONY	: all clean fclean re bonus