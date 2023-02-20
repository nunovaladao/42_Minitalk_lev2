# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 17:21:32 by nsoares-          #+#    #+#              #
#    Updated: 2023/02/19 18:14:35 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
RM = rm -rf
LIBFT = ./libft/libft.a

# _________SOURCES____________

SERVER_FILE = server.c
CLIENT_FILE = client.c

OBJS_SER = $(SERVER_FILE:.c=.o)
OBJS_CLI = $(CLIENT_FILE:.c=.o)

SERVER_BFILE = server_bonus.c
CLIENT_BFILE = client_bonus.c

OBJS_SER_BONUS = $(SERVER_BFILE:.c=.o)
OBJS_CLI_BONUS = $(CLIENT_BFILE:.c=.o)

# __________COLORS____________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# _________MESSAGE_____________

COMPILATION_START	=	echo "\n$(BOLD_YELLOW)Make: $(NO_COLOR)Compilation start...\n"

SERVER_READY	=	echo "\n✅ Server ready!\n"

CLIENT_READY	=	echo "\n✅ Client ready!\n"

CLEANED		=	echo "\n$(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n$(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# __________RULES______________

all: $(SERVER) $(CLIENT)

$(NAME): all 

compilation_start:
	@ $(COMPILATION_START)
	@ $(LIBFT)

$(SERVER): $(LIBFT) $(OBJS_SER)
	@ $(CC) $(CFLAGS) $(SERVER_FILE) $(LIBFT) -o $(SERVER)
	@ $(SERVER_READY)

$(CLIENT): $(LIBFT) $(OBJS_CLI)
	@ $(CC) $(CFLAGS) $(CLIENT_FILE) $(LIBFT) -o $(CLIENT)
	@ $(CLIENT_READY)	

$(SERVER_BONUS): $(LIBFT) $(OBJS_SER_BONUS)
	@ $(CC) $(CFLAGS) $(SERVER_BFILE) $(LIBFT) -o $(SERVER_BONUS)
	@ $(SERVER_READY)

$(CLIENT_BONUS): $(LIBFT) $(OBJS_CLI_BONUS)
	@ $(CC) $(CFLAGS) $(CLIENT_BFILE) $(LIBFT) -o $(CLIENT_BONUS)
	@ $(CLIENT_READY)

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(OBJS_SER)  $(OBJS_CLI)
	@ $(RM) $(OBJS_SER_BONUS) $(OBJS_CLI_BONUS)
	@ cd libft && make clean
	@ $(CLEANED)
	
fclean: clean
	@ $(RM) $(SERVER) $(CLIENT)
	@ $(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@ cd libft && make fclean
	@ $(FCLEANED)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)
		
re:	fclean all