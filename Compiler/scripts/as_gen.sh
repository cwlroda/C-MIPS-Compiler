#! /bin/bash

# Compiles all C test files in /test/ into assembly files

if [[ ! -d as_test ]]
then
    mkdir as_test
fi

for i in test/* ; do
    cp -R $i as_test
done

echo ""
SUCCESS=0

for i in as_test/* ; do
    for j in $i/*.c ; do
        ./scripts/assembler.sh $j
        rm $j
        SUCCESS=$(( ${SUCCESS}+1 ))
    done
done

echo ""
echo "Total number of files converted: ${SUCCESS}"
echo ""

