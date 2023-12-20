#!/bin/bash

#Введите путь до файла
read -p "Введите путь до файла: " filename

line=$(wc -l $filename)
line=${line% *}
echo $line
echo $(awk '{print $1}' $filename|grep -v src/history_of_vim.txt|sort -u|wc -l)
echo $(awk '{print $8}' $filename|grep -v NULL|sort -u|wc -l)








