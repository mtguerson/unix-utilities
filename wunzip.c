#include <stdio.h>
#include <stdlib.h>

// Função para descompactar um arquivo único
void wunzip(const char *fileName) {
    // Abre o arquivo especificado
    FILE *fp = fopen(fileName, "r");
    // Se o arquivo não puder ser aberto, executa uma ação específica
    if (fp == NULL) {
        printf("wcat: não é possível abrir o arquivo %s\n", fileName);
        perror("error: fail to open the file");
        exit(1);
    }

    //Inicializa o contador para o número de caracteres presentes no arquivo
    int count;
    // Armazena o caractere lido do arquivo.
    int character;
    while (fread(&count, sizeof(int), 1, fp) == 1) {
        fread(&character, sizeof(char), 1, fp);
        // Imprime o caractere uma quantidade de vezes igual ao valor lido pelo fread
        for (int i = 0; i < count; i++) {
            // Exibe o valor do caractere na saída padrão
            fputc(character, stdout);
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // Se nenhum argumento for fornecido na linha de comando
        printf("wunzip: arquivo1 [arquivo2 ...]\n");
        exit(1);
    }

    // Para cada arquivo fornecido na linha de comando, chama a função de descompactação
    for (int i = 1; i < argc; i++) {
        wunzip(argv[i]);
    }

    return 0;
}
