unset label
clear
set terminal jpeg
set output "cohete2.2.jpg"
set title "Ahau Kin"
set xlabel "t"
set ylabel "v(t)"
set grid
plot 'cohete2.txt' using 1:3 w l
