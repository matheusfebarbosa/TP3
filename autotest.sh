#!/bin/bash

for ((i=0; i<=9; i++)) do
	./TP3 < entrada/toy_"$i" > respostas/toy_"$i"
	diff -q saida/toy_"$i" respostas/toy_"$i"
done