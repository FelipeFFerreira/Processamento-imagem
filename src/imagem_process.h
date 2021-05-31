#ifndef _IMAGEM_PROCESS_H
#define _IMAGEM_PROCESS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INSTALL_OMP //Install_openmp
#ifdef INSTALL_OMP
	#include <omp.h>
#endif // INSTALL_OMP


void print_data(unsigned char * data, unsigned int len);

FILE * open_arquivo(char * str, char * modo);

unsigned long get_len_fptr(FILE * f);

void read_file_bin(FILE* f, unsigned char * ptr, unsigned long len_esperado);

void grava_arquivo(char * path, unsigned char * ptr, int tamanho);

unsigned char * read_image_input(char * _arq, unsigned long * _len_fptr);

void config_params_date_aux(unsigned char * data_aux, unsigned char * data, unsigned int len_header);

unsigned char * tonalidade_gray(unsigned char * data, unsigned int len_img);

unsigned char * inverte_image(unsigned char * data, unsigned int len_img);

unsigned char * tonalidade_toggle_gray(unsigned char * data, unsigned int len_img);

#endif // _IMAGEM_PROCESS_H
