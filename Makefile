NAME = minitalk

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

HEADER = $(INCLUDES)/minitalk.h

HEADERS = minitalk.h

SRV_SRCS = ./srcs/server.c
CLI_SRCS = ./srcs/client.c
SRCS = $(SRV_SRCS) $(CLI_SRCS)

SRV_OBJS = $(SRV_SRCS:.c=.o)
CLI_OBJS = $(CLI_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)

LIBFT_HEADER = ./libft/libft.h
LIBFT = ./libft/libft.a
LIBFT_FLAGS = -L=libft -lft

$(NAME): client server

$(SRV_OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES) -o $@

$(CLI_OBJS): %.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<  -I $(INCLUDES) -o $@

$(LIBFT):
	$(MAKE) -C ./libft

all: $(NAME)

client: $(CLI_OBJS) $(LIBFT) $(HEADER) 
	$(CC) $(CLI_OBJS) $(LIBFT_FLAGS) -o $@

server: $(SRV_OBJS) $(LIBFT) $(HEADER) 
	$(CC) $(SRV_OBJS) $(LIBFT_FLAGS) -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) server
	$(RM) client
	$(MAKE) fclean -C ./libft

re:
	$(MAKE) fclean
	$(MAKE) all

norm:
	norminette $(SRC) | grep "Error"
	norminette $(INCLUDES) | grep "Error"