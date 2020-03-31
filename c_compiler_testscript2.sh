#!/bin/bash
c_dir="testing/c_files";
input_dir="testing/s_files";
gcc_dir="testing/gccobjfile";
prog_file="testing/program_files";
output_dir="testing/output_files";
driver_dir="testing/driver_files";

for i in ${c}/*.c ; do
	#tmp="${i##*/}";
	#echo "${i##*/}";
	tmp=$(basename -- $i .c);
	echo $tmp;
	./bin/c_compiler -S "$i" -o "$input_dir/$tmp.s";
done

for i in ${input_dir}/*.s ; do
	tmp=$(basename -- $i .s);
	echo $tmp;
	chmod u+x "$input_dir"/"$tmp".s;
	mips-linux-gnu-gcc -mfp32 -o "$gcc_dir"/"$tmp".o -c "$input_dir"/"$tmp".s;
	chmod u+x "$gcc_dir"/"$tmp".o
	mips-linux-gnu-gcc -mfp32 -static -o "$prog_dir"/"$tmp" "$gcc_dir"/"$tmp".o "$driver_dir"/"$tmp""_driver".c
	chmod u+x "$prog_dir"/"$tmp"
	qemu-mips "$prog_dir"/"$tmp";
	
done