<a name="readme-topo"></a>

<div align='center'>
  <img src='imgs/banner.png'>
</div>

<h1 align='center'>
  Jogo da Vida
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
    Sumário
  </b>
  </summary>
  <ol>
    <li><a href="#Introdução">Introdução</a></li>
    <li><a href="#Fundamentação-Teórica">Fundamentação Teórica</a></li>
    <li><a href="#Objetivos">Objetivos</a></li>
    <li>
      <a href="#Metodologia">Metodologia</a>
      <ul>
        <li><a href='#Arquivos'>Arquivos</a></li>
        <li><a href='#Bibliotecas'>Bibliotecas</a></li>
        <li><a href='#Funções'>Funções</a></li>
        <li><a href='#Detalhes-de-Implementação'>Detalhes de Implementação</a></li>
      </ul>
    </li>
    <li><a href="#Testes-e-Resultados-Esperados">Testes e Resultados Esperados</a></li>
    <li><a href="#Conclusão">Conclusão</a></li>
    <li>
      <a href="#Começando">Começando</a>
      <ul>
        <li><a href="#Pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#Instalação-e-Execução">Instalação e Execução</a></li>
      </ul>
    </li>
    <li><a href="#Ambiente-de-Compilação/Execução">Ambiente de Compilação/Execução</a></li>
    <li><a href="#Referências">Referências</a></li>
    <li><a href="#Contato">Contato</a></li>
  </ol>
</details>


## Introdução

<div align="justify">

Este [trabalho][trabalho-url] (TP Aquecimento) foi proposto na disciplina de Algoritmos e Estruturas de Dados I (AEDSI) pelo professor [Michel Pires da Silva][github-prof].

Simplificadamente, o trabalho consiste numa implementação computacional do autômato celular chamado de Jogo da Vida (do inglês, [Game of Life][livroJV-url][^2]). O conceito por trás deste jogo foi criado no ano de 1970 pelo matemático John Horton Conway (1937-2020), que foi mundialmente reconhecido por realizar outras contribuições matemáticas ao meio.

A implementação computacional proposta consiste, basicamente, na manipulação de elementos de uma matriz de duas dimensões e de tamanho mínimo 5x5, com seus valores variando entre 1 ou 0 (verdadeiro ou falso/vivo ou morto). Seus elementos devem estar inicialmente dispostos numa proporção de 2 para 1 para os valores de 0 e 1, respectivamente. Isto é, deve haver o dobro de células mortas em relação às vivas na matriz inicial. Com tudo isso preparado, o jogo se inicia seguindo um conjunto de regras simples - que serão apresentadas nas seções subsequentes - e continua pela quantidade de gerações indicadas pelo usuário.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Fundamentação Teórica

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Objetivos

<div align="justify">

A principal finalidade do [trabalho prático de aquecimento][trabalho-url] é rever conceitos básicos que serão muito utilizados no decorrer da disciplina no 1º Semestre de 2024. Através desses fundamentos, deve-se resolver a problemática proposta: simular computacionalmente o Jogo Da Vida[^2]. Abaixo estão os principais conceitos necessários:

  - Controle de entradas e saídas de arquivos;
  - Manipulação de matrizes de duas dimensões;
  - Criação de arquivos de cabeçalho e bibliotecas;
  - Organização de código e boas práticas de programação.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Metodologia

### Arquivos

<div align="justify">

Para a solução proposta os seguintes diretórios/arquivos foram utilizados: 

  - [`datasets/input.mps`][input-ref]: arquivo em que se encontra a matriz de entrada para o programa;
  - [`src/main.cpp`][main-ref]: arquivo em que se encontra a função `main()` que executa comandos cruciais do programa;
  - [`src/jogoDaVida.hpp`][hppJV-ref]: arquivo em que se encontra as assinaturas das funções utilizadas e importações de bibliotecas padrão;
  - [`src/jogoDaVida.cpp`][cppJV-ref]: arquivo em que se encontra as implementações das funções utilizadas;
  - [`geracoes.mps`][output-ref]: arquivo em que se encontra as saídas geradas pelo programa a cada execução;
  - [`exemplosMatrizes.txt`][exemplos-ref]: arquivo em que se encontra as matrizes utilizadas para testes;
  - [`makefile`][makefile]: arquivo com os comandos para a compilação e execução do programa.

### Bibliotecas

A seguir estão as bibliotecas incluídas no programa e que são essenciais para o funcionamento dele.

  - `"jogoDaVida.hpp"`: biblioteca criada pelo autor com funções essenciais para o programa;
  - `<iostream>`: biblioteca utilizada para as operações de entrada e saída;
  - `<fstream>`: biblioteca utilizada para manipular a leitura e escrita nos arquivos [`datasets/input.mps`][input-ref] e [`geracoes.mps`][output-ref];
  - `<sstream>`: biblioteca utilizada para armazenar cada linha do arquivo de entrada como uma `istringstream`, que permite a conversão de `string` para `int`, além de separar a string para a utilização do operador `>>`. 

### Funções

