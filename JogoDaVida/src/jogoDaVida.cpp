#include "jogoDaVida.hpp"

int numeroGeracoes(){
    int geracoes;
    std::cout << "Informe o número de gerações: ";
    std::cin >> geracoes;

    return geracoes;
}

void leituraMatrizArquivo(bool **matriz, int linhas, int colunas){
    std::ifstream arquivo;
    int i = 0, j = 0;
    std::string linha;

    arquivo.open("datasets/input.mps");

    if(arquivo.is_open()){
        while(std::getline(arquivo, linha)){
            std::istringstream ss(linha);
            int valor;
            j = 0;
            
            while(ss >> valor){
                matriz[i][j] = valor;
                j++;
            }

            i++;
        }
        
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
    }
}

void mostraMatriz(bool **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void getTamanho(int &linhas, int &colunas){
    linhas = 0;
    colunas = 0;

    std::ifstream arquivo;
    std::string linha;
    arquivo.open("datasets/input.mps");

    if(arquivo.is_open()){
        while(std::getline(arquivo, linha)){
            std::istringstream ss(linha);
            int valor;
            colunas = 0;

            while(ss >> valor){
                colunas++;
            }

            linhas++;
        }

        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
    }

    if(linhas < 5 || colunas < 5){
        std::cout << "A matriz deve ter no mínimo 5x5" << std::endl;
        exit(1);
    }
}

void controladorJogoDaVida(bool **matriz, bool **matrizAux, int linhas, int colunas){    
    int qtdGeracoes = numeroGeracoes();
    int geracao = 0;

    do{
        std::cout << std::endl << "Estado atual: (";
        geracao ? std::cout << geracao : std::cout << "Inicial";
        std::cout << ")" << std::endl;

        int qtdVivos = contarQtdVivos(matriz, linhas, colunas);

        std::cout << "Razão entre vivos e mortos (V/M): (" << qtdVivos << "/" << (linhas*colunas - qtdVivos) << ")" << std::endl;

        mostraMatriz(matriz, linhas, colunas);
        gerarArquivosResultado(matriz, linhas, colunas, geracao++);

        calcularGeracao(matriz, matrizAux, linhas, colunas);
        matriz = matrizAux;
    }while(qtdGeracoes--);
}

void deletarMatrizes(bool **matriz, bool **matrizAux, int linhas){
    for(int i = 0; i < linhas; i++){
        delete[] matriz[i];
        delete[] matrizAux[i];
    }

    delete[] matriz;
    delete[] matrizAux;
}

void gerarMatrizes(bool **&matriz, bool **&matrizAux, int linhas, int colunas){
    matriz = new bool*[linhas];
    matrizAux = new bool*[linhas];

    for(int i = 0; i < linhas; i++){
        matriz[i] = new bool[colunas];
        matrizAux[i] = new bool[colunas];
    }
}

void calcularGeracao(bool **matriz, bool **matrizAux, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                int vizinhosVivos = qtdVizinhosVivos(matriz, linhas, colunas, i, j);

                if(matriz[i][j])
                    matrizAux[i][j] = !(vizinhosVivos < 2 || vizinhosVivos > 3);
                else
                    matrizAux[i][j] = vizinhosVivos == 3;
            }
    }
}

void gerarArquivosResultado(bool **matriz, int linhas, int colunas, int geracao){
    std::ofstream arquivo;
    std::string nomeArquivo = "geracoes.mps";
    arquivo.open(nomeArquivo, std::ios::app);

    if(arquivo.is_open()){
        int qtdVivos = contarQtdVivos(matriz, linhas, colunas);

        if(geracao == 0){
            arquivo << "Jogo da Vida - Tamanho da matriz: " << linhas << "x" << colunas << std::endl << std::endl;
        }

        arquivo << "Razão entre vivos e mortos (V/M): (" << qtdVivos << "/" << (linhas*colunas - qtdVivos) << ")" << std::endl;
        arquivo << "Geração ";
        geracao ? arquivo << geracao : arquivo << "Inicial";
        arquivo << std::endl;

        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                arquivo << matriz[i][j] << " ";
            }
            arquivo << std::endl;
        }

        arquivo << std::endl;

        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo\n";
    }
}

int contarQtdVivos(bool **matriz, int linhas, int colunas){
    int qtdVivos = 0;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            if(matriz[i][j])
                qtdVivos++;
        }
    }

    return qtdVivos;
}

int qtdVizinhosVivos(bool **matriz, int linhas, int colunas, int i, int j){
    int qtdVizinhosVivos = 0;
    int esquerda = j - 1;
    int direita = j + 1;
    int cima = i - 1;
    int baixo = i + 1;

    if(esquerda != -1 && cima != -1){
        if(matriz[cima][esquerda])
            qtdVizinhosVivos++;
    }

    if(cima != -1){
        if(matriz[cima][j])
            qtdVizinhosVivos++;
    }

    if(direita != colunas && cima != -1){
        if(matriz[cima][direita])
            qtdVizinhosVivos++;
    }

    if(esquerda != -1){
        if(matriz[i][esquerda])
            qtdVizinhosVivos++;
    }

    if(direita != colunas){
        if(matriz[i][direita])
            qtdVizinhosVivos++;
    }

    if(esquerda != -1 && baixo != linhas){
        if(matriz[baixo][esquerda])
            qtdVizinhosVivos++;
    }

    if(baixo != linhas){
        if(matriz[baixo][j])
            qtdVizinhosVivos++;
    }

    if(direita != colunas && baixo != linhas){
        if(matriz[baixo][direita])
            qtdVizinhosVivos++;
    }

    return qtdVizinhosVivos;
}