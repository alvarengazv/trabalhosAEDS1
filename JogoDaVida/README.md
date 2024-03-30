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
    Índice
  </b>
  </summary>
  <ol>
    <li><a href="#Introdução">Introdução</a></li>
    <li><a href="#Fundamentação-Teórica">Fundamentação Teórica</a></li>
    <li><a href="#Objetivos">Objetivos</a></li>
    <li><a href="#Metodologia">Metodologia</a></li>
    <li>
      <a href="#Começando">Começando</a>
      <ul>
        <li><a href="#Pré-requisitos">Pré-requisitos</a></li>
        <li><a href="#Instalação-e-Execução">Instalação e Execução</a></li>
      </ul>
    </li>
    <li><a href="#Conclusão">Conclusão</a></li>
    <li><a href="#Ambiente-de-Compilação">Ambiente de Compilação</a></li>
    <li><a href="#Referências">Referências</a></li>
    <li><a href="#Contato">Contato</a></li>
  </ol>
</details>

## Introdução

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Fundamentação Teórica

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Objetivos

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Metodologia

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Conclusão

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Começando

Nesta seção estão exemplificados os meios para que se possa compilar e executar o programa apresentado.

### Pré-requisitos

Inicialmente, algumas considerações importantes sobre como se deve preparar o ambiente para compilar e executar o programa:

  - Recomenda-se usar o sistema operacional Linux ou o Windows Subsystem for Linux (WSL), pois os comandos no [`makefile`][makefile] foram selecionados para funcionar em um ambiente [_shell/bash_][bash-url].

  - Considerando um ambiente _shell_, garanta que os seguintes comandos já foram executados:
    - Atualize os pacotes antes da instalação dos compiladores:
    ```properties
    sudo apt update
    ```
    - Instale a coleção de compiladores ___GNU/g++___ e o ___make___:
    ```bash
    sudo apt install build-essential
    ```
    - Se necessário, instale o ___make___ individualmente:
    ```console
    sudo apt install make
    ```

### Instalando

Com o ambiente preparado, os seguintes passos são para a instalação, compilação e execução do programa localmente:

<!-- Ensinar a clonar a pasta do repositório -->
1. Clone o repositório no diretório desejado e acesse o diretório do projeto:
  ```properties
  git clone https://github.com/alvarengazv/trabalhosAEDS1.git
  cd trabalhosAEDS1/JogoDaVida
  ```
2. Compile o programa através do ___g++___ e crie um arquivo executável na pasta [`build`][build-folder]:
  ```properties
  make
  ```
3. Execute o programa da pasta [`build`][build-folder] após a compilação:
  ```properties
  make run
  ```
4. Se necessário, apague a última compilação da pasta [`build`][build-folder]:
  ```properties
  make clean
  ```

O programa estará pronto para ser testado.

<p align="right">(<a href="#readme-topo">voltar ao topo</a>)</p>

## Ambiente de Compilação
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

[1] JOHNSTON, N; GREENE, D. **Conway's Game of Life:** Mathematics and Construction. [_S.l.: s.n._], 2022. _E-book_. Disponível em: https://conwaylife.com/book/conway_life_book.pdf. Acesso em: 29 mar. 2024.

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

[vscode-badge]: https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white
[vscode-url]: https://code.visualstudio.com/docs/?dv=linux64_deb
[make-badge]: https://img.shields.io/badge/_-MAKEFILE-427819.svg?style=for-the-badge
[make-url]: https://www.gnu.org/software/make/manual/make.html
[cpp-badge]: https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white
[cpp-url]: https://en.cppreference.com/w/cpp
[makefile]: ./makefile
[bash-url]: https://www.hostgator.com.br/blog/o-que-e-bash/
[build-folder]: ./build
[lenovo-badge]: https://img.shields.io/badge/lenovo%20laptop-E2231A?style=for-the-badge&logo=lenovo&logoColor=white
[ubuntu-badge]: https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white
[ryzen-badge]: https://img.shields.io/badge/AMD%20Ryzen_5_5500U-ED1C24?style=for-the-badge&logo=amd&logoColor=white
[linkedin-badge]: https://img.shields.io/badge/-LinkedIn-0077B5?style=for-the-badge&logo=Linkedin&logoColor=white
[linkedin-autor]: https://www.linkedin.com/in/guilherme-alvarenga-de-azevedo-959474201/
[github-badge]: https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white
[github-autor]: https://github.com/alvarengazv
[gmail-badge]: https://img.shields.io/badge/-Gmail-D14836?style=for-the-badge&logo=Gmail&logoColor=white
[gmail-autor]: mailto:gui.alvarengas234@gmail.com