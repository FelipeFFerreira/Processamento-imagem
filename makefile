img_bin: src/main.o src/imagem_process.o
	gcc -o img src/main.o src/imagem_process.o

main.o: src/main.c src/imagem_process.h
	gcc -c src/main.c

imagem_process.o: src/imagem_process.c src/imagem_process.h
	gcc -c src/imagem_process.c -fopenmp

