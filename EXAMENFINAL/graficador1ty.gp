unset label
clear
set terminal jpeg
set output "cohete1.1.jpg"
set title "Ah Mun"
set xlabel "t"
set ylabel "y(t)"
set grid
plot 'cohete1.txt' using 1:2 w l
