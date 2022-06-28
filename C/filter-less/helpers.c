#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Para as linhas
    for (int i = 0; i < height ; i++)
    {
//Para as colunas
        for (int j = 0; j < width; j++)
        {
//Convertendo os pixeis em float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

//fazer a media dos falores para trasformar em cinza
            int media = round((Red + Green + Blue) / 3.0);
//cada pixiel vai receber o mesmo valor de media
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = media;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Para as linhas
    for (int i = 0; i < height ; i++)
    {
//Para as colunas
        for (int j = 0; j < width; j++)
        {
            //Convertendo os pixeis em float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

//Calculando o valor novo das cores para sepia
            int NewRed = round((Red * 0.393) + (Green * 0.769) + (Blue * 0.189));
            int NewGreen = round((Red * 0.349) + (Green * 0.686) + (Blue * 0.168));
            int NewBlue = round((Red * 0.272) + (Green * 0.534) + (Blue * 0.131));


//importante mantes os valores ate um maximo de 255
            if (NewRed > 255)
            {
                NewRed = 255;
            }
            if (NewGreen > 255)
            {
                NewGreen = 255;
            }
            if (NewBlue > 255)
            {
                NewBlue = 255;
            }
//Atualizar os pixeis para a nova cor
            image[i][j].rgbtRed = NewRed;
            image[i][j].rgbtGreen = NewGreen;
            image[i][j].rgbtBlue = NewBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Para as linhas
    for (int i = 0; i < height ; i++)
    {
//Para as colunas
        for (int j = 0; j < width / 2; j++)
        {
//fazer a troca de pixel criando uma variavel temporaria
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    //Para as linhas
    for (int i = 0; i < height ; i++)
    {
//Para as colunas
        for (int j = 0; j < width; j++)
        {
//fazendo uam copia da imagem paa palicar o filto sem alterar os pixeis anteriores
            copy[i][j] = image[i][j];
        }
    }
//Para as linhas
    for (int i = 0; i < height ; i++)
    {
//Para as colunas
        for (int j = 0; j < width; j++)
        {
//as variaveis para poder guadar as
            int red, green, blue;
            red = green = blue = 0;
            float contador = 0.00;
//loop para poder circular um pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
//essas variaveis vao ser o pixel a ser modificado
                    int currentX = i + x;
                    int currentY = j + y;
//esses sao os limites da imagem para nao tentar contar pexeis fora da imagem
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
//comando para continuar o loop pulando os pixeis invalidos
                        continue;
                    }
//passando o valor orriginal para uma variavel para o calculo
                    red += image[currentX][currentY].rgbtRed;
                    green += image[currentX][currentY].rgbtGreen;
                    blue +=  image[currentX][currentY].rgbtBlue;
//o contador vai ser util para saber quantos pixeis realmente foram usados em cada conta
                    contador++;
                }
//Calculando a media das cores
                copy[i][j].rgbtRed = round(red / contador);
                copy[i][j].rgbtGreen = round(green / contador);
                copy[i][j].rgbtBlue = round(blue / contador);
            }
        }
    }
//para as linhas
    for (int i = 0; i < height ; i++)
    {
//Para as colunas
        for (int j = 0; j < width; j++)
        {
//Copiando os pixeis borrados para a imagem original
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
