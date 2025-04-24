#!/bin/bash

ARCHIVE="automata"

echo Compiling...

gcc $ARCHIVE.c -o $ARCHIVE

if [ $? -eq 0 ]; then

    echo Executing...
    ./$ARCHIVE $1
else
    echo Error compiling
fi
