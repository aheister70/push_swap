# push_swap
This project can sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

<b>INSTRUCTIONS</b><br>
• run a terminal in bash<br>
• compile the program by typing in 'make'<br>
• run it with as many numbers as you want and see how many actions were needed:<br>
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

• run it with the checker program to check if everything is sorted:<br>
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
