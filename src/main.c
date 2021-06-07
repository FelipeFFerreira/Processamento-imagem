#include "imagem_process.h"
#include <time.h>

char path_abs[100] = "/home/felipe/GitHub/"; //informe path base de localização dos diretorios


int main(int argc, char const *argv[])
{

	clock_t tempo;
    tempo = clock();
	char path_memorial_input[150], path_memorial_out_gray[150], path_memorial_out_toggle[150], path_memorial_out_inverte[150];
	char path_vista_diagonal_input[150], path_vista_diagonal_out_gray[150], path_vista_diagonal_out_toggle[150], path_vista_diagonal_out_inverte[150];
	char path_vista_frontal_input[150], path_vista_frontal_out_gray[150], path_vista_frontal_out_toggle[150], path_vista_frontal_out_inverte[150];
	char path_vista_fundo_input[150], path_vista_fundo_out_gray[150], path_vista_fundo_out_toggle[150], path_vista_fundo_out_inverte[150];
	char path_vista_lateral_direita_input[150], path_vista_lateral_direita_out_gray[150], path_vista_lateral_direita_out_toggle[150], path_vista_lateral_direita_out_inverte[150];
	char path_vista_lateral_esquerda_input[150], path_vista_lateral_esquerda_out_gray[150], path_vista_lateral_esquerda_out_toggle[150], path_vista_lateral_esquerda_out_inverte[150];
	char path_vista_superior_input[150], path_vista_superior_out_gray[150], path_vista_superior_out_toggle[150], path_vista_superior_out_inverte[150];

	/* Path's*/	
	strcpy(path_memorial_input, path_abs);
	strcat(path_memorial_input, "Processamento-imagem/imgs/memorial_img/memorial.ppm");
	strcpy(path_memorial_out_gray, path_abs);
	strcat(path_memorial_out_gray, "Processamento-imagem/imgs/memorial_img/memorial_out_gray.ppm");
	strcpy(path_memorial_out_toggle, path_abs);
	strcat(path_memorial_out_toggle, "Processamento-imagem/imgs/memorial_img/memorial_out_toggle.ppm");
	strcpy(path_memorial_out_inverte, path_abs);
	strcat(path_memorial_out_inverte, "Processamento-imagem/imgs/memorial_img/memorial_out_inverte.ppm");

	strcpy(path_vista_diagonal_input, path_abs);
	strcat(path_vista_diagonal_input, "Processamento-imagem/imgs/vista_diagonal_img/vista_diagonal.ppm");
	strcpy(path_vista_diagonal_out_gray, path_abs);
	strcat(path_vista_diagonal_out_gray, "Processamento-imagem/imgs/vista_diagonal_img/vista_diagonal_out_gray.ppm");
	strcpy(path_vista_diagonal_out_toggle, path_abs);
	strcat(path_vista_diagonal_out_toggle, "Processamento-imagem/imgs/vista_diagonal_img/vista_diagonal_out_toggle.ppm");
	strcpy(path_vista_diagonal_out_inverte, path_abs);
	strcat(path_vista_diagonal_out_inverte, "Processamento-imagem/imgs/vista_diagonal_img/vista_diagonal_out_inverte.ppm");

	strcpy(path_vista_frontal_input, path_abs);
	strcat(path_vista_frontal_input, "Processamento-imagem/imgs/vista_frontal_img/vista_frontal.ppm");
	strcpy(path_vista_frontal_out_gray, path_abs);
	strcat(path_vista_frontal_out_gray, "Processamento-imagem/imgs/vista_frontal_img/vista_frontal_out_gray.ppm");
	strcpy(path_vista_frontal_out_toggle, path_abs);
	strcat(path_vista_frontal_out_toggle, "Processamento-imagem/imgs/vista_frontal_img/vista_frontal_out_toggle.ppm");
	strcpy(path_vista_frontal_out_inverte, path_abs);
	strcat(path_vista_frontal_out_inverte, "Processamento-imagem/imgs/vista_frontal_img/vista_frontal_out_inverte.ppm");

	strcpy(path_vista_fundo_input, path_abs);
	strcat(path_vista_fundo_input, "Processamento-imagem/imgs/vista_fundo_img/vista_fundo.ppm");
	strcpy(path_vista_fundo_out_gray, path_abs);
	strcat(path_vista_fundo_out_gray, "Processamento-imagem/imgs/vista_fundo_img/vista_fundo_out_gray.ppm");
	strcpy(path_vista_fundo_out_toggle, path_abs);
	strcat(path_vista_fundo_out_toggle, "Processamento-imagem/imgs/vista_fundo_img/vista_fundo_out_toggle.ppm");
	strcpy(path_vista_fundo_out_inverte, path_abs);
	strcat(path_vista_fundo_out_inverte, "Processamento-imagem/imgs/vista_fundo_img/vista_fundo_out_inverte.ppm");

	strcpy(path_vista_lateral_direita_input, path_abs);
	strcat(path_vista_lateral_direita_input, "Processamento-imagem/imgs/vista_lateral_direita_img/vista_lateral_direita.ppm");
	strcpy(path_vista_lateral_direita_out_gray, path_abs);
	strcat(path_vista_lateral_direita_out_gray, "Processamento-imagem/imgs/vista_lateral_direita_img/vista_lateral_direita_out_gray.ppm");
	strcpy(path_vista_lateral_direita_out_toggle, path_abs);
	strcat(path_vista_lateral_direita_out_toggle, "Processamento-imagem/imgs/vista_lateral_direita_img/vista_lateral_direita_out_toggle.ppm");
	strcpy(path_vista_lateral_direita_out_inverte, path_abs);
	strcat(path_vista_lateral_direita_out_inverte, "Processamento-imagem/imgs/vista_lateral_direita_img/vista_lateral_direita_out_inverte.ppm");

	strcpy(path_vista_lateral_esquerda_input, path_abs);
	strcat(path_vista_lateral_esquerda_input, "Processamento-imagem/imgs/vista_lateral_esquerda_img/vista_lateral_esquerda.ppm");
	strcpy(path_vista_lateral_esquerda_out_gray, path_abs);
	strcat(path_vista_lateral_esquerda_out_gray, "Processamento-imagem/imgs/vista_lateral_esquerda_img/vista_lateral_esquerda_out_gray.ppm");
	strcpy(path_vista_lateral_esquerda_out_toggle, path_abs);
	strcat(path_vista_lateral_esquerda_out_toggle, "Processamento-imagem/imgs/vista_lateral_esquerda_img/vista_lateral_esquerda_out_toggle.ppm");
	strcpy(path_vista_lateral_esquerda_out_inverte, path_abs);
	strcat(path_vista_lateral_esquerda_out_inverte, "Processamento-imagem/imgs/vista_lateral_esquerda_img/vista_lateral_esquerda_out_inverte.ppm");

	strcpy(path_vista_superior_input, path_abs);
	strcat(path_vista_superior_input, "Processamento-imagem/imgs/vista_superior_img/vista_superior.ppm");
	strcpy(path_vista_superior_out_gray, path_abs);
	strcat(path_vista_superior_out_gray, "Processamento-imagem/imgs/vista_superior_img/vista_superior_out_gray.ppm");
	strcpy(path_vista_superior_out_toggle, path_abs);
	strcat(path_vista_superior_out_toggle, "Processamento-imagem/imgs/vista_superior_img/vista_superior_out_toggle.ppm");
	strcpy(path_vista_superior_out_inverte, path_abs);
	strcat(path_vista_superior_out_inverte, "Processamento-imagem/imgs/vista_superior_img/vista_superior_out_inverte.ppm");

	/*Datas*/
	unsigned long len_fptr;
	unsigned long len_fptr_vista_diagonal;
	unsigned long len_fptr_vista_frontal;
	unsigned long len_fptr_vista_fundo;
	unsigned long len_fptr_vista_lateral_direita;
	unsigned long len_fptr_vista_lateral_esquerda;
	unsigned long len_fptr_vista_superior;

	unsigned char * datas = read_image_input(path_memorial_input, &len_fptr);
	unsigned char * datas_vista_diagonal = read_image_input(path_vista_diagonal_input, &len_fptr_vista_diagonal);
	unsigned char * datas_vista_frontal = read_image_input(path_vista_frontal_input, &len_fptr_vista_frontal);
	unsigned char * datas_vista_fundo = read_image_input(path_vista_fundo_input, &len_fptr_vista_fundo);
	unsigned char * datas_vista_lateral_direita = read_image_input(path_vista_lateral_direita_input, &len_fptr_vista_lateral_direita);
	unsigned char * datas_vista_lateral_esquerda = read_image_input(path_vista_lateral_esquerda_input, &len_fptr_vista_lateral_esquerda);
	unsigned char * datas_vista_superior = read_image_input(path_vista_superior_input, &len_fptr_vista_superior);

	/*Efeitos*/
	unsigned char * data_gray = tonalidade_gray(datas, len_fptr, 7);
	unsigned char * data_gray_toggle = tonalidade_toggle_gray(datas, len_fptr, 512, 7);
	unsigned char * data_inverte = inverte_image(datas, len_fptr, 7);

	unsigned char * data_gray_vista_diagonal = tonalidade_gray(datas_vista_diagonal, len_fptr_vista_diagonal, 9);
	unsigned char * data_gray_toggle_vista_diagonal = tonalidade_toggle_gray(datas_vista_diagonal, len_fptr_vista_diagonal, 3840, 9);
	unsigned char * data_inverte_vista_diagonal = inverte_image(datas_vista_diagonal, len_fptr_vista_diagonal, 9);

	unsigned char * data_gray_vista_frontal = tonalidade_gray(datas_vista_frontal, len_fptr_vista_frontal, 9);
	unsigned char * data_gray_toggle_vista_frontal = tonalidade_toggle_gray(datas_vista_frontal, len_fptr_vista_frontal, 3840, 9);
	unsigned char * data_inverte_vista_frontal = inverte_image(datas_vista_frontal, len_fptr_vista_frontal, 9);

	unsigned char * data_gray_vista_fundo = tonalidade_gray(datas_vista_fundo, len_fptr_vista_fundo, 9);
	unsigned char * data_gray_toggle_vista_fundo = tonalidade_toggle_gray(datas_vista_fundo, len_fptr_vista_fundo, 3840, 9);
	unsigned char * data_inverte_vista_fundo = inverte_image(datas_vista_fundo, len_fptr_vista_fundo, 9);

	unsigned char * data_gray_vista_lateral_direita = tonalidade_gray(datas_vista_lateral_direita, len_fptr_vista_lateral_direita, 9);
	unsigned char * data_gray_toggle_vista_lateral_direita = tonalidade_toggle_gray(datas_vista_lateral_direita, len_fptr_vista_lateral_direita, 3840, 9);
	unsigned char * data_inverte_vista_lateral_direita = inverte_image(datas_vista_lateral_direita, len_fptr_vista_lateral_direita, 9);

	unsigned char * data_gray_vista_lateral_esquerda = tonalidade_gray(datas_vista_lateral_esquerda, len_fptr_vista_lateral_esquerda, 9);
	unsigned char * data_gray_toggle_vista_lateral_esquerda = tonalidade_toggle_gray(datas_vista_lateral_esquerda, len_fptr_vista_lateral_esquerda, 3840, 9);
	unsigned char * data_inverte_vista_lateral_esquerda = inverte_image(datas_vista_lateral_esquerda, len_fptr_vista_lateral_esquerda, 9);

	unsigned char * data_gray_vista_superior = tonalidade_gray(datas_vista_superior, len_fptr_vista_superior, 9);
	unsigned char * data_gray_toggle_vista_superior = tonalidade_toggle_gray(datas_vista_superior, len_fptr_vista_superior, 3840, 9);
	unsigned char * data_inverte_vista_superior = inverte_image(datas_vista_superior, len_fptr_vista_superior, 9);

	/*Gravação*/
	grava_arquivo(path_memorial_out_gray, data_gray, len_fptr);
	grava_arquivo(path_memorial_out_toggle, data_gray_toggle, len_fptr);
	grava_arquivo(path_memorial_out_inverte, data_inverte, len_fptr);

	grava_arquivo(path_vista_diagonal_out_gray, data_gray_vista_diagonal, len_fptr_vista_diagonal);
	grava_arquivo(path_vista_diagonal_out_toggle, data_gray_toggle_vista_diagonal, len_fptr_vista_diagonal);
	grava_arquivo(path_vista_diagonal_out_inverte, data_inverte_vista_diagonal, len_fptr_vista_diagonal);

	grava_arquivo(path_vista_frontal_out_gray, data_gray_vista_frontal, len_fptr_vista_frontal);
	grava_arquivo(path_vista_frontal_out_toggle, data_gray_toggle_vista_frontal, len_fptr_vista_frontal);
	grava_arquivo(path_vista_frontal_out_inverte, data_inverte_vista_frontal, len_fptr_vista_frontal);

	grava_arquivo(path_vista_fundo_out_gray, data_gray_vista_fundo, len_fptr_vista_fundo);
	grava_arquivo(path_vista_fundo_out_toggle, data_gray_toggle_vista_fundo, len_fptr_vista_fundo);
	grava_arquivo(path_vista_fundo_out_inverte, data_inverte_vista_fundo, len_fptr_vista_fundo);
	
	grava_arquivo(path_vista_lateral_direita_out_gray, data_gray_vista_lateral_direita, len_fptr_vista_lateral_direita);
	grava_arquivo(path_vista_lateral_direita_out_toggle, data_gray_toggle_vista_lateral_direita, len_fptr_vista_lateral_direita);
	grava_arquivo(path_vista_lateral_direita_out_inverte, data_inverte_vista_lateral_direita, len_fptr_vista_lateral_direita);

	grava_arquivo(path_vista_lateral_esquerda_out_gray, data_gray_vista_lateral_esquerda, len_fptr_vista_lateral_esquerda);
	grava_arquivo(path_vista_lateral_esquerda_out_toggle, data_gray_toggle_vista_lateral_esquerda, len_fptr_vista_lateral_esquerda);
	grava_arquivo(path_vista_lateral_esquerda_out_inverte, data_inverte_vista_lateral_esquerda, len_fptr_vista_lateral_esquerda);
	
	grava_arquivo(path_vista_superior_out_gray, data_gray_vista_superior, len_fptr_vista_superior);
	grava_arquivo(path_vista_superior_out_toggle, data_gray_toggle_vista_superior, len_fptr_vista_superior);
	grava_arquivo(path_vista_superior_out_inverte, data_inverte_vista_superior, len_fptr_vista_superior);

	printf("\n[Tempo Total de execução: %fs]\n", (float) (clock() - tempo)  / CLOCKS_PER_SEC);

	return 0;
}
