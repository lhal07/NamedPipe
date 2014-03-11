BIN=bin/
SRC=src/
RM=rm -rf

all: server client

server:
	$(CC) $(SRC)server.c -o $(BIN)server

client:
	$(CC) $(SRC)client.c -o $(BIN)client

clean:
	$(RM) $(BIN)server $(BIN)client
