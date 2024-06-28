<a name="readme-topo"></a>

<div align='center'>
  <img src='#' width='350'>
</div>

<h1 align='center'>
  Lista 1 - Problema 11 - Processos & Leitura/Escrita de Arquivos
</h1>

<div align='center'>

[![IDE][vscode-badge]][vscode-url]
[![Make][make-badge]][make-url]
[![Linguagem][cpp-badge]][cpp-url]

Algoritmos e Estruturas de Dados I

</div>

<details>
  <summary>
  <b style='font-size: 15px'>
    📑 Sumário
  </b>
  </summary>
  <ol>
    <li><a href="#-Introdução">🔍 Introdução</a></li>
    <li>
      <a href="#-Objetivos">🎯 Objetivos</a>
      <ul>
        <li><a href='#Objetivo-Geral'>Objetivo Geral</a></li>
        <li><a href='#Objetivos-Específicos'>Objetivos Específicos</a></li>
      </ul>
    </li>
    <li>
      <a href="#-Metodologia">🔬 Metodologia</a>
      <ul>
        <li><a href='#Arquivos'>Arquivos</a></li>
        <li><a href='#Bibliotecas'>Bibliotecas</a></li>
        <li><a href='#Funções'>Funções</a></li>
      </ul>
    </li>
    <li>
      <a href="#-Testes-e-Análises-dos-Resultados">📊 Testes e Análises dos Resultados</a>
    </li>
    <li><a href="#-Conclusão">🏁 Conclusão</a></li>
    <li>
      <a href="#-Começando">🔨 Começando</a>
      <ul>
        <li><a href="#Pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#Instalando">Instalando</a></li>
      </ul>
    </li>
    <li><a href="#-Ambiente-de-Compilação-e-Execução">🧪 Ambiente de Compilação e Execução</a></li>
    <li><a href="#-Referências">📚 Referências</a></li>
    <li><a href="#-Contato">📨 Contato</a></li>
  </ol>
</details>


## 🔍 Introdução

<div align="justify">

Este [exercício][trabalho-url] (Lista 1 - Problema 11) foi proposto na disciplina de Algoritmos e Estruturas de Dados I (AEDSI) pelo professor [Michel Pires da Silva][github-prof].

O problema consiste na representação de um sistema computacional que faz o controle de processos. Estes últimos são representados por arquivos no diretório [datasets][dts], seguindo o padrão de nome $Px.txt$, com x podendo ser variável. Cada um desses arquivos de texto terão um número $n$ de linhas da forma < $L_{n}$, 04, 07, 01, 01, 07, 06, ... , 03 >, em que $L_{n}$ representa a linha $n$ do processo e os números subsequentes são os números de arquivos necessários para a execução da linha em questão. Estes arquivos enumerados, também localizados no diretório [datasets][dts], possuem $100.000$ números de ponto flutuante aleatórios, variando de $1 a 1.000.000$. Estes arquivos de números são nomeados no formato 04.txt, 07.txt, ..., 03.txt e serão indicados em quantidades variáveis nos arquivos de processos, que também possuem quantidades de linhas variáveis.

O usuário indicará um número inteiro de processos, então, caso indique 5, os arquivos $P1.txt, P2.txt, P3.txt, P4.txt, P5.txt$ deverão ser abertos e seus "processos" executados. Como limitação, cada linha só poderá ser executada assim que a última já tiver terminado.

A execução em questão, consiste em abrir os arquivos indicados na linha e calcular a soma da raiz quadrada de todos os valores neles contidos. Após isso, deve-se subtrair o resultado da próxima linha do valor encontrado na linha "atual". Ao se chegar a um resultado para cada processo, esses valores devem compor um arquivo chamado output.txt, também contido no diretório [datasets][dts].

Após o término do programa, o aluno deve realizar uma análise do tempo de execução e trazer uma discussão sobre possíveis otimizações para o algoritmo.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🎯 Objetivos

