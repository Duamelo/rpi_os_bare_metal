#!/usr/bin/bash

mkdir -p build/files

FILES=build/files

KER=kernel

MOD=modules

for i in $(ls $MOD --ignore=*.*); do
	cp -f ${MOD}/${i}/*.c ${FILES};
    cp -f ${MOD}/${i}/*.h ${FILES};
done

cp -f ${MOD}/*.h $FILES
cp -f ${KER}/* ${FILES}
cp -f *.c ${FILES}
#cp -f *.h ${FILES}

cp build/Makefile $FILES
cp build/linker.ld $FILES

cd ${FILES} || exit

make