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
      <ul>
        <li><a href="#Versão-1">Versão 1</a></li>
        <li>
          <a href="#Versões-2-e-2-1">Versões 2 e 2.1</a>
          <ul>
            <li><a href="#1-Versão-Principal">1. Versão Principal</a></li>
            <li><a href="#2-Versão-Alternativa">2. Versão Alternativa</a></li>
          </ul>
        </li>
        <li><a href="#Versão-3">Versão 3</a></li>
        <li><a href="#Versão-4">Versão 4</a></li>
        <li><a href="#Interpretação-dos-Resultados-e-Primeiras-Conclusões">Interpretação dos Resultados e Primeiras Conclusões</a></li>
      </ul>
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

A solução proposta se divide em 4 principais versões do programa, a serem comparadas em termos de custo computacional e eficiência ao calcular os resultados dos processos solicitados. 

As funções custo da execução principal do programa dependem primariamente do seguinte método:

```cpp
// sendo a = qtdProcessos
// sendo b = qtd de bytes lidos em cada linha (qtdArquivos/linha)
// sendo d = qtd de arquivos solicitados na linha
// sendo n = qtd de linhas do processo (qtdLinhas/Processo)
// b e d são proporcionais, entao b = d

void executarProcessos(int qtdProcessos){
  std::map<std::string, double> resultadosProcessos;    // -> Custo: constante (1) 
  std::map<std::string, double> temposProcessos;        // -> Custo: constante (1)

  for(int i = 1; i <= qtdProcessos; i++){               // -> Custo: Qtd de elementos = a - 0 + 1 = a + 1; Comparações/Atribuições = 2 p/ execução, ou seja: 2*(a+1)
      leituraLinhaProcesso("P" + std::to_string(i), resultadosProcessos, temposProcessos);     // -> Custo: (a)*(custo da função de acordo com a versão)
      std::cout << "Processo " << i << std::endl;       // -> Custo: (a)*(1)
      std::cout << std::fixed << std::setprecision(6) << "Resultado: " << resultadosProcessos.at("P" + std::to_string(i)) << std::endl;    // -> Custo: (a)*(1)
  }
  
  gerarArquivoResultados(resultadosProcessos, temposProcessos, qtdProcessos);   // -> Custo: qtdBytes escritos (depende da quantidade de processos e linhas)
}
// 2a - for
// a(2bn + nlog(n) + 2log(a)) - todo a execução principal do processo
// 2a - saídas cout
// a*n - aproximadamente a quantidade de Bytes escritos
// = 2a + a*2bn + a*n*log(n) + a*2log(a) + 2a + a*n
// Ignorando constantes e funções com crescimento menor:
// Total = 2abn + an + anlog(n) + a2log(a)
```

Para determinar o custo real de $O(2abn + an + an\log(n) + 2a\log(a))$, deve-se conhecer o custo do método `void leituraLinhaProcesso()`, que depende da quantidade de linhas e arquivos por linha no processo em questão. Além disso, em cada versão do código ele possui uma função de custo diferente. O principal bloco de código que influencia no seu custo é composto pelo `while-loop` ao se ler as linhas do processo.

### Versão 1

Na primeira versão do algoritmo, a função `void leituraLinhaProcesso()` possuia os seguintes custos por comandos:

