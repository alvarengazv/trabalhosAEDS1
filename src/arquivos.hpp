#ifndef ARQUIVOS_HPP
#define ARQUIVOS_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <iomanip>
#include <filesystem>
#include <map>
#include <ctime>

#define MIN_LINHAS 10
#define MAX_LINHAS 15 
#define MIN_NUMEROS 5
#define MAX_NUMEROS 15

void gerarArquivosNumeros(int qtdArquivos);
void gerarArquivosProcessos(int qtdArquivosProcessos, int qtdArquivosNumeros);
void leituraLinhaProcesso(std::string nomeArquivo, std::map<std::string, double> &resultadosProcessos, std::map<std::string, double> &temposProcessos);
void gerarArquivoSaida(std::string nomeArquivo, double resultado, std::string nomeProcesso);
void gerarArquivoResultados(std::map<std::string, double> resultadosProcesso, std::map<std::string, double> temposProcesso, int qtdProcessos);
std::string leituraLinhaArquivoNumero(std::string diretorioArquivo);
int contarArquivosProcessos(const std::string& diretorio, const std::string& substring);

#endif