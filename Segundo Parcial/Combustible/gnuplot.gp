unset label
clear
set terminal pdf
set output 'tendencia.pdf'
set title 'Tendencia de la Gasolina'
set xlabel 'Semana'
set ylabel 'Precio por Galon (Q.)'
set grid
set key left
plot 'data' w p, 0.446*x + 19.667 w l
