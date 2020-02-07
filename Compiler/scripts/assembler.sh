#! /bin/bash

# Converts a C file to an Assembly file
# Links and generates an executable
# ./assembler.sh file.c

file=$1
echo ""
cat ${file}
echo -e "\n"
filename="${file%.*}"

# compiler
clang -S ${file} -o ${filename}.s

# assembler
as -o ${filename}.o ${filename}.s

# linker
# NOTE: does not work with multiple files
# ld -macosx_version_min 10.14.0 -o ${filename} ${filename}.o -lSystem

