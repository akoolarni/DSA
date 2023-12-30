set title 'BST Data'
set xlabel 'Tree'
set ylabel 'Values'
plot 'output2.txt' using 1:3 title 'BST Heights' with lines, 
     'output2.txt' using 1:4 title 'BST Comparisons' with lines, 
     'output2.txt' using 1:5 title 'BST Pointer Operations' with lines
