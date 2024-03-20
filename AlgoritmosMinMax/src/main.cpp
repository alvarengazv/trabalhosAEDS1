#include "minMax.hpp"

int main(){
    srand(time(NULL));
    int tamanhos[4] = {1000, 10000, 100000, 500000};

    int n = tamanhos[0];
    
    int *vetor;
    int min, max;
    controladorMinMax(vetor, n, min, max, tamanhos);

    return 0;
}