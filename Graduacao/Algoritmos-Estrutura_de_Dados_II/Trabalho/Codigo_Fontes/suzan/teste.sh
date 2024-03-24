#!/bin/sh
if [ "$#" -ne 1 ]; then
 echo "Uso: $0 <METODO>" >&2
 echo "Argumento METODO:" >&2
 echo "   Representa o metodo de casamento exato de cadeias a ser executado, podendo ser:" >&2
 echo "   -f, --forca-bruta       Forca Bruta;" >&2
 echo "   -b, --boyer-moore       Boyer-Moore (BM) com heuristica ocorrencia;" >&2
 echo "   -m, --bm-horspool       Boyer-Moore-Horspool (BMH);" >&2
 echo "   -h, --bmh-sunday        Boyer-Moore-Horspool-Sunday (BMHS);" >&2
 echo "   -s, --shift-and         Shift-And Exato." >&2
 exit 1
fi
./casamento $1 pequeno.txt "stars" -a 
./casamento $1 pequeno.txt "Andrew Fraknoi" -a
./casamento $1 pequeno.txt "By Andrew Fraknoi and Sherwood" -a
./casamento $1 medio.txt "The" -a
./casamento $1 medio.txt "The Scarecrow" -a
./casamento $1 medio.txt "The Marvelous Land of Oz" -a
./casamento $1 grande.txt "may" -a
./casamento $1 grande.txt "entertainment" -a
./casamento $1 grande.txt "THE BEGINNING OF THIS HISTORY" -a
