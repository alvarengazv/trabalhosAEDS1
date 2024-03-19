#ifndef JOGODAVIDA_HPP
#define JOGODAVIDA_HPP

#include <iostream>
#include <fstream>
#include <sstream>

int qtdVizinhosVivos(bool **matriz, int linhas, int colunas, int i, int j);
int numeroGeracoes();
int contarQtdVivos(bool **matriz, int linhas, int colunas);
void getTamanho(int &linhas, int &colunas);
void controladorJogoDaVida(bool **matriz, bool **matrizAux, int linhas, int colunas);
void calcularGeracao(bool **matriz, bool **matrizAux, int linhas, int colunas);
void mostraMatriz(bool **matriz, int linhas, int colunas);
void leituraMatrizArquivo(bool **matriz, int linhas, int colunas);
void gerarArquivosResultado(bool **matriz, int linhas, int colunas, int geracao);
void gerarMatrizes(bool **&matriz, bool **&matrizAux, int linhas, int colunas);
void deletarMatrizes(bool **matriz, bool **matrizAux, int linhas);

#endif