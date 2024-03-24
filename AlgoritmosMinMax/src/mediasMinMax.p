set datafile separator ","
set term png size 1920,1080 font "arial,10"

# The file we'll write to
set output 'output/img/grafico04.png'

set multiplot layout 2,2
set linetype 1 lc rgb 'green'
set linetype 2 lc rgb 'red'
set linetype 3 lc rgb 'blue'
set xrange [0:500000]
set yrange [0:4]

set xtics 50000
set ytics 0.2


# The graphic title
set key left spacing 0.9 samplen 0.6 width 1
set grid

set ylabel "Média de tempo de Execução (ms)"
set xlabel "Tamanho da entrada (n)"

#plot the graphic
set title 'MediaMinMax1'
plot 'output/csv/medias04.csv' skip 1 every 3::::9 u 3:14 t "Ordem Aleatória" with lp,\
'' skip 1 every 3::::9 u 3:14:14 with labels center offset 0,1 notitle,\
'' skip 2 every 3::::9 u 3:14 t "Ordem Crescente" with lp,\
'' skip 3 every 3::::9 u 3:14 t "Ordem Decrescente" with lp

set title 'MediaMinMax2'
plot 'output/csv/medias04.csv' skip 13 every 3::::9 u 3:14 t "Ordem Aleatória" with lp,\
'' skip 13 every 3::::9 u 3:14:14 with labels center offset 0,1 notitle,\
'' skip 14 every 3::::9 u 3:14 t "Ordem Crescente" with lp,\
'' skip 15 every 3::::9 u 3:14 t "Ordem Decrescente" with lp

set title 'MediaMinMax3'
plot 'output/csv/medias04.csv' skip 25 every 3::::9 u 3:14 t "Ordem Aleatória" with lp,\
'' skip 25 every 3::::9 u 3:14:14 with labels center offset 0,1 notitle,\
'' skip 26 every 3::::9 u 3:14 t "Ordem Crescente" with lp,\
'' skip 27 every 3::::9 u 3:14 t "Ordem Decrescente" with lp