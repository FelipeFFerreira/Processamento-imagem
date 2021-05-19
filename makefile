img: imagem_process.o
	gcc -o img imagem_process.o -lpthread -fopenmp

imagem_process.c: imagem_process.c
	gcc -c imagem_process.c


