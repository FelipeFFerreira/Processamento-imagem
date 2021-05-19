#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INSTALL_OMP //Install_openmp
#ifdef INSTALL_OMP
	#include <omp.h>
#endif // INSTALL_OMP

void print_data(unsigned char * data, unsigned int len)
{
	unsigned int i, k = 0;
	for (i = 15; i < len; i++, k++) {
		if (k < 2) printf("%d,  ", data[i]);
		else {
			printf("%d\n", data[i]);
			k = -1;
		}
	}
}

FILE *open_arquivo(char * str, char * modo) {

    FILE * arq; //Arquivo lógico
    if ((arq = fopen(str, modo)) == NULL) {
        printf("Erro na abertura do arquivo %s\n", "filename");
        exit(0x3);
    }
    return arq;
}

unsigned long get_len_fptr(FILE * f)
{
	fseek(f, 0, SEEK_END);
	unsigned long len = (unsigned long)ftell(f);
	fseek(f, SEEK_SET, 0);
	return len;
}

void read_file_bin(FILE* f, unsigned char * ptr, unsigned long len_esperado)
{
	unsigned long  qtd_bytes_read;
	qtd_bytes_read = fread(ptr, sizeof(unsigned char), len_esperado, f);
	if (qtd_bytes_read != len_esperado) {
		printf("Erro na Leitura do arquivo\n");
		printf("Número de bytes lidos %ld\n", qtd_bytes_read);
	} else
		printf("Leitura realizada com sucesso\n");
}

void grava_arquivo(char * path, unsigned char * ptr, int tamanho)
{
	FILE * f = open_arquivo(path, "wb");
    unsigned long qtd_bytes_gravados;
    qtd_bytes_gravados = fwrite(ptr, sizeof(unsigned char), tamanho, f);
    if(qtd_bytes_gravados != tamanho) { // verifica se a gravacao funcionou
	printf("Erro na gravacao do arquivo!\n");
	exit(1);
    } else
	printf("Gravacao realizada com sucesso! (%ld)\n", qtd_bytes_gravados);	
}

unsigned char * read_image_input(char * _arq, unsigned long * _len_fptr)
{
	FILE* arq = open_arquivo(_arq, "rb");
	*_len_fptr = get_len_fptr(arq);
	printf("O tamanho do arquivo %s é %ld bytes.\n", _arq, *_len_fptr);

	//Aloca memória para ler todos os bytes do arquivo
	unsigned char *ptr;
	ptr =  (unsigned char *) malloc(sizeof(unsigned char) * *_len_fptr);
	if (ptr == NULL) {
		printf("Erro na alocação da memória\n");
		exit(1);
	}

	read_file_bin(arq, ptr, *_len_fptr);
	fclose(arq);
	return ptr;
}

void config_params_date_aux(unsigned char * data_aux, unsigned char * data, unsigned int len_header)
{
	for (int i = 0; i < len_header; i++)
	{
		data_aux[i] = data[i];
	}
}

unsigned char * tonalidade_gray(unsigned char * data, unsigned int len_img)
{
	unsigned char * data_aux;
	data_aux =  (unsigned char *) malloc(sizeof(unsigned char) * len_img);
	if (data_aux == NULL) {
		printf("Erro na alocação da memória\n");
		exit(1);
	}

	config_params_date_aux(data_aux, data, 15);

	printf("Aplicando tonalidade gray!\n");
	#ifdef INSTALL_OMP
        #pragma omp parallel for
	#endif
	int i, j;
	bool state_linha = true;

	for (i = 15; i < len_img; i += 3) {
		data_aux[i] = (int) ((0.299 * data[i]) + (0.587 * data[i + 1]) + (0.144 * data[i + 2])); //calcula o valor para conversão
		data_aux[i + 1] = data_aux[i]; //copia o valor para
		data_aux[i + 2] = data_aux[i];  //todas componentes
        
        if (data_aux[i] > 255) {
            data_aux[i] = 255;
            data_aux[i + 1] = 255;
            data_aux[i + 2] = 255;
		}
	}
	return data_aux;
}

void tonalidade_toggle_gray(unsigned char * data, unsigned int len_img)
{
	printf("Aplicando tonalidade gray!\n");
	#ifdef INSTALL_OMP
        #pragma omp parallel for
	#endif
	
	int i, j;
	bool state_linha = true;

	for (i = 15; i < len_img; i += 3) {
		
		//if (i % (512 * 3) == 0) printf("multiplos %d = %d\n", 512 * 3, i);
		if (state_linha) {
			data[i] = (int) ((0.299 * data[i]) + (0.587 * data[i + 1]) + (0.144 * data[i + 2])); //calcula o valor para conversão
			data[i + 1] = data[i]; //copia o valor para
			data[i + 2] = data[i];  //todas componentes
	        
	        if (data[i] > 255) {
	            data[i] = 255;
	            data[i + 1] = 255;
	            data[i + 2] = 255;
			}

			printf("impar i =%d\n", i);
			if ((i + 3) % (512 * 3) == 0) {
				state_linha = false;
				//printf("TROCA\n");
			}
		}
		else {
			printf("par i =%d\n", i);
			if ((i + 3) % (512 * 3) == 0) {
				state_linha = true;
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	char path_arq_ppm[] = "/home/felipe/GitHub/Processamento-imagem/imgs/memorial.ppm";
	char path_arq_ppm_out_gray[] = "/home/felipe/GitHub/Processamento-imagem/imgs/memorial_gray.ppm";
	char path_arq_ppm_out_gray_toggle[] = "/home/felipe/GitHub/Processamento-imagem/imgs/memorial_toggle.ppm";
	unsigned long len_fptr;
	unsigned char* datas;

	datas = read_image_input(path_arq_ppm, &len_fptr);
	unsigned char * data_gray = tonalidade_gray(datas, len_fptr);
	grava_arquivo(path_arq_ppm_out_gray, data_gray, len_fptr);

	return 0;
}