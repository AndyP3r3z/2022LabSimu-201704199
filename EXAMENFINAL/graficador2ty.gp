unset label
clear
set terminal jpeg
set output "cohete2.1.jpg"
set title "Ahau Kin"
set xlabel "t"
set ylabel "y(t)"
set grid
plot 'cohete2.txt' using 1:2 w l