<div align="justify">

  ### Objetivo Geral
  
  O objetivo deste trabalho envolve o desenvolvimento de um algoritmo que represente um sistema computacional e uma discussão sobre formas de otimizá-lo. 

  ### Objetivos Específicos

  - Analisar que tipo de melhorias podem ser realizadas para minimizar o tempo de execução de um programa.

  - Pesquisar e entender como possíveis otimizações em um código podem influenciar no seu custo computacional geral, isto é, seu uso de memória, de processador e de outros recursos disponíveis. 

  - Descobrir e compreender que tipo de otimizações podem compensar um uso maior de recursos com um tempo de execução muito satisfatório.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔬 Metodologia

<div align="justify">

### Arquivos

Para a solução proposta os seguintes diretórios/arquivos foram utilizados: 

  - [`datasets/P*.txt`][dts]: arquivos que representam os processos do sistema;
  - [`datasets/*.txt`][dts]: arquivos que contêm os números para a execução dos processos;
  - [`datasets/output*.txt`][dts]: arquivos que contêm os números que representam os resultados de cada processo para cada versão do programa;
  - [`datasets/temposDeExecucao-versao****.txt`][dts]: arquivos que contêm os tempos de execução de cada processo para cada versão do programa;
  - [`datasets/testeMedio](datasets/testeMedio): diretório para armazenar um teste médio para a versão mais otimizada do programa;
  - [`datasets/testeMedio](datasets/testePesado): diretório para armazenar um teste pesado para a versão mais otimizada do programa;
  - [`src/main.cpp`][main-ref]: arquivo em que se encontra a função `main()` que executa comandos cruciais do programa;
  - [`src/arquivos.cpp`][cppArquivos-ref]: arquivo em que se encontra as implementações das funções utilizadas para realizar operações com arquivos (leitura/escrita das linhas);
  - [`src/arquivos.hpp`][hppArquivos-ref]: arquivo em que se encontra as assinaturas das funções utilizadas para realizar operações com arquivos e importações de bibliotecas padrão;
  - [`src/controlador.cpp`][cppControlador-ref]: arquivo em que se encontra as implementações das funções utilizadas para controlar toda a execução do programa (menu, escolhas do usuário e cálculos necessários);
  - [`src/controlador.hpp`][hppControlador-ref]: arquivo em que se encontra as assinaturas das funções utilizadas para controlar toda a execução do programa e importações de bibliotecas padrão;
  - [`makefile`][makefile]: arquivo com os comandos para a compilação e execução do programa.

### Bibliotecas

A seguir estão as bibliotecas incluídas no programa e que são essenciais para o funcionamento dele.

  - `"arquivos.hpp"`: biblioteca criada pelo autor com funções essenciais para o programa ler e escrever em arquivos;
  - `"controlador.hpp"`: biblioteca criada pelo autor com funções essenciais para o programa executar os cálculos necessários;
  - `<iostream>`[^3]: biblioteca utilizada para as operações de entrada e saída;
  - `<fstream>`[^3]: biblioteca utilizada para manipular a escrita nos arquivos [`output/csv/medias.csv`][medias-ref] e [`output/csv/mediasPC.csv`][mediasPC-ref];
  - `<random>`[^3]: biblioteca utilizada para gerar os números aleatórios para preencher os vetores de entrada para os algoritmos;
  - `<chrono>`[^3]: biblioteca utilizada para calcular, em ms, o tempo de execução de cada algoritmo MinMax;
  - `<string>`[^3]: biblioteca utilizada para utilizar o tipo de variável _string_, para facilitar a geração de resultados nos arquivos de saída.
  - `<bits/stdc++.h>`[^3]: biblioteca utilizada para utilizar, principalmente, a função `sqrt()` sem precisar incluir a biblioteca `<cmath>`.
  - `<map>`[^3]: biblioteca utilizada para utilizar o tipo de variável _map_, para facilitar no armazenamento dos resultados.
  - `<vector>`[^3]: biblioteca utilizada para utilizar o tipo de variável _vector_, para facilitar no armazenamento dos resultados.
  - `<iomaip>`[^3]: biblioteca utilizada para utilizar funções que permitam a manipulação de variáveis para serem mostradas em _strings_ (variáveis como a representação do dia e horário atuais e a precisão de _floats/doubles_).
  - `<filesystem>`[^3]: biblioteca utilizada para fazer a contagem de arquivos de processo existentes no diretório [datasets][dts].
  - `<ctime>`[^3]: biblioteca utilizada para determinar o dia e horário atuais.