```cpp
// sendo c = qtd de bytes escritos 
std::string linha;                                               // -> Custo: constante (1)
std::pair<std::string, double> resultadoLinha;                   // -> Custo: constante (1)

while(getline(arquivo, linha)){                                  // -> Custo: b*n
    auto inicio = std::chrono::high_resolution_clock::now();     // -> Custo: n*(1)
    resultadoLinha = executarLinhaProcesso(linha);               // -> Custo: n*(custo da função de acordo com a versão)
    auto fim = std::chrono::high_resolution_clock::now();        // -> Custo: n*(1)
    std::chrono::duration<double> tempoTotal = fim - inicio;     // -> Custo: n*(1)
    temposProcessos.emplace(nomeArquivo + "-" + resultadoLinha.first, tempoTotal.count());            // -> Custo: n*log(n)  - quantidade de linhas nos processos

    if(!resultadoLinha.first.compare("L1"))                      // -> Custo: n*(1)
        resultado += resultadoLinha.second;                      // -> Custo -- somados = n*1
    else                                                         //          --
        resultado -= resultadoLinha.second;                      // -> Custo -- somados = n*1
}
resultadosProcessos.emplace(nomeArquivo + "-qtdLinhas", std::stoi(resultadoLinha.first.substr(1)));   // -> Custo: log(a) - quantidade de processos executados
gerarArquivoSaida("output", resultado, nomeArquivo);             // -> Custo: c
resultadosProcessos.emplace(nomeArquivo, resultado);             // -> Custo: log(a) - quantidade de processos executados

// b*n -while
// n*(d) - calcular resultado
// 3n - tempos
// nlog(n) - adicionar ao map de tempos
// 2n - if-else
// log(a) - adicionar ao map de resultados
// c - escrita no arquivo (constante, pois é sempre um float com 6 casas decimais)
// log(a) - adicionar ao map de resultados
// = bn + nb + 5n + nlog(n) + c + 2log(a)
// Ignorando constantes e funções com crescimento menor:
// Total = 2bn + nlog(n) + 2log(a)

```

Ademais, para encontrar o custo total buscado, deve-se calcular o custo do método `pair<string, double> executarLinhaProcesso()`, e é nele onde a maior parte das mudanças entre as versões do algoritmo estarão explícitas.

```cpp
std::pair<std::string, double> executarLinhaProcesso(std::string linha){
    std::stringstream streamLinha(linha);                      // -> Custo: constante (1)
    std::string stringNumero;                                  // -> Custo: constante (1)
    std::vector<std::string> elementosLinha;                   // -> Custo: constante (1)
    std::vector<int> numerosLinha;                             // -> Custo: constante (1)
    long unsigned int i = 0;                                   // -> Custo: constante (1)

    while(std::getline(streamLinha, stringNumero, ',')){       // -> Custo: d + 1
        elementosLinha.push_back(stringNumero);                // -> Custo: d + 1
        if(i > 0)                                              // -> Custo: d + 1
            numerosLinha.push_back(std::stoi(stringNumero));   // -> Custo: d
        i++;                                                   // -> Custo: d + 1
    }

    double resultadoLinhaProcesso = 0.0;                       // -> Custo: constante (1)

    for(i = 0; i < numerosLinha.size(); i++){        // -> Custo: Qtd de elementos = d - 0 + 1 = d + 1; Comparações/Atribuições = 2 p/ execução, ou seja: 2*(d + 1)
        std::string numero;                                    // -> Custo: (d)*(1)
        if(numerosLinha[i] < 10)                               // -> Custo: (d)*(1)
            numero = '0' + std::to_string(numerosLinha[i]);    // -> Custo -- somados = (d)*(1)
        else                                                   //          -- 
            numero = std::to_string(numerosLinha[i]);          // -> Custo -- somados = (d)*(1)
        
        std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");    // -> Custo: (d)*(constante de 100000 números lidos do arquivo)
        resultadoLinhaProcesso += calcularResultadoArquivoNumero(linhaArquivo);                 // -> Custo: (d)*(custo da função que calcula a raiz dos 100000 números e suas somas)
    }

    return std::make_pair(elementosLinha[0], resultadoLinhaProcesso);     // -> Custo: constante (1)
}
//5d - while
//2d - for
//3d - criação da string numero
//100000d - leitura da linha dos 100000 números do arquivo
//d - cálculo das raízes e somas
// = 100011d
// Total: 100011d -> O(d)
```

Por fim, a função que calcula a soma das raízes dos números de um mesmo arquivo:

