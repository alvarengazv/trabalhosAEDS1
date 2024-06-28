#include "controlador.hpp"

int main(){
    srand(time(NULL));

    int escolha = 0;

    while(escolha != 3){
        escolha = menu();
        system("clear || cls");

        controladorEscolha(escolha);
    }

    return 0;
}