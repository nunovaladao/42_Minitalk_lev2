# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 17:21:32 by nsoares-          #+#    #+#              #
#    Updated: 2023/02/11 22:14:27 by nsoares-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFT = ./libft/libft.a
#LIBFT_DIR = ./libft

# _________SOURCES____________

SERVER_FILE = server.c
CLIENT_FILE = client.c

#OBJS_SER = $(SERVER_FILE:.c=.o)
#OBJS_CLI = $(CLIENT_FILE:.c=.o)

# __________COLORS____________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# ________MESSAGE_____________

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# __________RULES______________

all: $(SERVER) $(CLIENT)

$(NAME): all 

comp_start:
	@ $(COMP_START)
	@ $(LIBFT)

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAGS) $(SERVER_FILE) $(LIBFT) -o $(SERVER)
	@ $(SERV_READY)

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAGS) $(CLIENT_FILE) $(LIBFT) -o $(CLIENT)
	@ $(CLI_READY)	
$(LIBFT):
	@ $(MAKE) -C ./libft	
clean:
	@ $(RM) $(SERVER) $(CLIENT)
	@ cd libft && make clean
	@ $(CLEANED)
	
fclean: clean
	@ $(RM) $(SERVER) $(CLIENT)
	@ cd libft && make fclean
	@ $(FCLEANED)
		
re:	fclean all