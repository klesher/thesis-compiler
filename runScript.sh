#!/bin/bash

#NEED TO REWORK.  RUN WITH ALREADY COMPILED BINARIES?

#Compile the compiler and the code generator, and run it

#Compiler the compiler
cd compiler/
make

#Stop the script if there was a compiling error.  Does NOT
#stop the script for warnings.
if [ $? != 0 ];
then
    exit
fi

#Move the compiler's bytecode output to the code generator
cp in.abc ../codeGenerator


#Compile the code generator
cd ../codeGenerator
make

#Stop the script if there was a compiling error.  Does NOT
#stop the script for warnings.
if [ $? != 0 ];
then
    exit
fi

#Display the results of the code generator
#cat out.xml

#Move the output to the web directory & change permissions
cp out.xml /var/www/html/out.xml
