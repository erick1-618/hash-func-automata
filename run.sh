#!/bin/bash

ARCHIVE="automata"

echo Compiling...

gcc "./src/$ARCHIVE.c" -o "./bin/$ARCHIVE"

if [ $? -eq 0 ]; then

    echo Executing...
    ./bin/$ARCHIVE $1
else
    echo Error compiling
fi
