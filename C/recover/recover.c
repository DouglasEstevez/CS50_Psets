#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

//Verificar se recebeu somente um comando
    if (argc != 2)
    {
        printf("./recover IMAGE\n");
        return 1;
    }

//Abrir o arquivo
    FILE *file = fopen(argv[1], "r");

//Verificar se o arquivo tem algo para ser lido
    if (file == NULL)
    {
        printf("Invalid");
        return 2;
    }

//variavel para salvar o que foi lido do file,
    unsigned char imagens[512];
//Contar quantas imagens
    int contador = 0;
//Separando memoria para escrever novos arquivos
    char *filename = malloc(8 * sizeof(char));
//Variavel do novo arquivo
    FILE *output_file = NULL;

//Loop para ler todo o arquivo
    while (fread(imagens, sizeof(char), 512, file) == 512)
    {
//Verificar se o arquivo e um JPG
        if (imagens[0] == 0xff && imagens[1] == 0xd8 && imagens[2] == 0xff && (imagens[3] & 0xf0) == 0xe0)
        {
//Nomear os arquivos novos
            sprintf(filename, "%03i.jpg", contador);
            output_file = fopen(filename, "w");
//Contar quantas imagens
            contador++;
        }
//Vefrifica se realemnte tem um jpg
        if (output_file != NULL)
        {
//Escrever no novo arquivo
            fwrite(imagens, sizeof(char), 512, output_file);
        }
    }
//Depois de abrir temos que fechar todos os arquivos e malloc para liberar memoria
    free(filename);
    fclose(output_file);
    fclose(file);

    return 0;

}