#!/bin/sh
## testLemIn.sh for lemin in /home/alexis/rendu/B2/CPE/CPE_2014_lemin/tests
## 
## Made by alexis
## Login   <alexis@epitech.net>
## 
## Started on  Sun May  3 19:10:03 2015 alexis
## Last update Sun May  3 21:23:01 2015 guigui
##

make re
clear
printf "\t\t\t\t\t\t Welcome to the Lem-In \n";
sleep 1;

printf "\t\t\t\\t\t\t We are going to do some tests\n";
sleep 1;

clear


printf "\t\t\t\\t\t\t First: A small test\n";
cat ./tests/FirstMap | ./lem_in
sleep 2;
clear

printf "\t\t\t\\t\t\t Second: A map more difficult test\n";
cat ./tests/SecondMap | ./lem_in
sleep 2;
clear

printf "\t\t\t\\t\t\t Third: A small test\n";
cat ./tests/ThirdMap | ./lem_in
sleep 2;
clear

printf "\t\t\t\\t\t\t Fourth: A small test\n";
cat ./tests/FourthMap | ./lem_in
sleep 2;
clear

printf "\t\t\t\\t\t\t Fifth: A small test\n";
cat ./tests/FifthMap | ./lem_in
sleep 2;
clear

printf "\t\t\t\\t\t\t Final: The FINAL TEST\n";
cat ./tests/FinalMap | ./lem_in
sleep 2;
clear

