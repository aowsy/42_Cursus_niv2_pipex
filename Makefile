# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/25 15:47:16 by mdelforg          #+#    #+#              #
#    Updated: 2022/03/21 17:58:40 by mdelforg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = srcs/main.c \
	   srcs/pipex_utils.c \
	   srcs/error_free.c \
	   srcs/libft.c \
	   srcs/libft_split.c

SRCS_BONUS = srcs_bonus/main_bonus.c \
			 srcs_bonus/pipex_utils_bonus.c \
			 srcs_bonus/error_free_bonus.c \
			 srcs_bonus/libft_bonus.c \
			 srcs_bonus/libft_split_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC		= gcc -g
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

exe:		all clean

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

bonus:		${OBJS_BONUS}
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)

exe_bonus:		bonus clean

.PHONY:		exe clean fclean re bonus
