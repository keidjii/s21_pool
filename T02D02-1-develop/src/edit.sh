#!/bin/bash

#   Введите путь до файла
read -p "Имя файла: " filename

# Возьмите строку поиска
read -p "Введите строку поиска: " search

# Возьмите строку замены
read -p "Введите строку замены: " replace

#if [[ $search != "" && $replace != "" ]]; then
sed -i '' "s/$search/$replace/g" $filename
#fi
way=$filename
date=$(stat -f %Sm -t '%y-%m-%d %H:%M' $filename)
size=$(stat -f %z $filename)
sha1=$(shasum -a 256 $filename)
sha=${sha1% *}

 
#filename=${filename#*../}
echo "$filename"' - '"$date"' - '"$size"' - '"$sha"' - sha256'>>files.log



