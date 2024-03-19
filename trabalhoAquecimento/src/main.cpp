#include "jogoDaVida.hpp"

int main(){
    int linhas, colunas;
    getTamanho(linhas, colunas);

    bool **matriz, **matrizAux;
    
    gerarMatrizes(matriz, matrizAux, linhas, colunas);

    leituraMatrizArquivo(matriz, linhas, colunas);

    controladorJogoDaVida(matriz, matrizAux, linhas, colunas);

    deletarMatrizes(matriz, matrizAux, linhas);

    return 0;
}