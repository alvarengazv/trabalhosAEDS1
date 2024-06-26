#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <vector>

#define VERSION 2.1

void controladorEscolha(int escolha);
void executarProcessos(int qtdProcessos);
int menu();
int entradaNumero(std::string mensagem);
std::pair<std::string, double> executarLinhaProcesso(std::string linha);
double calcularResultadoArquivoNumero(std::string linhaArquivo);

#endif