```cpp
double calcularResultadoArquivoNumero(std::string linhaArquivo){
    std::stringstream streamLinha(linhaArquivo);               // -> Custo: constante (1)
    std::string stringNumero;                                  // -> Custo: constante (1)
    std::vector<std::string> elementosLinha;                   // -> Custo: constante (1)
    double resultado = 0;                                      // -> Custo: constante (1)

    while(std::getline(streamLinha, stringNumero, ',')){       // -> Custo: constante (100000)
        resultado += sqrt(std::stof(stringNumero));            // -> Custo: constante 100000*(log(x))
    }

    return resultado;                                          // -> Custo: constante (1)
}
// Total: 100000 -> O(1)
```

Com cada um dos custos encontrados, podemos somar seus valores e encontrar uma função de complexidade de tempo para a primeira versão do programa. Por uma questão de simplificação, todos os custos de tempo constantes serão desconsiderados. Com isso, encontra-se a expressão de custo: $C(a, b, n) = abn + an + an\log(n) + 2a\log(a)$, sendo:
 - $a$ - quantidade de processos solicitados
 - $b$ - quantidade de arquivos em cada linha do processos
 - $n$ - quantidade de linhas dos processos

Como todas essas são variáveis, é possível considerar que todas sejam iguais e tenham seus valores tendendo a infinito. Assim, com $a = b = n$, nosso algoritmo atinge um custo de: $C(n) = 2n^{3} + n^{2} + n^2\log(n) + 2n\log(n)$. Visivelmente, a classe assintótica que domina a função $C(n)$ é $\mathcal{O}(n^3)$, caso o número de processos, arquivos e linhas por processo tenham valores proporcionais e cada vez maiores.

Ao executar o programa com 5 processos, 5 arquivos de números, 5-10 arquivos por linha e 10-15 linhas por processo, a versão 1 do programa, segundo dados do [arquivo de tempo de execução da versão 1](./datasets/temposDeExecucao-versao1-25-06-2024-18-19-56.txt), estava demorando entre  de $0,08$ a $0,24$ para executar cada linha dos processos. Com isso, cada processo estava levando entre $1,5$ e $2,0 s$ para terminar e, no total, o programa finalizou sua execução em cerca de **$8,7 s$**.

### Versões 2 e 2.1

Nessa versão, as únicas alterações ocorreram na função `executarLinhaProcesso()`, em que se tinha o objetivo de não abrir e recalcular, para uma mesma linha, arquivos que já haviam sido considerados.

###### 1. Versão principal

Primeiramente, foram adicionadas as seguintes variáveis antes do ciclo principal de abertura de arquivos e cálculo:

```cpp
int max = *std::max_element(numerosLinha.begin(), numerosLinha.end());
double resultadosArquivos[max] = {0.0};
```

A variável `max` serve para descobrir qual o maior número de arquivo da linha para posteriormente se criar um vetor `resultadosArquivos`, que precisará de, no máximo, `max` posições (todas iniciadas em 0).

Após isso, o ciclo principal da função foi substituído por:

```cpp
if(resultadosArquivos[numerosLinha[i] - 1] == 0.0){
  std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");
  double resultadoArquivo = calcularResultadoArquivoNumero(linhaArquivo);
  resultadosArquivos[numerosLinha[i] - 1] = resultadoArquivo;
}
resultadoLinhaProcesso += resultadosArquivos[numerosLinha[i] - 1];
```

Com essa alteração, a abertura dos arquivos e os cálculos apenas serão realizados caso o valor na posição do vetor referente ao número do arquivo em questão seja igual a 0. A função de custo do algoritmo no pior caso não teve mudança já que, caso nenhum arquivo se repita na mesma linha, todos deverão ser abertos e executados. Já para casos como o testado, em que a quantidade de arquivos total não é maior que a quantidade de arquivos por linha, isto é, eles repetem, essa mudança causa uma melhoria de eficiência drástica.

