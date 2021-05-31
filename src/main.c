#include "imagem_process.h"
#include <time.h>

char path_abs[100] = "/home/felipe/GitHub/"; //informe path base de localização dos diretorios


int main(int argc, char const *argv[])
{

	clock_t tempo;
    tempo = clock();
	char path_memorial_input[150], path_memorial_out_gray[150], path_memorial_out_toggle[150], path_memorial_out_inverte[150];
	
	strcpy(path_memorial_input, path_abs);
	strcat(path_memorial_input, "Processamento-imagem/imgs/memorial_img/memorial.ppm");
	strcpy(path_memorial_out_gray, path_abs);
	strcat(path_memorial_out_gray, "Processamento-imagem/imgs/memorial_img/memorial_out_gray.ppm");
	strcpy(path_memorial_out_toggle, path_abs);
	strcat(path_memorial_out_toggle, "Processamento-imagem/imgs/memorial_img/memorial_out_toggle.ppm");
	strcpy(path_memorial_out_inverte, path_abs);
	strcat(path_memorial_out_inverte, "Processamento-imagem/imgs/memorial_img/memorial_out_inverte.ppm");
	
	unsigned long len_fptr;
	unsigned char * datas;

	datas = read_image_input(path_memorial_input, &len_fptr);
	//print_data(datas, len_fptr);
	unsigned char * data_gray = tonalidade_gray(datas, len_fptr);
	unsigned char * data_gray_toggle = tonalidade_toggle_gray(datas, len_fptr);
	unsigned char * data_inverte = inverte_image(datas, len_fptr);

	grava_arquivo(path_memorial_out_gray, data_gray, len_fptr);
	grava_arquivo(path_memorial_out_toggle, data_gray_toggle, len_fptr);
	grava_arquivo(path_memorial_out_inverte, data_inverte, len_fptr);
	
	printf("\n[Tempo Total de execução: %fs]\n", (float) (clock() - tempo)  / CLOCKS_PER_SEC);
	
	return 0;
}
