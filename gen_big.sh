#!/bin/bash

cat $1 > $2
i=0
loop=$3
let loop--

while [ $i -lt $loop ]
do
    cat $1 >> $2
    let i++
done


