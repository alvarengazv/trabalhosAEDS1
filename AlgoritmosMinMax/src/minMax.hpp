#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <string>

void controladorMinMax(int *&vetor, int n, int &min, int &max, int *tamanhos, std::string nomeArquivo);
void mudarOrdem(int *&vetor, int n, int ordem);
void encontraMediaMinMax1(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo, std::string &stringMedia1);
void minMax1(int *&vetor, int n, int &min, int &max);
void encontraMediaMinMax2(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo, std::string &stringMedia2);
void minMax2(int *&vetor, int n, int &min, int &max);
void encontraMediaMinMax3(int *&vetor, int n, int &min, int &max, int tamanho, int ordem, std::ofstream& arquivo, std::string &stringMedia3);
void minMax3(int *&vetor, int n, int &min, int &max);
void preencheVetor(int *&vetor, int n);
void mostraVetor(int *vetor, int n);
int particionaCrescente(int *&vetor, int inicio, int fim);
void quicksortOrdenacaoCrescente(int *&vetor, int inicio, int fim);
int particionaDecrescente(int *&vetor, int inicio, int fim);
void quicksortOrdenacaoDecrescente(int *&vetor, int inicio, int fim);
double calculaMedia(double soma);

#endif