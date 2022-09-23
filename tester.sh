#! /bin/bash

TESTDIR="tests"
SAMPLESDIR="srcs/tests/samples"
SAMPLES=("aes" "avx" "avx2" "avx512" "basic" "fma" "mmx" "sse" "sse2" "sse3" "sse4" "x87")

EXEC="disassembler"
NASM="nasm -g -f elf64 -o"
OBJCOPY="objcopy -O binary -j .text"
OBJDUMP="objdump -d -M intel"

RED=$'\e[1;31m'
GREEN=$'\e[1;32m'
RESET=$'\e[1;0m'

rm -rf ${TESTDIR}
mkdir ${TESTDIR}
cp ${EXEC} ${TESTDIR}
cd ${TESTDIR}

for SAMPLE in ${SAMPLES[*]} ; do

    echo -n "Testing: [${SAMPLE^^}]:"

    ${NASM} ${SAMPLE}.o ../${SAMPLESDIR}/${SAMPLE}.S
    if [ $? != 0 ] ; then
        echo "ERROR: ${SAMPLE^^}: Not possible to compile."
        exit 1
    fi

    ${OBJCOPY} ${SAMPLE}.o ${SAMPLE}.txt
    if [ $? != 0 ] ; then
        echo "ERROR: ${SAMPLE^^}: Not possible to objcopy."
        exit 1
    fi

    ./${EXEC} ${SAMPLE}.txt 1> ${SAMPLE}.log.S 2> /dev/null
    if [ $? != 0 ] ; then
        echo "ERROR: ${EXEC}: Returned error."
        exit 1
    fi

    ${NASM} ${SAMPLE}.log.o ${SAMPLE}.log.S
    if [ $? != 0 ] ; then
        echo "ERROR: ${SAMPLE^^}.log: Not possible to compile."
        exit 1
    fi

    ${OBJDUMP} ${SAMPLE}.log.o | sed '2d' > ${SAMPLE}.diff.new.txt
    ${OBJDUMP} ${SAMPLE}.o | sed '2d' > ${SAMPLE}.diff.orig.txt

    diff ${SAMPLE}.diff.new.txt ${SAMPLE}.diff.orig.txt > /dev/null
    if [ $? -eq 0 ] ; then
        echo "${GREEN} PASSED ${RESET}"
    else
        echo "${RED} FAILED ${RESET}"
    fi

done
