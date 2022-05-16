unset label
clear
set terminal jpeg
set output "cohete3.1.jpg"
set title "Chac"
set xlabel "t"
set ylabel "y(t)"
set grid
plot 'cohete3.txt' using 1:2 w l
