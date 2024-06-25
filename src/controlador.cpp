#include "controlador.hpp"
#include "arquivos.hpp"

void controladorEscolha(int escolha){
    switch(escolha){
        case 1:{
            int qtdArquivosNumeros = entradaNumero("Digite a quantidade de arquivos de numeros: ");
            gerarArquivosNumeros(qtdArquivosNumeros);
            gerarArquivosProcessos(entradaNumero("Digite a quantidade de arquivos de processos: "), qtdArquivosNumeros);
            break;
        }
        case 2:{
            int qtdProcessosUsuario = 0;
            int qtdProcessos = contarArquivosProcessos("datasets/", "P");
            do{
                qtdProcessosUsuario = entradaNumero("Digite a quantidade de processos: ");
                if(qtdProcessosUsuario > qtdProcessos)
                    std::cout << "Quantidade de processos maior que a quantidade de processos existentes" << std::endl;
                else if(qtdProcessosUsuario <= 0)
                    std::cout << "Quantidade de processos inválida" << std::endl;
                
            } while (qtdProcessosUsuario > qtdProcessos || qtdProcessosUsuario <= 0);
            
            executarProcessos(qtdProcessosUsuario);

            break;
        }
        case 3:
            std::cout << "Saindo..." << std::endl;
            break;
        default:
            std::cout << "Opção inválida" << std::endl;
            break;
    }
}

void executarProcessos(int qtdProcessos){
    std::map<std::string, double> resultadosProcessos;
    std::map<std::string, double> temposProcessos;

    for(int i = 1; i <= qtdProcessos; i++){
        leituraLinhaProcesso("P" + std::to_string(i), resultadosProcessos, temposProcessos);
        std::cout << "Processo " << i << std::endl;
        std::cout << std::fixed << std::setprecision(6) << "Resultado: " << resultadosProcessos.at("P" + std::to_string(i)) << std::endl;
    }
    
    gerarArquivoResultados(resultadosProcessos, temposProcessos, qtdProcessos);
}

int menu(){
    std::cout << "1 - Gerar arquivos" << std::endl;
    std::cout << "2 - Executar Processos" << std::endl;
    std::cout << "3 - Sair" << std::endl;
    std::cout << "Digite a opção desejada: ";
    int opcao;
    std::cin >> opcao;
    
    return opcao;
}

int entradaNumero(std::string mensagem){
    int numero;
    std::cout << mensagem;
    std::cin >> numero;
    return numero;
}

std::pair<std::string, double> executarLinhaProcesso(std::string linha){
    std::stringstream streamLinha(linha);
    std::string stringNumero;
    std::vector<std::string> elementosLinha;
    std::vector<int> numerosLinha;
    long unsigned int i = 0;

    while(std::getline(streamLinha, stringNumero, ',')){
        elementosLinha.push_back(stringNumero);
        if(i > 0)
            numerosLinha.push_back(std::stoi(stringNumero));
        i++;
    }
    //sort(numerosLinha.begin(), numerosLinha.end());

    double resultadoLinhaProcesso = 0;

    for(i = 0; i < numerosLinha.size(); i++){
        std::string numero;
        if(numerosLinha[i] < 10)
            numero = '0' + std::to_string(numerosLinha[i]);
        else
            numero = std::to_string(numerosLinha[i]);
        
        std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");
        resultadoLinhaProcesso += calcularResultadoArquivoNumero(linhaArquivo);
    }

    return std::make_pair(elementosLinha[0], resultadoLinhaProcesso);
}

double calcularResultadoArquivoNumero(std::string linhaArquivo){
    std::stringstream streamLinha(linhaArquivo);
    std::string stringNumero;
    std::vector<std::string> elementosLinha;
    double resultado = 0;

    while(std::getline(streamLinha, stringNumero, ',')){
        resultado += sqrt(std::stof(stringNumero));
    }

    return resultado;
}