Abaixo estão as funções essenciais para o funcionamento do programa. Com a finalidade de simplificar a escrita, os parâmetros de cada uma delas foram ocultados.

  - `int main()`: função principal do programa que cria variáveis e faz chamadas de funções importantes para o programa;
  - `int qtdVizinhosVivos()`: função que calcula e retorna a quantidade de vizinhos vivos da posição da matriz indicada;
  - `int numeroGeracoes()`: função que pergunta ao usuário e retorna o número total de gerações do jogo;
  - `int contarQtdVivos()`: função que calcula e retorna a quantidade de células vivas na matriz;
  - `void getTamanho()`: função que obtém o tamanho (número de linhas e colunas) da matriz ao ler o arquivo de entrada [`datasets/input.mps`][input-ref];
  - `void controladorJogoDaVida()`: função controladora do Jogo da Vida, responsável por gerenciar as iterações do jogo;
  - `void calcularGeracao()`: função que calcula a próxima geração do Jogo da Vida com base na configuração atual da matriz;
  - `void mostraMatriz()`: função que mostra a matriz na tela;
  - `void leituraMatrizArquivo()`: função que lê os valores da matriz do arquivo de entrada [`datasets/input.mps`][input-ref];
  - `void gerarArquivosResultado()`: função que gera o arquivo de resultado [`geracoes.mps`][output-ref] (se necessário) e adiciona ao final dele a matriz de cada geração do jogo;
  - `void gerarMatrizes()`: função que gera a matriz principal e a auxiliar do mesmo tamanho, necessárias para o funcionamento do programa;
  - `void deletarMatrizes()`: função que deleta as matrizes alocadas dinamicamente;
  - `void copiarMatriz()`: função que copia o conteúdo de uma matriz para outra.

### Detalhes de Implementação


  #### 1. Primeira Leitura do Arquivo

  - A primeira função executada pelo programa é a função `int main()` em que, inicialmente, cria-se as variáveis `int linhas` e `int colunas`. Após isso há a chamada da função `void getTamanho()`, em que o arquivo de entrada [`datasets/input.mps`][input-ref] é lido a fim de se conseguir obter quantidade de linhas e de colunas da matriz. Essas duas variáveis são passadas por referência como parâmetros para a função para que possa ser utilizada no resto do programa após receberem os valores. 

  #### 1.1 Caso de saída antecipada do programa

  - Caso a quantidade de linhas ou de colunas seja menor que 5, o programa mostra a mensagem "A matriz deve ter no mínimo 5x5" no terminal e para de ser executado.

  #### 2. Criação das matrizes

  - Duas variáveis `bool **matriz` e `bool **matrizAux` foram criadas e são "ponteiros para ponteiros" de um tipo booleano*. Isto é, são capazes de representar uma matriz bidimensional com valores 0 ou 1. Após isso, ambas as matrizes são alocadas dinamicamente com a chamada de função `void gerarMatrizes()` e, em seguida, os valores da matriz de entrada do arquivo [`datasets/input.mps`][input-ref] são posicionados na variável `matriz`.

*O tipo booleano foi escolhido pois os valores da matriz sempre representarão o estado vivo ou morto, ou seja, 1 ou 0 (verdadeiro ou falso).

  #### 3. Parte principal do Jogo da Vida

  - Aqui, a função `void controladorJogoDaVida()` é chamada na função `int main()` e realiza as seguintes operações:
    - Com a chamada da função `int numeroGeracoes()` pergunta ao usuário a quantidade de gerações que ele deseja que sejam calculadas;
    - Inicializa a variável `geracao` com valor 0 para acompanhar o número de gerações processadas;
    - Inicia um loop `do-while` que continuará até que todas as gerações desejadas tenham sido calculadas;
    - Imprime na saída padrão o estado atual do jogo da vida, indicando a geração atual ou se é a geração inicial;
    - Com a chamada da função `int contarQtdVivos()` calcula e com o valor retornado imprime a razão entre células vivas e células mortas na matriz;
    - Com a chamada da função `void mostraMatriz()` mostra a matriz na saída padrão;
    - Com a chamada da função `void gerarArquivosResultado()` que gera o arquivo de resultado [`geracoes.mps`][output-ref] (se necessário) e adiciona ao final dele a matriz de cada geração do jogo;
    - Com a chamada da função `void calcularGeracao()` calcula a próxima geração do Jogo da Vida;
    - Copia a nova geração para a matriz original para continuar o processo de cálculo através da chamada da função `void copiarMatriz()`;
    - Repete o processo até que o número total de gerações especificado seja alcançado.

  #### 4. Liberar o espaço na memória

  - Ao finalizar todas as operações necessárias para a saída do resultado final, na função `int main()` há uma chamada da função `void deletarMatrizes()`, que ao receber as variáveis das matrizes como parâmetros, desaloca-as e consequentemente libera espaço na memória. Após isso, o programa é finalizado e retorna 0. 

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Testes e Resultados Esperados

### 1. Testes seguindo a razão de 2 para 1

#### 1.1 Matriz 5x5

