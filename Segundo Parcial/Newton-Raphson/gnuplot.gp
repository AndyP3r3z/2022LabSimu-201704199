unset label
clear
set terminal pdf
set output 'función.pdf'
set title 'Ceros de f(x)'
set xlabel 'x'
set ylabel 'f(x)'
set grid
set xrange [-1:2]
set yrange [-1:2]
set key left
plot 2 + cos(exp(x)- 2) - exp(x) w l, 0 lc 0 notitle
