#include <stdio.h>
#include <stdlib.h>

// Protótipo da função ImprimirArquivo
void ImprimirArquivo(FILE *arq);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        // se nenhum arquivo for especificado, realiza a leitura a partir da entrada padrão
        ImprimirArquivo(stdin);
    }
    else
    {
        // Cria um laço para obter múltiplos arquivos
        for (int i = 1; i < argc; i++)
        {
            // Tenta abrir o arquivo
            FILE *arq = fopen(argv[i], "r");
            // se nao for possível abrir o arquivo
            if (arq == NULL)
            {
                printf("wcat: não é possível abrir o arquivo %s\n", argv[i]);
                perror("erro: falha ao abrir o arquivo");
                exit(1);
            }
            // Chama a função para imprimir o conteúdo do arquivo
            ImprimirArquivo(arq);
            fclose(arq);
        }
    }
    return 0;
}

// Função que imprime o conteúdo de um arquivo dado um ponteiro para seu descritor de arquivo
void ImprimirArquivo(FILE *arq)
{
    char linha[1000];
    while (fgets(linha, sizeof(linha), arq))
    {
        printf("%s", linha);
    }
    printf("\n");
}
