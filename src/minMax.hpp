#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>

#define QTDEXECUCOES 10

void controladorMinMax(std::string nomeArquivo);
void mudarOrdem(int *&vetor, int n, int ordem);
void encontraMediaMinMaxGeral(int *&vetor, int n, int &min, int &max, int ordem, std::string *stringsMinmax);
void minMax1(int *&vetor, int n, int &min, int &max);
void minMax2(int *&vetor, int n, int &min, int &max);
void minMax3(int *&vetor, int n, int &min, int &max);
void preencheVetor(int *&vetor, int n);
void geraGraficos();
int particionaCrescente(int *&vetor, int inicio, int fim);
void quickSortOrdenacaoCrescente(int *&vetor, int inicio, int fim);
int particionaDecrescente(int *&vetor, int inicio, int fim);
void quickSortOrdenacaoDecrescente(int *&vetor, int inicio, int fim);

#endif