# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:47:16 by mdelforg          #+#    #+#              #
#    Updated: 2022/03/20 11:11:35 by mdelforg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = srcs/main.c \
	   srcs/pipex_utils.c \
	   srcs/error_free.c \
	   srcs/libft.c \
	   srcs/libft_split.c

OBJS = $(SRCS:.c=.o)

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

exe:	all clean

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
