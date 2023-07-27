#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reserva espaço em memória para armazenar o conteúdo do arquivo
#define BUFFER_SIZE 512

// Protótipos
void grepStdin(const char *searchTerm);
void grepFile(const char *searchTerm, const char *fileName);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: termo_de_busca [arquivo ...]\n");
        exit(1);
    }

    // Obtém o termo de busca inserido via terminal
    const char *searchTerm = argv[1];
    // Se nenhum arquivo for especificado, ler do stdin
    if (argc == 2) {
        grepStdin(searchTerm);
    } else {
        // Procurar os termos em cada arquivo fornecido como argumento no terminal
        for (int i = 2; i < argc; i++) {
            grepFile(searchTerm, argv[i]);
        }
    }

    return 0;
}

// Função para buscar termo na entrada padrão
void grepStdin(const char *searchTerm) {
    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("wgrep: erro ao alocar memória\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Verifica se o termo está presente na linha do arquivo
        if (strstr(buffer, searchTerm) != NULL) {
            printf("%s", buffer);
        }
    }

    // Libera o espaço em memória previamente alocado
    free(buffer);
}

// Funcao para buscar o termo em um arquivo
void grepFile(const char *searchTerm, const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    // Se a abertura do arquivo falhar
    if (fp == NULL) {
        printf("wgrep: não é possível abrir o arquivo %s\n", fileName);
        perror("error: fail to open the file");
        exit(1);
    }

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("wgrep: erro ao alocar memória\n");
        // Encerra o arquivo
        fclose(fp);
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (strstr(buffer, searchTerm) != NULL) {
            printf("%s", buffer);
        }
    }

    fclose(fp);
    free(buffer);
}
