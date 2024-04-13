#include "minMax.hpp"

void controladorMinMax(std::string nomeArquivo){
    int tamanhos[4] = {1000, 10000, 100000, 500000};
    int *vetor, min, max, t = 1;

    std::ofstream arquivo;
    std::string *stringsMinmax = new std::string[3];
    
    arquivo.open(nomeArquivo);

    if(arquivo.is_open()){
        arquivo << "# Algoritmo,Ordenação do Vetor,Tamanho do vetor (n),";

        while (t <= QTDEXECUCOES){
            arquivo << "t" << t << " (ms)" << ",";
            t++;
        }

        arquivo << "Média (ms),Min,Max" << std::endl;
        for(int i = 0; i < 4; i++){
            preencheVetor(vetor, tamanhos[i]);

            for(int j = 0; j < 3; j++){
                mudarOrdem(vetor, tamanhos[i], j);

                encontraMediaMinMaxGeral(vetor, tamanhos[i], min, max, j, stringsMinmax);
            }
        }

        arquivo << stringsMinmax[0] << stringsMinmax[1] << stringsMinmax[2];

        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
    }

    delete vetor;
}

void mudarOrdem(int *&vetor, int n, int ordem){
    switch (ordem){
        case 1:
            quickSortOrdenacaoCrescente(vetor, 0, n - 1);
            break;
        case 2:
            quickSortOrdenacaoDecrescente(vetor, 0, n - 1);
            break;
    }
}

void encontraMediaMinMaxGeral(int *&vetor, int n, int &min, int &max, int ordem, std::string *stringsMinmax){
    double soma = 0;
    std::string ordemString = (ordem == 0 ? "Aleatória" : (ordem == 1 ? "Crescente" : "Decrescente"));
    int alg = 0;

    while(alg < 3){
        stringsMinmax[alg] += "MinMax" + std::to_string((alg+1)) + "," + ordemString + "," + std::to_string(n) + ",";

        for(int i = 0; i < QTDEXECUCOES; i++){
            auto inicio = std::chrono::high_resolution_clock::now();
            switch (alg){
                case 0:
                    minMax1(vetor, n, min, max);
                    break;
                case 1:
                    minMax2(vetor, n, min, max);
                    break;
                case 2:
                    minMax3(vetor, n, min, max);
                    break;
            }
            auto final = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
            stringsMinmax[alg] += std::to_string(tempoExec.count()) + ",";
            soma += tempoExec.count();
        }
        stringsMinmax[alg] += std::to_string(soma/QTDEXECUCOES) + "," + std::to_string(min) + "," + std::to_string(max) + "\n";
        soma = 0;

        alg++;
    }
    
}

void minMax1(int *&vetor, int n, int &min, int &max){
    max = vetor[0];
    min = vetor[0];

    for(int i = 1; i < n; i++){
        if(vetor[i] > max)
            max = vetor[i];
        if(vetor[i] < min)
            min = vetor[i];   
    }
}

void minMax2(int *&vetor, int n, int &min, int &max){
    max = vetor[0];
    min = vetor[0];
    
    for(int i = 1; i < n; i++){
        if(vetor[i] > max)
            max = vetor[i];
        else if(vetor[i] < min)
            min = vetor[i];
    }
}

void minMax3(int *&vetor, int n, int &min, int &max){
    int fimDoAnel = 0; 

    if(n % 2 > 0){
        vetor[n] = vetor[n-1];
        fimDoAnel = n;
    } else 
        fimDoAnel = n-1;

    if(vetor[0] > vetor[1]){
        max = vetor[0];
        min = vetor[1];
    } else {
        max = vetor[1];
        min = vetor[0];
    }

    int i = 2;
    while(i < fimDoAnel){
        if(vetor[i] > vetor[i+1]){
            if(vetor[i] > max)
                max = vetor[i];
            if(vetor[i+1] < min)
                min = vetor[i+1];
        } else {
            if(vetor[i+1] > max)
                max = vetor[i+1];
            if(vetor[i] < min)
                min = vetor[i];
        }
        i += 2;
    }
}

void preencheVetor(int *&vetor, int n){
    vetor = new int[n];
    for(int i = 0; i < n; i++)
        vetor[i] = rand() % 1001;
}

void geraGraficos(){
    const char* command = "gnuplot -persist -e \"load 'src/mediasMinMax.p'\"";

    FILE* pipe = popen(command, "r");
    if (!pipe) {
        std::cerr << "Erro! Não foi possível abrir um pipe para o gnuplot" << std::endl;
        return;
    }

    pclose(pipe);
}

int particionaCrescente(int *&vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1), aux;

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;

    return (i + 1);
}

void quickSortOrdenacaoCrescente(int *&vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionaCrescente(vetor, inicio, fim);

        quickSortOrdenacaoCrescente(vetor, inicio, pivo - 1);
        quickSortOrdenacaoCrescente(vetor, pivo + 1, fim);
    }
}

int particionaDecrescente(int *&vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1), aux;

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] > pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;

    return (i + 1);
}

void quickSortOrdenacaoDecrescente(int *&vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionaDecrescente(vetor, inicio, fim);

        quickSortOrdenacaoDecrescente(vetor, inicio, pivo - 1);
        quickSortOrdenacaoDecrescente(vetor, pivo + 1, fim);
    }
}