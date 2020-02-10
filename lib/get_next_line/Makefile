# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvan-sni <jvan-sni@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 16:59:45 by jvan-sni       #+#    #+#                 #
#    Updated: 2020/01/02 22:23:42 by tbruinem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
FLAGS = -Wall -Wextra -Werror
BUFFER_SIZE=5
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $< -c -I.

$(NAME): $(OBJ)
	echo "Compiling.."
	@ar -rcs $(NAME) $(OBJ)

fclean: clean
	@rm -f $(NAME)

clean:
	@echo "Cleaning.."
	@rm -f $(OBJ)

re: fclean all
