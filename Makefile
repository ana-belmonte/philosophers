# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:21:07 by aaires-b          #+#    #+#              #
#    Updated: 2024/03/12 17:44:58 by aaires-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCSFILES = main.c parsing.c utils.c
OBJDIR = obj/
SRCSDIR = srcs/
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
INCLUDE = -Iincludes -I/usr/include 

SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))

OBJS = $(patsubst $(SRCSDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 

