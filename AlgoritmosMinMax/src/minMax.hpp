#ifndef MINMAX_HPP
#define MINMAX_HPP

#include <iostream>
#include <random>
#include <chrono>

void controladorMinMax(int *&vetor, int n, int &min, int &max, int *tamanhos);
void minMax1(int *&vetor, int n, int &min, int &max);
void minMax2(int *&vetor, int n, int &min, int &max);
void minMax3(int *&vetor, int n, int &min, int &max);
void encontraMediaMinMax1(int *&vetor, int n, int &min, int &max, int tamanho, int ordem);
void encontraMediaMinMax2(int *&vetor, int n, int &min, int &max, int tamanho, int ordem);
void encontraMediaMinMax3(int *&vetor, int n, int &min, int &max, int tamanho, int ordem);
void mudarOrdem(int *&vetor, int n, int ordem);
void mostraVetor(int *vetor, int n);
void preencheVetor(int *&vetor, int n);
void ordenaCrescente(int *&vetor, int n);
void ordenaDecrescente(int *&vetor, int n);
void deletaVetor(int *&vetor);
double calculaMedia(double soma);


#endif