Em média, sempre haverão arquivos repetidos nas linhas dos processos. Com isso, observando os resultados para o mesmo teste da versão 1, no [arquivo gerado para a versão 2](./datasets/temposDeExecucao-versao2-26-06-2024-18-16-35.txt), cada linha dos processos estava levando entre $0,05$ e $0,089 s$ para executar. Consequentemente, houve uma diminuição do tempo por processo, que passou a demorar de $0,7$ a $0,89 s$ e o tempo total de execução diminuiu, em média, um pouco mais de 2 vezes em relação à primeira versão, chegando a $3,84 s$. 

###### 2. Versão alternativa

Nessa versão, a estrutura `if` da versão 2 estava composta, também, pela parte do código que cria o nome do arquivo (o que deveria ter sido realizado desde o início para evitar execuções de código desnecessárias):

```cpp
if(resultadosArquivos[numerosLinha[i] - 1] == 0.0){
    std::string numero;
    if(numerosLinha[i] < 10)
        numero = '0' + std::to_string(numerosLinha[i]);
    else
        numero = std::to_string(numerosLinha[i]);

    std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");
    double resultadoArquivo = calcularResultadoArquivoNumero(linhaArquivo);
    resultadosArquivos[numerosLinha[i] - 1] = resultadoArquivo;
}
```

Como esperado, essa execução não teve tanta diferença para a versão 2 principal, tendo ainda, um ínfimo aumento no tempo de execução total, que passou para cerca de $3,97 s$. Porém, em média, essa alteração não fez diferença para o teste realizado - algo que poderia fazer alguma diferença caso $n$ fosse muito grande.  

### Versão 3

Já na versão 3, foi idealizada uma maneira de evitar repetições no curso de execução das linhas dos processos, mas que não necessitasse da mesma quantidade de memória que a versão 2 (o vetor adicional de $n$ posições). A ideia consiste em ordenar o vetor que contém os números dos arquivos da linha e, reutilizar o último valor calculado até o número do arquivo se alterar.

As mudanças foram a criação da variável `resultadoAnterior` para armazenar o último valor calculado, e a mudança do ciclo principal do programa para:

```cpp
if(i > 0){
    if(numerosLinha[i] != numerosLinha[i - 1]){
        std::string numero;
        if(numerosLinha[i] < 10)
            numero = '0' + std::to_string(numerosLinha[i]);
        else
            numero = std::to_string(numerosLinha[i]);

        std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");
        double resultadoArquivo = calcularResultadoArquivoNumero(linhaArquivo);
        resultadoAnterior = resultadoArquivo;
    }
} else {
    std::string numero;
    if(numerosLinha[i] < 10)
        numero = '0' + std::to_string(numerosLinha[i]);
    else
        numero = std::to_string(numerosLinha[i]);

    std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");
    double resultadoArquivo = calcularResultadoArquivoNumero(linhaArquivo);
    resultadoAnterior = resultadoArquivo;
}
resultadoLinhaProcesso += resultadoAnterior;
```

Como esperado, a execução realizará a mesma quantidade de cálculos que a versão 2 com uma complexidade de espaço similar, mas com um vetor "a menos". Porém, também há de ser considerado o tempo de execução do método `sort()` utilizado, que resulta em uma complexidade de tempo $n\log(n)$ vezes maior para cada linha executada. E, na prática, vemos que de fato não fez muita diferença, já que o tempo de execução chegou aos $3,9 s$. Isso pode ser considerado, em média, um mesmo tempo de execução que a melhoria vista na segunda versão do programa.

### Versão 4

Já na quarta e última versão do programa, foi idealizada a ideia de que, se um processo já realizou o cálculo de um arquivo em uma linha, esse valor pode ser reaproveitado nas linhas subsequentes. Então, foi criada uma variável para armazenar o "cache" dos arquivos já calculados pelo processo. Sendo ela `map<int, double> resultadosArquivos`, criada na função `leituraLinhaProcesso()` e passada por referência para o método principal da execução do programa `executarLinhaProcesso()`. Após isso, ao se criar o vetor de números dos arquivos necessários da linha, um registro será incluído no `map` com a chave (número do arquivo) e o valor (0 inicialmente), caso já não exista, com o método `try_emplace()`:

```cpp
while(std::getline(streamLinha, stringNumero, ',')){
    elementosLinha.push_back(stringNumero);
    if(i > 0){
        int num = std::stoi(stringNumero);
        numerosLinha.push_back(num);
        resultadosArquivos.try_emplace(num, 0.0);  // linha adicionada
    }
    i++;
}
```

E, também, o ciclo principal de abertura de arquivos e cálculos ficou similar à versão 2 do programa:

```cpp
if(resultadosArquivos[numerosLinha[i]] == 0.0){
    std::string linhaArquivo = leituraLinhaArquivoNumero("datasets/" + numero + ".txt");
    double resultadoArquivo = calcularResultadoArquivoNumero(linhaArquivo);
    resultadosArquivos[numerosLinha[i]] = resultadoArquivo;
}
resultadoLinhaProcesso += resultadosArquivos[numerosLinha[i]];
```

Com isso, será verificado na variável de "cache" (`resultadosArquivos`), se já existe um registro daquele arquivo com valor igual a 0 para não repetir o mesmo cálculo em um mesmo processo. Novamente, a complexidade de tempo do programa no pior caso não foi alterada, já que se os arquivos não forem repetidos em nenhum momento do processo, não haverá uma utilidade para a variável de "cache". Porém, como no enunciado e nos testes realizados os arquivos se repetem para um mesmo processo, a mudança foi muito importante para melhorar os tempos de execução do programa. Para o teste básico realizado para todas as versões, com essa última alteração, o tempo total foi cerca de $0,41 s$. 

Ao se observar os tempos de execução para cada linha de um mesmo processo, observa-se que a primeira linha continua com um tempo médio de $0,08 s$, mas, todas as próximas linhas executaram entre 1000 e 10000 vezes mais rápido que a primeira. Assim, cada processo levou cerca de $0,08 s$ para ser executado. Isso nos dá uma melhora média de 20 vezes mais velocidade nos casos em que há uma repetição de arquivos requisitados.

Além do teste básico, para a versão quatro do programa, foi realizado um [teste médio](./datasets/testeMedio/), com 20 arquivos de processos, 15 arquivos de números, 5-10 arquivos por linha e 10-15 linhas por processo. Aqui, como a quantidade de arquivos de números é maior, e o número de arquivos por linha continuou o mesmo, as duas primeiras linhas possuem um tempo de execução maior, entre $0,08 s$ e $0,13 s$, e o restante com tempos de execução ínfimos da ordem de 10000 vezes mais rápido. Assim, cada processo está levando pouco mais que o dobro de tempo que no teste básico (mudança esperada, já que o número de arquivos aumentou em 3 vezes).

Por fim, um [teste mais pesado](./datasets/testePesado/) foi testado, em que haviam 50 processos, 50 arquivos de números, 15-50 números por linha e 20-50 linhas por processo. Dessa forma, as 7 primeiras linhas dos processos estavam com tempos de execução consideráveis (de $0,01 s$ até $0,3 s$), ou seja, até que todos os arquivos fossem abertos e calculados. Para o restante das linhas os tempos foram ínfimos e, então, cada processo demorou cerca de $0,8 s$ para ser executado.

Para se tentar diminuir a complexidade de tempo ou espaço do algoritmo, uma melhoria que poderia ser realizada seria a utilização de alguma estrutura de dados mais eficiente que o `std::map`. Para tal, foi testado, para a mesma versão 4 do programa, o uso do `std::unordered_map`, que possui uma complexidade de tempo média da ordem de $\mathcal{O}(1)$. Porém, essa troca não trouxe aumento de velocidade significativo, mantendo-se, em média, os mesmos valores para os 3 testes realizados.

