# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:21:07 by aaires-b          #+#    #+#              #
#    Updated: 2024/03/24 19:49:42 by aaires-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCSFILES = main.c parse.c utils.c init.c error.c action.c start.c
OBJDIR = obj/
SRCSDIR = srcs/
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=thread -pthread
INCLUDE = -Iincludes -I/usr/include 

SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))

OBJS = $(patsubst $(SRCSDIR)%.c, $(OBJDIR)%.o, $(SRCS))

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling object files" 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Done"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "Cleaning object files"
	@rm -rf $(OBJDIR)
	@echo "Done"

fclean: clean
	@echo "Cleaning executable file"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re 

