set datafile separator ","
set term png size 1920,1080 font "arial,10"

datetimeAtual = strftime("%d/%m/%Y - %H:%M:%S", time(0) - (3 * 3600))

set output 'output/img/graficoComparacaoOrdensPorAlgoritmo.png'

set multiplot layout 2,2 title sprintf("Gráficos AlgoritmosMinMax gerados em: %s", datetimeAtual)
set linetype 1 lc rgb 'green'
set linetype 2 lc rgb 'red'
set linetype 3 lc rgb 'blue'
set xrange [0:500000]
set yrange [0:4]

set xtics 50000
set ytics 0.2

set key left spacing 1.5 samplen 0.6 width 1
set grid

set ylabel "Média de tempo de Execução (ms)"
set xlabel "Tamanho da entrada (n)"

set title "MediaMinMax1"
plot 'output/csv/medias.csv' skip 1 every 3::::9 u 3:14 t "Ordem Aleatória" with lp,\
'' skip 1 every 3::::9 u 3:14:(sprintf("%.2f", $14)) with labels center offset 0,1 notitle,\
'' skip 2 every 3::::9 u 3:14 t "Ordem Crescente" with lp,\
'' skip 3 every 3::::9 u 3:14 t "Ordem Decrescente" with lp

set title 'MediaMinMax2'
plot 'output/csv/medias.csv' skip 13 every 3::::9 u 3:14 t "Ordem Aleatória" with lp,\
'' skip 13 every 3::::9 u 3:14:(sprintf("%.2f", $14)) with labels center offset 0,1 notitle,\
'' skip 14 every 3::::9 u 3:14 t "Ordem Crescente" with lp,\
'' skip 15 every 3::::9 u 3:14 t "Ordem Decrescente" with lp

set title 'MediaMinMax3'
plot 'output/csv/medias.csv' skip 25 every 3::::9 u 3:14 t "Ordem Aleatória" with lp,\
'' skip 25 every 3::::9 u 3:14:(sprintf("%.2f", $14)) with labels center offset 0,1 notitle,\
'' skip 26 every 3::::9 u 3:14 t "Ordem Crescente" with lp,\
'' skip 27 every 3::::9 u 3:14 t "Ordem Decrescente" with lp

f(n) = n - 1 
g(n) = 2*(n - 1) 
h(n) = 3*(n/2) - 3/2 
q(n) = 3*(n/2) - 2
p(n) = n

unset ytics
unset xtics

set ylabel "f(n)"

set xrange [0:30]
set yrange [0:85]

# set ytics 100000

set title "Funções de cada Algoritmo em relação ao de custo ótimo"
plot f(x) with lines lc rgb 'blue' lw 2 title 'f(n) = n - 1',\
g(x) with lines lc rgb 'red' lw 2 title 'g(n) = 2(n - 1)',\
h(x) with lines lc rgb 'green' lw 2 title 'h(n) = 3n/2 - 3/2',\
q(x) with lines lc rgb 'yellow' lw 2 title 'q(n) = 3n/2 - 2',\
p(x) with lines lc rgb 'orange' lw 2 title 'p(n) = n'

unset multiplot

set output 'output/img/graficoComparacaoAlgoritmosPorOrdem.png'

set multiplot layout 2,2 title sprintf("Gráficos AlgoritmosMinMax gerados em: %s", datetimeAtual)
set linetype 1 lc rgb 'green'
set linetype 2 lc rgb 'red'
set linetype 3 lc rgb 'blue'
set xrange [0:500000]
set yrange [0:4]

set xtics 50000
set ytics 0.2

set key left spacing 1.5 samplen 0.6 width 1
set grid

set ylabel "Média de tempo de Execução (ms)"
set xlabel "Tamanho da entrada (n)"

set title "Ordem Aleatória"
plot 'output/csv/medias.csv' skip 1 every 3::::9 u 3:14 t "MinMax1" with lp,\
'' skip 13 every 3::::9 u 3:14 t "MinMax2" with lp,\
'' skip 25 every 3::::9 u 3:14 t "MinMax3" with lp,\

set title "Ordem Crescente"
plot 'output/csv/medias.csv' skip 2 every 3::::9 u 3:14 t "MinMax1" with lp,\
'' skip 14 every 3::::9 u 3:14 t "MinMax2" with lp,\
'' skip 26 every 3::::9 u 3:14 t "MinMax3" with lp,\

set title "Ordem Decrescente"
plot 'output/csv/medias.csv' skip 3 every 3::::9 u 3:14 t "MinMax1" with lp,\
'' skip 15 every 3::::9 u 3:14 t "MinMax2" with lp,\
'' skip 27 every 3::::9 u 3:14 t "MinMax3" with lp,\

f(n) = n - 1 
g(n) = 2*(n - 1) 
h(n) = 3*(n/2) - 3/2 
q(n) = 3*(n/2) - 2
p(n) = n

unset ytics
unset xtics

set ylabel "f(n)"

set xrange [0:30]
set yrange [0:85]

# set ytics 100000

set title 'Funções de cada Algoritmo em relação ao de custo ótimo"
plot f(x) with lines lc rgb 'blue' lw 2 title 'f(n) = n - 1',\
g(x) with lines lc rgb 'red' lw 2 title 'g(n) = 2(n - 1)',\
h(x) with lines lc rgb 'green' lw 2 title 'h(n) = 3n/2 - 3/2',\
q(x) with lines lc rgb 'yellow' lw 2 title 'q(n) = 3n/2 - 2',\
p(x) with lines lc rgb 'orange' lw 2 title 'p(n) = n'
