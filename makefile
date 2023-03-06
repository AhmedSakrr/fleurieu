all: 
	gcc server/main.c server/server.c fleurieu.c -o build/server.o 
	gcc client/main.c client/client.c fleurieu.c -o build/client.o 
