#! /bin/bash
if [[ ! -d as_test ]]
then
    mkdir as_test
fi

for i in test/* ; do
    cp -R $i as_test
done

for i in as_test/* ; do
    for j in $i/*.c ; do
        ./assembler.sh $j
        rm $j
    done
done