Geração Inicial

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 |

Caso seja requisitado que sejam calculadas oito gerações, elas devem ser impressas na saída da seguinte maneira: 

<table>
<tr><th>Geração 1</th>
<th>Geração 2</th>
<th>Geração 3</th>
<th>Geração 4</th>
<tr><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |

</td>
<tr><th>Geração 5</th>
<th>Geração 6</th>
<th>Geração 7</th>
<th>Geração 8</th>
<tr><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 0 | 1 | 0 | 0 |

</td><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 |

</td></tr> </table>

Neste caso, após oito gerações o padrão inicial se desenvolveu até chegar no ponto em que todas as células se encontram mortas. 

#### 1.2 Matriz 6x6

Geração Inicial:

|   |   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 | 1 | 1 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 | 0 | 1 |
| 0 | 0 | 0 | 0 | 0 | 0 |

Caso seja requisitado que sejam calculadas quatro gerações, elas devem ser impressas na saída da seguinte maneira:

<table>
<tr><th>Geração 1</th>
<th>Geração 2</th>
<th>Geração 3</th>
<th>Geração 4</th>
<tr><td>

|   |   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 1 | 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 1 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 1 | 0 | 1 |
| 0 | 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |

</td><td>

|   |   |   |   |   |   |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 0 | 0 | 0 |

</td></tr> 
</table>

Neste caso, apesar da matriz ser maior e da razão de células vivas e mortas continuar a mesma, bastou apenas quatro gerações para o padrão inicial se desenvolver até chegar no ponto em que todas as células se encontram mortas. 

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>


## Conclusão



<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Começando

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

<!-- Ensinar a clonar a pasta do repositório -->
1. Clone a _branch_ [`JogoDaVida`][branchJV-url] do repositório no diretório desejado:
  ```console
  git clone -b JogoDaVida https://github.com/alvarengazv/trabalhosAEDS1.git
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

## Ambiente de Compilação/Execução

> [!IMPORTANT] 
> Para que os testes tenham validade, considere as especificações técnicas do computador utilizado

O trabalho foi desenvolvido, compilado e executado em um ambiente com as seguintes especificações:

<div align='center'>

![Ubuntu][ubuntu-badge]
![Ryzen][ryzen-badge]
![Lenovo][lenovo-badge]

SO | CPU | RAM
--- | --- | ---
Ubuntu 22.04.4 LTS | Ryzen 5 5500U 2.1GHz | 2x4GB 3200MHz

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Referências

GARDNER, M. **Mathematical games:** the fantastic combinations of John Conway’s new solitaire game “life”, Scientific American 223:120–123, 1970.

JOHNSTON, N; GREENE, D. **Conway's Game of Life:** Mathematics and Construction. [_S.l.: s.n._], 2022. _E-book_. Disponível em: https://conwaylife.com/book/conway_life_book.pdf. Acesso em: 29 mar. 2024.

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Contato

<div align="center">
   <i>Guilherme Alvarenga de Azevedo - 3º Período de Engenharia de Computação @ CEFET-MG</i>
<br><br>

[![Gmail][gmail-badge]][gmail-autor]
[![Linkedin][linkedin-badge]][linkedin-autor]
[![Github][github-badge]][github-autor]
</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>


[^1]: JOHNSTON, N; GREENE, D. **Conway's Game of Life:** Mathematics and Construction. [_S.l.: s.n._], 2022. _E-book_. Disponível em: https://conwaylife.com/book/conway_life_book.pdf. Acesso em: 29 mar. 2024.

[^2]: GARDNER, M. **Mathematical games:** the fantastic combinations of John Conway’s new solitaire game “life”, Scientific American 223:120–123, 1970.

[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp
[trabalho-url]: https://drive.google.com/file/d/1Y7qkA7pisIWjmh77S078_xkbtndmSPZn/view?usp=sharing
[github-prof]: https://github.com/mpiress
[livroJV-url]: https://conwaylife.com/book/conway_life_book.pdf
[input-ref]: datasets/input.mps
[main-ref]: src/main.cpp
[hppJV-ref]: src/jogoDaVida.hpp
[cppJV-ref]: src/jogoDaVida.cpp
[output-ref]: geracoes.mps
[exemplos-ref]: exemplosMatrizes.txt
[branchJV-url]: https://github.com/alvarengazv/trabalhosAEDS1/tree/JogoDaVida
[makefile]: ./makefile
[bash-url]: https://www.hostgator.com.br/blog/o-que-e-bash/
[lenovo-badge]: https://img.shields.io/badge/lenovo%20laptop-E2231A?style=for-the-badge&logo=lenovo&logoColor=white
[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white
[ryzen-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_5500U-ED1C24?style=for-the-badge&logo=amd&logoColor=white
[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[linkedin-autor]: https://www.linkedin.com/in/guilherme-alvarenga-de-azevedo-959474201/
[github-badge]: https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white
[github-autor]: https://github.com/alvarengazv
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white
[gmail-autor]: mailto:gui.alvarengas234@gmail.com
