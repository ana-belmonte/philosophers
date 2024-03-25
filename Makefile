# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 21:21:07 by aaires-b          #+#    #+#              #
#    Updated: 2024/03/25 20:06:37 by aaires-b         ###   ########.fr        #
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
MAGENTA = \e[35m
RED = \e[31m
RESET = \e[0m
YELLOW = \e[33m
CYAN = \e[36m
GREEN = \e[32m
BLUE = \e[34m

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@echo -e "$(GREEN)Compiling object files$(RESET)" 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(YELLOW)Done$(RESET)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo -e "$(CYAN)Cleaning object files$(RESET)"
	@rm -rf $(OBJDIR)
	@echo -e "$(YELLOW)Done$(RESET)"

fclean: clean
	@echo -e "$(CYAN)Cleaning executable file$(RESET)"
	@rm -f $(NAME)
	@echo -e "$(YELLOW)Done$(RESET)"

re: fclean all

.PHONY: all clean fclean re 

