SERVER = server
CLIENT = client 

INCLUDES = includes


all:
	gcc srcs/server.c -I $(INCLUDES) -o $(SERVER)
	gcc srcs/client.c -I $(INCLUDES) -o $(CLIENT)

server:
	gcc srcs/server.c -I $(INCLUDES) -o $(SERVER)

client:
	gcc srcs/client.c -I $(INCLUDES) -o $(CLIENT)

clean:
	rm -rf srcs/client.o srcs/server.o

fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all	