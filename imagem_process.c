#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSTALL_OMP //Install_openmp
#ifdef INSTALL_OMP
	#include <omp.h>
#endif // INSTALL_OMP

#define QTD_CARACTER_HEIGTH 3
#define QTD_CARACTER_WIDTH 3

typedef struct pixel** ptr_pixel;
struct pixel
{
  unsigned int r, g, b;	
};

typedef struct 
{
  ptr_pixel pixels;
  char tipo[2];
  unsigned int width, height;
	
}img;



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

unsigned long get_len_arq(FILE * f)
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

void gravar_datas_output(char * path, img * image)
{
	FILE* arq = open_arquivo(path, "wb");
	fprintf(arq, "P3\n%d %d\n%d\n", (*image).width, (*image).height, 255);
	unsigned int i, j;
	for (i = 0; i < (*image).height; i++) {
		for (j = 0; j < (*image).width; j++) {
			fprintf(arq, "%d", (*image).pixels[i][j].r);
			fprintf(arq, "%d", (*image).pixels[i][j].g);
			fprintf(arq, "%d\n", (*image).pixels[i][j].b);
		}
	}
	printf("Gravacao realizada com sucesso!\n");
	fclose(arq);
}


// *******************************************************
// Função que grava os bytes em um aquivo
// *******************************************************
void GravaArquivo(char * path, unsigned char * ptr, int tamanho)
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

void create_matriz_pixels_img(unsigned char* data, unsigned int len, img* image)
{
	(*image).tipo[0] = data[0];
	(*image).tipo[1] = data[1];
	char height[4], width[4];

	unsigned int i, j, k, l;
	for (i = 0; i < QTD_CARACTER_HEIGTH; i++) {
		k = i + 3;
		width[i] = data[k];
	}
	width[i] = '\0';
	k += 2;
	for (j = 0; j < QTD_CARACTER_WIDTH; j++, k++) { 
		height[j] = data[k];
	}
	height[j] = '\0';

	(*image).height = atoi(height);
	(*image).width = atoi(width);
	printf("%d x %d\n", (*image).height, (*image).width);

	if (((*image).pixels = (struct pixel **)malloc(sizeof(struct pixel*) * ((*image).height))) == NULL) {
		fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
	}

	for (int i = 0; i < (*image).height; i++)
	{
		if (((*image).pixels[i] = (struct pixel *)malloc(sizeof(struct pixel) * ((*image).width))) == NULL) {
		fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
		}	
	}
	return;
	k = 15;
	for (i = 0; i < (*image).height; i++) {
		char cor = 'r';
		for (j = 0; j < (*image).width; j++) {
			switch (cor) {
				case 'r' : (*image).pixels[i][j].r = 10;//data[k++];
						cor = 'g';
				break;
				case 'g' : (*image).pixels[i][j].g = 10;//data[k++];
						cor = 'b';
				break;
				case 'b' : (*image).pixels[i][j].b = 10;//data[k++];
						cor = 'r';
				break;
			}
			//printf("[%d][%d]\n", i, j);
		}
	}
}

unsigned char * read_image_input(char * _arq, unsigned long * _len_arq, img* image)
{
	FILE* arq = open_arquivo(_arq, "rb");
	*_len_arq = get_len_arq(arq);
	printf("O tamanho do arquivo %s é %ld bytes.\n", _arq, *_len_arq);

	//Aloca memória para ler todos os bytes do arquivo
	unsigned char *ptr;
	ptr =  (unsigned char *) malloc(sizeof(unsigned char) * *_len_arq);
	if (ptr == NULL) {
		printf("Erro na alocação da memória\n");
		exit(1);
	}

	read_file_bin(arq, ptr, *_len_arq);
	create_matriz_pixels_img(ptr, *_len_arq, image);
	fclose(arq);
	return ptr;
}

void tonalidade_gray(unsigned char * data, img * image, unsigned int len_img)
{
	printf("Aplicando tonalidade gray!\n");
	#ifdef INSTALL_OMP
        #pragma omp parallel for
	#endif
	unsigned int i, j;
	for (i = 15; i < len_img; i += 3) {
		data[i] = (int) ((0.299 * data[i]) + (0.587 * data[i + 1]) + (0.144 * data[i + 2])); //calcula o valor para conversão
		data[i + 1] = data[i]; //copia o valor para
		data[i + 2] = data[i];  //todas componentes
		//testa o valor para ver se o mesmo não passou de 255
        if (data[i] > 255) {
            data[i] = 255;
            data[i + 1] = 255;
            data[i + 2] = 255;
		}
	}
}


void printf_matriz_img(img * image)
{
	unsigned int i, j;
	printf("height=%d, width=%d\n",(*image).height, (*image).height);
	for (i = 0; i < (*image).height; i++) {
		for (j = 0; j < (*image).width; j++) {
			printf("%d,", (*image).pixels[i][j].r);
			printf("%d,", (*image).pixels[i][j].g);
			printf("%d\n", (*image).pixels[i][j].b);
		}
	}
	exit(1);
}

int main(int argc, char const *argv[])
{
	char path_arq_ppm[] = "/home/felipe/GitHub/Processamento-imagem/memorial.ppm";
	char path_arq_ppm_out[] = "/home/felipe/GitHub/Processamento-imagem/memorial_gray.ppm";
	unsigned long len_arq;
	unsigned char* datas;
	img image;

	datas = read_image_input(path_arq_ppm, &len_arq, &image);
	//print_data(datas, len_arq);
	//printf_matriz_img(&image);
	tonalidade_gray(datas, &image, len_arq);
	//print_data(datas, len_arq);
	GravaArquivo(path_arq_ppm_out, datas, len_arq);
	//gravar_datas_output(path_arq_ppm_out, &image);

	return 0;
}