unset label
clear
set terminal jpeg
set output "cohete3.2.jpg"
set title "Chac"
set xlabel "t"
set ylabel "v(t)"
set grid
plot 'cohete3.txt' using 1:3 w l
