#include "arquivos.hpp"
#include "controlador.hpp"

void gerarArquivosNumeros(int qtdArquivos){
    for(int i = 1; i <= qtdArquivos; i++){
        std::string diretorioArquivo = "datasets/";
        if(i < 10){
            diretorioArquivo += "0";
        }
        diretorioArquivo += std::to_string(i) + ".txt";

        std::ofstream arquivo(diretorioArquivo);

        if(arquivo.is_open()){
            for(int j = 1; j <= 100000; j++){
                float numero = ((rand() % 1000000) + 1) + (((rand() % 10000) + 1000 )/ 10000.0);
                
                arquivo << std::setprecision(13) << numero << (j == 100000 ? "" : ", ");
            }
        }else{
            std::cout << "Erro ao abrir o arquivo 1" << std::endl;
        }

        arquivo.close();
    }
}

void gerarArquivosProcessos(int qtdArquivosProcessos, int qtdArquivosNumeros){
    for(int i = 1; i <= qtdArquivosProcessos; i++){
        std::string diretorioArquivo = "datasets/";

        diretorioArquivo += "P" + std::to_string(i) + ".txt";

        std::ofstream arquivo(diretorioArquivo);

        if(arquivo.is_open()){
            int qtdLinhas = (rand() % (MAX_LINHAS - MIN_LINHAS + 1)) + MIN_LINHAS;
            for(int j = 1; j <= qtdLinhas; j++){
                int qtdNumeros = (rand() % (MAX_NUMEROS - MIN_NUMEROS + 1)) + MIN_NUMEROS;
                arquivo << "L" << j << ", ";

                for(int k = 1; k <= qtdNumeros; k++){
                    int numero = (rand() % qtdArquivosNumeros) + 1;
                    
                    arquivo << (numero < 10 ? "0" : "") << numero << (k == qtdNumeros ? "\n" : ", ");
                }
            }
        }else{
            std::cout << "Erro ao abrir o arquivo 2" << std::endl;
        }

        arquivo.close();
    }
}

int contarArquivosProcessos(const std::string& diretorio, const std::string& substring) {
    int qtd = 0;
    for (const auto& arquivo : std::filesystem::directory_iterator(diretorio)) {
        if (arquivo.is_regular_file() && arquivo.path().filename().string().find(substring) != std::string::npos) {
            ++qtd;
        }
    }
    return qtd;
}

void leituraLinhaProcesso(std::string nomeArquivo, std::map<std::string, double> &resultadosProcessos, std::map<std::string, double> &temposProcessos){
    std::ifstream arquivo("datasets/" + nomeArquivo + ".txt");
    double resultado = 0;
    std::pair<std::string, double> resultadoLinha;

    if(arquivo.is_open()){
        std::string linha;
        while(getline(arquivo, linha)){
            auto inicio = std::chrono::high_resolution_clock::now();
            resultadoLinha = executarLinhaProcesso(linha);
            auto fim = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> tempoTotal = fim - inicio;
            temposProcessos.emplace(nomeArquivo + "-" + resultadoLinha.first, tempoTotal.count());

            if(!resultadoLinha.first.compare("L1"))
                resultado += resultadoLinha.second;
            else 
                resultado -= resultadoLinha.second;
        }
        resultadosProcessos.emplace(nomeArquivo + "-qtdLinhas", std::stoi(resultadoLinha.first.substr(1)));
        gerarArquivoSaida("output", resultado, nomeArquivo);
        resultadosProcessos.emplace(nomeArquivo, resultado);
    }else{
        std::cout << "Erro ao abrir o arquivo 3" << std::endl;
    }

    arquivo.close();
}

std::string leituraLinhaArquivoNumero(std::string diretorioArquivo){
    std::ifstream arquivo(diretorioArquivo);
    std::string linhaArquivo;

    if(arquivo.is_open()){
        getline(arquivo, linhaArquivo);
    }else{
        std::cout << diretorioArquivo << std::endl;
        std::cout << "Erro ao abrir o arquivo 4" << std::endl;
    }

    arquivo.close();

    return linhaArquivo;
}

void gerarArquivoSaida(std::string nomeArquivo, double resultado, std::string nomeProcesso){
    std::ofstream arquivo;
    // se for o processo "P1", cria um novo arquivo
    if(!nomeProcesso.compare("P1"))
        arquivo.open("datasets/" + nomeArquivo + ".txt");
    else
        arquivo.open("datasets/" + nomeArquivo + ".txt", std::ios::app);

    if(arquivo.is_open()){
        arquivo << std::fixed << std::setprecision(6) << resultado << std::endl;
    }else{
        std::cout << "Erro ao abrir o arquivo 5" << std::endl;
    }

    arquivo.close();
}

void gerarArquivoResultados(std::map<std::string, double> resultadosProcesso, std::map<std::string, double> temposProcesso, int qtdProcessos){
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::stringstream buffer;
    buffer << std::put_time(&tm, "%d-%m-%Y-%H:%M:%S");
    std::string dateTime(buffer.str());
    std::string diretorioArquivo = "datasets/temposDeExecucao-versao" + std::to_string(VERSION) + "-" + dateTime + ".txt";
    std::ofstream arquivo(diretorioArquivo);

    if(arquivo.is_open()){
        double tempoTotal = 0;
        arquivo << "Versão " << VERSION << " - " << dateTime << std::endl;
        for(int i = 1; i <= qtdProcessos; i++){
            double tempoTotalProcesso = 0;
            arquivo << "Processo P" << i << std::endl;
            arquivo << "Resultado: " << std::fixed << std::setprecision(6) << resultadosProcesso.at("P" + std::to_string(i)) << std::endl;
            for(int j = 1; j <= resultadosProcesso.at("P" + std::to_string(i) + "-qtdLinhas"); j++){
                tempoTotalProcesso += temposProcesso.at("P" + std::to_string(i) + "-L" + std::to_string(j));
                arquivo << "Tempo de execução L" << j << ": " << std::fixed << std::setprecision(6) << temposProcesso.at("P" + std::to_string(i) + "-L" + std::to_string(j)) << "s" << std::endl;
            }
            arquivo << "Tempo de execução total do processo P" << std::to_string(i) << ": " << tempoTotalProcesso << "s" << std::endl;
            arquivo << std::endl << std::endl;
            tempoTotal += tempoTotalProcesso;
        }
        arquivo << "Tempo de execução total dos processos: " << tempoTotal << "s" << std::endl;
    }else{
        std::cout << "Erro ao abrir o arquivo 6" << std::endl;
    }
}