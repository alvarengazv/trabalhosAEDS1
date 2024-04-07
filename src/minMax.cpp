#include "minMax.hpp"

void controladorMinMax(int *&vetor, int n, int &min, int &max, int *tamanhos, std::string nomeArquivo){    
    std::ofstream arquivo;
    std::string linha, stringMedia1, stringMedia2, stringMedia3;
    arquivo.open(nomeArquivo);
    int t = 1;
    arquivo << "# Algoritmo,Ordenação do Vetor,Tamanho do vetor (n),";

    while (t <= 10){
        arquivo << "t" << t << " (ms)" << ",";
        t++;
    }

    arquivo << "Média (ms),Min,Max" << std::endl;

    if(arquivo.is_open()){
        for(int i = 0; i < 4; i++){
            preencheVetor(vetor, tamanhos[i]);

            for(int j = 0; j < 3; j++){
                mudarOrdem(vetor, tamanhos[i], j);

                encontraMediaMinMax1(vetor, tamanhos[i], min, max, i, j, arquivo, stringMedia1);
                encontraMediaMinMax2(vetor, tamanhos[i], min, max, i, j, arquivo, stringMedia2);
                encontraMediaMinMax3(vetor, tamanhos[i], min, max, i, j, arquivo, stringMedia3);
                //arquivo << std::endl;
            }
        }

        arquivo << stringMedia1 << stringMedia2 << stringMedia3;

        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo" << std::endl;
    }

    delete vetor;
}

void mudarOrdem(int *&vetor, int n, int ordem){
    switch (ordem){
        case 1:
            quicksortOrdenacaoCrescente(vetor, 0, n - 1);
            break;
        case 2:
            quicksortOrdenacaoDecrescente(vetor, 0, n - 1);
            break;
    }
}

void encontraMediaMinMax1(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo, std::string &stringMedia1){
    double soma = 0;
    std::string ordemString = (ordem == 0 ? "Aleatória" : (ordem == 1 ? "Crescente" : "Decrescente"));
    stringMedia1 += "MinMax1," + ordemString + "," + std::to_string(n) + ",";

    //arquivo << "MinMax1," << ordemString << "," << n << ",";

    for(int i = 0; i < 10; i++){
        auto inicio = std::chrono::high_resolution_clock::now();
        minMax1(vetor, n, min, max);
        auto final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
        //arquivo << tempoExec.count() << ",";
        stringMedia1 += std::to_string(tempoExec.count()) + ",";
        soma += tempoExec.count();
    }

    stringMedia1 += std::to_string(calculaMedia(soma)) + "," + std::to_string(min) + "," + std::to_string(max) + "\n";

    //arquivo << calculaMedia(soma) << "," << min << "," << max << std::endl;

    std::cout << "Média 1/" << (tamanho+1) << "/" << ordem << ": " << calculaMedia(soma) << "ms" << std::endl;
    mostraVetor(vetor, n);
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

void encontraMediaMinMax2(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo, std::string &stringMedia2){
    double soma = 0;
    std::string ordemString = (ordem == 0 ? "Aleatória" : (ordem == 1 ? "Crescente" : "Decrescente"));

    //arquivo << "MinMax2," << ordemString << "," << n << ",";
    stringMedia2 += "MinMax2," + ordemString + "," + std::to_string(n) + ",";

    for(int i = 0; i < 10; i++){
        auto inicio = std::chrono::high_resolution_clock::now();
        minMax2(vetor, n, min, max);
        auto final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
        //arquivo << tempoExec.count() << ",";
        stringMedia2 += std::to_string(tempoExec.count()) + ",";
        soma += tempoExec.count();
    }

    //arquivo << calculaMedia(soma) << "," << min << "," << max << std::endl;
    stringMedia2 += std::to_string(calculaMedia(soma)) + "," + std::to_string(min) + "," + std::to_string(max) + "\n";

    std::cout << "Média 2/" << (tamanho+1) << "/" << ordem <<  ": " << calculaMedia(soma) << "ms" << std::endl;
    mostraVetor(vetor, n);
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

void encontraMediaMinMax3(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo, std::string &stringMedia3){
    double soma = 0;
    std::string ordemString = (ordem == 0 ? "Aleatória" : (ordem == 1 ? "Crescente" : "Decrescente"));

    //arquivo << "MinMax3," << ordemString << "," << n << ",";
    stringMedia3 += "MinMax3," + ordemString + "," + std::to_string(n) + ",";

    for(int i = 0; i < 10; i++){
        auto inicio = std::chrono::high_resolution_clock::now();
        minMax3(vetor, n, min, max);
        auto final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
        //arquivo << tempoExec.count() << ",";
        stringMedia3 += std::to_string(tempoExec.count()) + ",";
        soma += tempoExec.count();
    }

    //arquivo << calculaMedia(soma) << "," << min << "," << max << std::endl;
    stringMedia3 += std::to_string(calculaMedia(soma)) + "," + std::to_string(min) + "," + std::to_string(max) + "\n";

    std::cout << "Média 3/" << (tamanho+1) << "/" << ordem << ": " << calculaMedia(soma) << "ms" << std::endl;
    mostraVetor(vetor, n);
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
        vetor[i] = rand() % 1000 + 1;
}

void mostraVetor(int *vetor, int n){
    for(int i = 0; i < 20; i++)
        std::cout << vetor[i] << " ";
    std::cout << std::endl;
}

//Método de ordenação QuickSort para ordenar o vetor em ordem crescente 
int particionaCrescente(int *&vetor, int inicio, int fim) {
    int pivot = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return (i + 1);
}

void quicksortOrdenacaoCrescente(int *&vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionaCrescente(vetor, inicio, fim);

        quicksortOrdenacaoCrescente(vetor, inicio, pi - 1);
        quicksortOrdenacaoCrescente(vetor, pi + 1, fim);
    }
}

//Método de ordenação QuickSort para ordenar o vetor em ordem decrescente 
int particionaDecrescente(int *&vetor, int inicio, int fim) {
    int pivot = vetor[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] > pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;

    return (i + 1);
}

void quicksortOrdenacaoDecrescente(int *&vetor, int inicio, int fim) {
    if (inicio < fim) {
        int pi = particionaDecrescente(vetor, inicio, fim);

        quicksortOrdenacaoDecrescente(vetor, inicio, pi - 1);
        quicksortOrdenacaoDecrescente(vetor, pi + 1, fim);
    }
}

double calculaMedia(double soma){
    return soma/10;
}