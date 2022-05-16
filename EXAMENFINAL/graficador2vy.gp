unset label
clear
set terminal jpeg
set output "cohete2.3.jpg"
set title "Ahau Kin"
set xlabel "y(t)"
set ylabel "v(t)"
set grid
plot 'cohete2.txt' using 2:3 w l
