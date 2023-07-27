#include <stdio.h>
#include <stdlib.h>

void wzip(FILE *fp)
{
    // Contador de sequência de caracteres
    int count = 1;
    // Registra o caractere atual e o próximo
    int currentChar, nextChar;

    // Lê o primeiro caractere do arquivo
    currentChar = fgetc(fp);

    // Verifica se o próximo caractere não é o fim do arquivo
    while ((nextChar = fgetc(fp)) != EOF)
    {
        // Se o caractere atual for igual ao próximo caractere
        if (currentChar == nextChar)
        {
            // Aumenta o contador
            count++;
        }
        else
        {
            // Escreve o caractere atual e seu contador no arquivo compactado
            fwrite(&count, sizeof(int), 1, stdout);
            fputc(currentChar, stdout);

            // Zera o contador de sequência de caracteres
            count = 1;
        }

        // Define o valor do próximo caractere como o valor atual para entrar no primeiro if novamente
        currentChar = nextChar;
    }

    // Escreve o último caractere e seu contador no arquivo compactado
    fwrite(&count, sizeof(int), 1, stdout);
    fputc(currentChar, stdout);
}

int main(int argc, char *argv[])
{
    // Se nenhum argumento for fornecido na linha de comando
    if (argc < 2)
    {
        printf("wzip: arquivo1 [arquivo2 ...]\n");
        exit(1);
    }

    // Itera sobre cada arquivo fornecido como argumento
    for (int i = 1; i < argc; i++)
    {
        // Abre o arquivo
        FILE *fp = fopen(argv[i], "r");

        // Se o arquivo não for encontrado
        if (fp == NULL)
        {
            printf("wzip: nao é possível abrir o arquivo %s\n", argv[i]);
            perror("error: fail to open the file");
            exit(1);
        }

        // Chama a função wzip com o arquivo aberto como argumento
        wzip(fp);

        // Fecha o arquivo
        fclose(fp);
    }

    return 0;
}
