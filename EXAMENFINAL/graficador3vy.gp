unset label
clear
set terminal jpeg
set output "cohete3.3.jpg"
set title "Chac"
set xlabel "y(t)"
set ylabel "v(t)"
set grid
plot 'cohete3.txt' using 2:3 w l
