main: 
	gcc server.c fleurieu.c -o build/server.o 
	gcc client.c fleurieu.c -o build/client.o 
