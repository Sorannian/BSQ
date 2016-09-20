# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/19 17:27:46 by mdupuy            #+#    #+#              #
#    Updated: 2016/09/19 17:30:23 by mdupuy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = ./src
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(NAME) -o $(NAME) $(SRC)

clean:
	/bim/rm -f $(SRCCOMP)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
