#!/bin/bash

input_dir="testing/c_files";
output_dir="testing/s_files";

for i in ${input_dir}/*.c ; do
	#tmp="${i##*/}";
	#echo "${i##*/}";
	tmp=$(basename -- $i .c);
	echo $tmp;
	./bin/c_compiler -S "$i" -o "$output_dir/$tmp.s";
done