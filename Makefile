# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkwak <jkwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 15:14:55 by jkwak             #+#    #+#              #
#    Updated: 2022/08/08 15:15:15 by jkwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
NAME = philo

SRCS = main.c \
		ft_atoi.c \
		get_time.c \
		init_func.c \
		monitoring.c \
		parsing.c \
		philo_act.c \
		philo_act2.c \
		print.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -pthread -fsanitize=thread -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean 
	make all	

.PHONY : all clean fclean re
