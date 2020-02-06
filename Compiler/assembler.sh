#! /bin/bash

file=$1
echo ""
cat ${file}
echo -e "\n"
filename="${file%.*}"

# compiler
gcc -S ${file} -o ${filename}".s"

# assembler
as -o ${filename}".o" ${filename}".s"

#linker
ld -macosx_version_min 10.14.0 -o ${filename} ${filename}.o -lSystem

# executable
./${filename}
echo $?

