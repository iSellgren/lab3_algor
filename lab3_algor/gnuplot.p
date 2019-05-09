# Gnuplot script file for plotting data in file "HashTable"
# This file is called   gnuplot
set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "SearchAlgorithms"
set xlabel "Primes (NumersOf)"
set ylabel "Time (microSec)"
set yr [*:*]
set xr[0:*];
set terminal qt 0
##plot "HashTable.txt" using 1:2 title 'HashTable' with lines , \
##"HashTable.txt" using 1:2:3 with errorbars
##replot "BalanceTree.txt" using 1:2 title 'BalanceTree' with lines , \
##"BalanceTree.txt" using 1:2:3 with errorbars
##replot "BinarySearch.txt" using 1:2 title 'BinarySearch' with lines , \
##"BinarySearch.txt" using 1:2:3 with errorbars

##set terminal qt 1
plot "LinearSearch.txt" using 1:2 title 'LinearSearch' with lines , \
"LinearSearch.txt" using 1:2:3 with errorbars


##set terminal qt 2
##plot "HashTable.txt" using 1:2 title 'HashTable' with lines , \
##"HashTable.txt" using 1:2:3 with errorbars

##set terminal qt 3
##plot "BalanceTree.txt" using 1:2 title 'BalanceTree' with lines , \
##"BalanceTree.txt" using 1:2:3 with errorbars

set terminal qt 4
plot "BinarySearch.txt" using 1:2 title 'BinarySearch' with lines , \
"BinarySearch.txt" using 1:2:3 with errorbars
set terminal qt 5
plot "LinearSearchComp.txt" using 1:2 title 'LinearSearchComp' with lines , \
"LinearSearchComp.txt" using 1:2:3 with errorbars
set terminal qt 6
plot "BinarySearchComp.txt" using 1:2 title 'BinarySearchComp' with lines , \
"BinarySearchComp.txt" using 1:2:3 with errorbars