### Interpretação dos Resultados e Primeiras Conclusões

É evidente que o algoritmo proposto depende naturalmente das variáveis citadas nos testes acima (quantidade de processos, quantidade de arquivos de números, quantidade de números por linha e quantidade de linhas por processo). A versão 4 possui um comportamento satisfatório para casos em que os arquivos podem ser repetidos nas linhas de um mesmo processo. Contudo, sua complexidade de tempo continua exponencial em relação às variáveis citadas e, quanto maiores elas forem, o tempo será exponencialmente maior. Portanto, vale ressaltar que a versão 4 do programa pode ser mais eficiente em termos de complexidade de tempo do que as versões anteriores, e lança mão de uma variável a mais do tipo `map`, o que aumenta ligeiramente a complexidade de espaço do programa. Mas todas têm em comum o pior caso de função de custo de tempo igual a $\mathcal{O}(n^3)$, caso os arquivos não se repitam.

</div>

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## 🏁 Conclusão

<div  align="justify">

Ao se considerar todas as limitações impostas pelo encunciado, pode-se chegar à conclusão de que a solução aqui proposta é bem satisfatória pela quantidade de dados que consegue reaproveitar e pela baixa utilização de recursos computacionais. Isso porque, muito provavelmente, caso algum arquivo/processo/linha não fossem considerados, o resultado encontrado pelo programa, apesar de mais rápido, não estaria correto.

Fora isso, para melhorar ainda mais a performance do programa, levando em conta que os arquivos podem se repetir nos processos, poderia-se considerar que todos eles teriam acesso aos cálculos realizados pelos outros processos já finalizados. Assim, os arquivos já calculados antes por algum processo não seriam recalculados e isso salvaria muito tempo para as execuções seguintes. Porém, como em um sistema computacional a segurança é um dos principais pontos a serem considerados, talvez essa resolução para o problema não fosse a ideal. Já caso não houvesse essa preocupação, uma variável de "cache" poderia ser criada para o sistema todo. Assim, o primeiro processo levaria mais tempo para executar todos os arquivos que não foram abertos ainda e, para os seguintes, o tempo de execução seria consideravelmente menor. Com isso, a complexidade de tempo do programa não chegaria a $\mathcal{O}(n^3)$ antes encontrado, já que os arquivos não seriam considerados para todo processo e linha.

Além disso, como discutido, o maior desafio do problema apareceria caso os arquivos solicitados nas linhas dos processos não se repetissem e, então, nenhuma das soluções propostas acima teriam validade. Para estes casos, se o enunciado permitisse a execução de mais linhas e/ou processos ao mesmo tempo, uma solução plausível para o problema seria a utilização de técnicas de paralelismo e processamento assíncrono para que as execuções não dependessem do término das anteriores para serem iniciadas. 

De qualquer forma, para uma implementação "perfeita" do sistema idealizado no exercício, seria necessário que fosse concedido o máximo de informações possíveis sobre as características dos processos executados e as quantidades médias de arquivos e linhas obrigatórios. Como em Knuth (1998, p. 180), sobre algoritmos de multiplicação e representações polinomiais: "[...] não há uma melhor maneira de se definir 'melhor' [...] em cada caso foi necessário formular uma definição simples do 'melhor algoritmo possível', para alcançar uma estrutura suficiente para tornar o problema viável"*.

*Versão traduzida

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

C++ Reference. **CPPReference**, 2017. Disponível em: https://en.cppreference.com/w/cpp. Acesso em: 30 jun. 2024.

KNUTH, D. E. **The Art of Computer Programming**, Volume 3: Sorting and Searching. 2 ed. 1998.

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

[^3]: C++ Reference. **CPPReference**, 2017. Disponível em: https://en.cppreference.com/w/cpp. Acesso em: 30 jun. 2024.

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
[makefile]: ./makefilep

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