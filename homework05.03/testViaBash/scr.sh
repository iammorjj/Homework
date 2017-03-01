#!/bin/bash

make

ans=0
i=1
dir=./test/

while [[ i -lt 11 ]] 
do
	./MyProg < $dir${i}_test_in.txt > $dir${i}_test_out.txt
	str1=$(cat $dir${i}_test_out.txt)
	str2=$(cat $dir${i}_test_res.txt)
	if [[ str1 -eq str2 ]]; then
		let "ans+=1"
	fi
	let "i+=1"
done
echo $ans	
