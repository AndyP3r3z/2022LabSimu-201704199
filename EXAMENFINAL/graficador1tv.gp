unset label
clear
set terminal jpeg
set output "cohete1.2.jpg"
set title "Ah Mun"
set xlabel "t"
set ylabel "v(t)"
set grid
plot 'cohete1.txt' using 1:3 w l
