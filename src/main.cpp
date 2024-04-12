#include "minMax.hpp"

int main(){
    srand(time(NULL));
    std::string nomeArquivo = "output/csv/medias.csv";
    
    controladorMinMax(nomeArquivo);
    geraGraficos();

    return 0;
}