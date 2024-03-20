#include "minMax.hpp"

void controladorMinMax(int *&vetor, int n, int &min, int &max, int *tamanhos){    
    std::ofstream arquivo;
    std::string linha;
    arquivo.open("medias.csv", std::ios::app);

    if(arquivo.is_open()){
        for(int i = 0; i < 4; i++){
            preencheVetor(vetor, tamanhos[i]);
            arquivo << "TAMANHO: " << tamanhos[i] << " ELEMENTOS." << std::endl;

            for(int j = 0; j < 3; j++){
                mudarOrdem(vetor, tamanhos[i], j);
                std::string ordemString = (j == 0 ? "ALEATÓRIA" : (j == 1 ? "CRESCENTE" : "DECRESCENTE"));

                arquivo << "ORDEM: " << ordemString << "." << std::endl;

                encontraMediaMinMax1(vetor, tamanhos[i], min, max, i, j, arquivo);
                encontraMediaMinMax2(vetor, tamanhos[i], min, max, i, j, arquivo);
                encontraMediaMinMax3(vetor, tamanhos[i], min, max, i, j, arquivo);
            }

            arquivo << "\t";
        }
    }

    delete vetor;
}

void mudarOrdem(int *&vetor, int n, int ordem){
    switch (ordem){
        case 1:
            ordenaCrescente(vetor, n);
            break;
        case 2:
            ordenaDecrescente(vetor, n);
            break;
    }
}

void encontraMediaMinMax1(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo){
    double soma = 0;
    arquivo << std::endl << "Média MinMax1" << std::endl;
    arquivo << "Valores:" << std::endl;

    for(int i = 0; i < 10; i++){
        auto inicio = std::chrono::high_resolution_clock::now();
        minMax1(vetor, n, min, max);
        auto final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
        arquivo << "t" << i+1 << ": " << tempoExec.count() << std::endl;
        soma += tempoExec.count();
    }

    arquivo << "Média: " << calculaMedia(soma) << std::endl;

    std::cout << "Média 1/" << (tamanho+1) << "/" << ordem << ": " << calculaMedia(soma) << "ms" << std::endl;
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

void encontraMediaMinMax2(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo){
    double soma = 0;
    arquivo << std::endl << "Média MinMax2" << std::endl;
    arquivo << "Valores:" << std::endl;

    for(int i = 0; i < 10; i++){
        auto inicio = std::chrono::high_resolution_clock::now();
        minMax2(vetor, n, min, max);
        auto final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
        arquivo << "t" << i+1 << ": " << tempoExec.count() << std::endl;
        soma += tempoExec.count();
    }

    arquivo << "Média: " << calculaMedia(soma) << std::endl;

    std::cout << "Média 2/" << (tamanho+1) << "/" << ordem <<  ": " << calculaMedia(soma) << "ms" << std::endl;
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

void encontraMediaMinMax3(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo){
    double soma = 0;
    arquivo << std::endl << "Média MinMax2" << std::endl;
    arquivo << "Valores:" << std::endl;

    for(int i = 0; i < 10; i++){
        auto inicio = std::chrono::high_resolution_clock::now();
        minMax3(vetor, n, min, max);
        auto final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempoExec = (final - inicio);
        arquivo << "t" << i+1 << ": " << tempoExec.count() << std::endl;
        soma += tempoExec.count();
    }

    arquivo << "Média: " << calculaMedia(soma) << std::endl;

    std::cout << "Média 3/" << (tamanho+1) << "/" << ordem << ": " << calculaMedia(soma) << "ms" << std::endl;
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

    for(int i = 2; i < fimDoAnel; i+=2){
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

double calculaMedia(double soma){
    return soma/10;
}

void ordenaCrescente(int *&vetor, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(vetor[i] > vetor[j]){
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ordenaDecrescente(int *&vetor, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(vetor[i] < vetor[j]){
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}