unset label
clear
set terminal jpeg
set output "cohete1.3.jpg"
set title "Ah Mun"
set xlabel "y(t)"
set ylabel "v(t)"
set grid
plot 'cohete1.txt' using 2:3 w l
