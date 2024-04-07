#include "minMax.hpp"

int main(){
    srand(time(NULL));
    std::string nomeArquivo = "output/csv/medias.csv";
    int tamanhos[4] = {1000, 10000, 100000, 500000};

    int n = tamanhos[0];
    
    int *vetor;
    int min, max;
    controladorMinMax(vetor, n, min, max, tamanhos, nomeArquivo);

    const char* command = "gnuplot -persist -e \"load 'src/mediasMinMax.p'\"";

    FILE* pipe = popen(command, "r");
    if (!pipe) {
        std::cerr << "Erro! Não foi possível abrir um pipe para o gnuplot" << std::endl;
        return 1;
    }

    pclose(pipe);

    return 0;
}