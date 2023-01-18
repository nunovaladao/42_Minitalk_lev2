# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 17:21:32 by nsoares-          #+#    #+#              #
#    Updated: 2023/01/18 17:13:10 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_FILES = 

OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		cp libft/libft.a $(NAME)
		ar rc $(NAME) $(OBJS)
			
clean:
	$(MAKE) clean -C ./libft 
	$(RM) $(OBJS)
	
fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)
		
re:	fclean	$(NAME)