### Funções

Abaixo estão as funções essenciais para o funcionamento do programa. Com a finalidade de simplificar a escrita, os parâmetros de cada uma delas foram ocultados.

  - `int main()`: função principal do programa que cria a variável de escolha e faz a chamada das funções `menu()` e `controladorEscolha()`;
  
  - `int menu()`: esta função serve para mostrar ao usuário as opções disponíveis para a execução do programa e retorna a alternativa escolhida;

  - `void controladorEscolha()`: esta função atua como um controlador para direcionar o programa para o ponto certo de acordo com a escolha do usuário;

  - `int entradaNumero()`: esta função pergunta ao usuário o número desejado para determinada ocasião e retorna este valor inteiro;

  - `void gerarArquivosNumeros()`: esta função gera a quantidade de arquivos de números de acordo com o número indicado pelo usuário e os valores dados pelo enunciado do exercício, com uma lógica para gerar números _float_ aleatórios e colocá-los separados por ", " nos arquivos;
  
  - `void gerarArquivosProcessos()`: esta função gera a quantidade de arquivos de processos de acordo com o número indicado pelo usuário e com quantidades de linhas e números por linha variando de acordo com as constantes criadas biblioteca [`src/arquivos.hpp`][hppArquivos-ref];
  
  - `int contarArquivosProcessos()`: esta função conta e retorna a qunatidade de arquivos de processo no diretório [datasets][dts];

  - `void executarProcessos()`: esta função serve para executar os processos, calcular seus resultados e gerar um arquivo de saída com os tempos de execução (chamando as funções separadamente);

  - `void leituraLinhaProcesso()`: esta função serve para realizar a leitura linha a linha de cada processo, calcular seus resultados e tempos de execução e armazenar o resultado no arquivo de saída `output.txt` (chamando as funções separadamente);
  
  - `std::string leituraLinhaArquivoNumero()`: esta função serve para realizar a leitura dos valores _float_ de um determinado arquivo de números da pasta [datasets][dts];

  - `double calcularResultadoArquivoNumero()`: esta função serve para realizar o cálculo da soma das raízes de um determinado arquivo de números;

  - `std::pair<std::string, double> executarLinhaProcesso()`: esta função serve para executar, calcular e retornar o resultado para cada linha de um determinado processo;

  - `void gerarArquivoSaida()`: esta função serve para gerar o arquivo de saída `output.txt` com o resultado do último processo realizado ou adicionar este valor no arquivo já existente;

  - `void gerarArquivoResultados()`: esta função serve para gerar o arquivo de saída que contém os tempos de execução para cada linha e processo e o tempo total de execução;

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 📊 Testes e Análises dos Resultados

<div  align="justify">



</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🏁 Conclusão

<div  align="justify">



</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🔨 Começando

Nesta seção estão exemplificados os meios através dos quais se tornam possíveis a compilação e execução do programa apresentado.

### Pré-requisitos

Inicialmente, algumas considerações importantes sobre como se deve preparar o ambiente para compilar e executar o programa:

> [!NOTE]
> Recomenda-se usar uma distribuição de sistema operacional Linux ou o Windows Subsystem for Linux (WSL), pois os comandos no [`makefile`][makefile] foram selecionados para funcionar em um ambiente [_shell/bash_][bash-url].

