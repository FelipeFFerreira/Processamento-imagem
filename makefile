parell: main.o threads.o lista_th.o lista.o 
	gcc -o parell main.o threads.o lista_th.o lista.o -lpthread -fopenmp

main.o: src/main.c src/main.h src/libs/lib_thread/threads.h src/libs/lib_lista_int/lista.h src/libs/lib_thread/lista_th.h
	gcc -c src/main.c
	
threads.o: src/libs/lib_thread/threads.c src/libs/lib_thread/threads.h src/libs/lib_lista_int/lista.h src/libs/lib_thread/lista_th.h -lpthread
	gcc -c src/libs/lib_thread/threads.c

lista_th.o: src/libs/lib_thread/lista_th.c src/libs/lib_thread/lista_th.h
	gcc -c src/libs/lib_thread/lista_th.c

lista.o: src/libs/lib_lista_int/lista.c src/libs/lib_lista_int/lista.h
	gcc -c src/libs/lib_lista_int/lista.c	
