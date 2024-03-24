#!/bin/sh

echo "TESTE COM ARQUIVO GRANDE\n" > saida.txt
echo "-----------Padrão pequeno\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 grande.txt "Curae" -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 grande.txt "Curae" -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 grande.txt "Curae" -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 grande.txt "Curae" -P >> saida.txt
echo "#ShiftAnd\n" >> saida.txt
./casamento 5 grande.txt "Curae" -P >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão medio\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 grande.txt "hendrerit quis" -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 grande.txt "hendrerit quis" -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 grande.txt "hendrerit quis" -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 grande.txt "hendrerit quis" -P >> saida.txt
echo "#ShiftAnd\n" >> saida.txt
./casamento 5 grande.txt "hendrerit quis" -P >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão grande\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 grande.txt "ac placerat dolor lectus quis " -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 grande.txt "ac placerat dolor lectus quis " -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 grande.txt "ac placerat dolor lectus quis " -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 grande.txt "ac placerat dolor lectus quis " -P >> saida.txt
#echo "#ShiftAnd\n" >> saida.txt
#./casamento 5 grande.txt "Lorem ipsum dolor sit amet" -P >> saida.txt

echo "---------------------------------------------------------\n" >> saida.txt
echo "TESTE COM ARQUIVO MEDIO\n" >> saida.txt

echo "-----------Padrão pequeno\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 medio.txt "nisi " -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 medio.txt "nisi " -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 medio.txt "nisi " -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 medio.txt "nisi " -P >> saida.txt
echo "#ShiftAnd\n" >> saida.txt
./casamento 5 medio.txt "nisi " -P >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão medio\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 medio.txt " turpis egestas" -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 medio.txt " turpis egestas" -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 medio.txt " turpis egestas" -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 medio.txt " turpis egestas" -P >> saida.txt
echo "#ShiftAnd\n" >> saida.txt
./casamento 5 medio.txt " turpis egestas" -P >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão grande\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 medio.txt "Suspendisse pulvinar, augue ac" -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 medio.txt "Suspendisse pulvinar, augue ac" -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 medio.txt "Suspendisse pulvinar, augue ac" -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 medio.txt "Suspendisse pulvinar, augue ac" -P >> saida.txt
#echo "#ShiftAnd\n" >> saida.txt
#./casamento 5 medio.txt "Lorem ipsum dolor sit amet" -P >> saida.txt

echo "---------------------------------------------------------\n" >> saida.txt
echo "TESTE COM ARQUIVO PEQUENO\n" >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão pequeno\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 pequeno.txt " quis" -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 pequeno.txt " quis" -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 pequeno.txt " quis" -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 pequeno.txt " quis" -P >> saida.txt
echo "#ShiftAnd\n" >> saida.txt
./casamento 5 pequeno.txt " quis" -P >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão medio\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 pequeno.txt "hendrerit quis," -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 pequeno.txt "hendrerit quis," -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 pequeno.txt "hendrerit quis," -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 pequeno.txt "hendrerit quis," -P >> saida.txt
echo "#ShiftAnd\n" >> saida.txt
./casamento 5 pequeno.txt "hendrerit quis," -P >> saida.txt

echo "\n" >> saida.txt
echo "-----------Padrão grande\n" >> saida.txt
echo "#Forca Bruta\n" >> saida.txt
./casamento 1 pequeno.txt " Donec vitae sapien ut libero " -P >> saida.txt
echo "#BMC\n" >> saida.txt
./casamento 2 pequeno.txt " Donec vitae sapien ut libero " -P >> saida.txt
echo "#BMH\n" >> saida.txt
./casamento 3 pequeno.txt " Donec vitae sapien ut libero " -P >> saida.txt
echo "#BMHS\n" >> saida.txt
./casamento 4 pequeno.txt " Donec vitae sapien ut libero " -P >> saida.txt
#echo "#ShiftAnd\n" >> saida.txt
#./casamento 5 pequeno.txt "Lorem ipsum dolor sit amet" -P >> saida.txt