Considerando um ambiente _shell_, garanta que os seguintes comandos já foram executados:
  - Atualize os pacotes antes da instalação dos compiladores:
  ```console
  sudo apt update
  ```
  - Instale a coleção de compiladores ___GNU/g++___ e o ___make___:
  ```console
  sudo apt install build-essential
  ```
  - Se necessário, instale o ___make___ individualmente:
  ```console
  sudo apt install make
  ```

### Instalando

Com o ambiente preparado, os seguintes passos são para a instalação, compilação e execução do programa localmente:

1. Clone a _branch_ [`Lista1Problema11`][branchL1P11-url] do repositório no diretório desejado:
  ```console
  git clone -b Lista1Problema11 https://github.com/alvarengazv/trabalhosAEDS1.git
  cd trabalhosAEDS1
  ```
2. Compile o programa com o ___make___, o que gera a pasta `build`, que contém arquivos de objeto e um arquivo executável:
  ```console
  make
  ```
3. Execute o programa da pasta `build` após a compilação:
  ```console
  make run
  ```

4. Se necessário, apague a última compilação da pasta `build`:
  ```console
  make clean
  ```

O programa estará pronto para ser testado.

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🧪 Ambiente de Compilação e Execução

> [!IMPORTANT] 
> Para que os testes tenham validade, considere as especificações técnicas do computador utilizado

O trabalho foi desenvolvido, compilado e executado no ambiente com as configurações especificadas no quadro abaixo:

<div align='center'>

![Ubuntu][ubuntu-badge]
![Ryzen][ryzen5500-badge]
![Lenovo][lenovo-badge]

SO | Compilador | CPU | RAM | Dispositivo de Armazenamento 
--- | --- | --- | --- | ---
Ubuntu 24.04 LTS | g++ (Ubuntu 13.2.0-23ubuntu4) 13.2.0 | Ryzen 5 5500U 2.1GHz | 2x4GB 3200MHz | SSD M.2 NVME 256GB (3500MB/s de Leitura x 1200MB/s de Escrita) 

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 📚 Referências

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 📨 Contato

<div align="center">
   <i>Guilherme Alvarenga de Azevedo - Graduando - 3º Período de Engenharia de Computação @ CEFET-MG</i>
<br><br>

[![Gmail][gmail-badge]][gmail-autor]
[![Linkedin][linkedin-badge]][linkedin-autor]
[![Telegram][telegram-badge]][telegram-autor]
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

[^3]: C++ Reference. **CPPReference**, 2017. Disponível em: https://en.cppreference.com/w/cpp. Acesso em: 10 abr. 2024.

[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp

[trabalho-url]: https://drive.google.com/file/d/1GrQSlq6e1nKbm7AoaXgnPn_7Q08f6yIN/view?usp=sharing
[github-prof]: https://github.com/mpiress

[dts]: ./datasets
[main-ref]: src/main.cpp
[cppArquivos-ref]: src/arquivos.cpp
[hppArquivos-ref]: src/arquivos.hpp
[cppControlador-ref]: src/controlador.cpp
[hppControlador-ref]: src/controlador.hpp
[makefile]: ./makefile

[bash-url]: https://www.hostgator.com.br/blog/o-que-e-bash/
[branchL1P11-url]: https://github.com/alvarengazv/trabalhosAEDS1/tree/Lista1Problema11
[lenovo-badge]: https://img.shields.io/badge/lenovo%20laptop-E2231A?style=for-the-badge&logo=lenovo&logoColor=white
[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white
[ryzen5500-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_5500U-ED1C24?style=for-the-badge&logo=amd&logoColor=white

[linkedin-autor]: https://www.linkedin.com/in/guilherme-alvarenga-de-azevedo-959474201/
[telegram-autor]: https://t.me/alvarengazv
[gmail-autor]: mailto:gui.alvarengas234@gmail.com
[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[telegram-badge]: https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white