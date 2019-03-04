#!/bin/bash

TEST_PREFIX="testData"
DIR_PROJECT=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && cd .. && pwd )
DIR_COMPILER="$DIR_PROJECT/compiler/"
DIR_TESTING="$DIR_PROJECT/testing/"

#Test the compiler pipeline.

#Compile the compiler
cd "$DIR_COMPILER"
make cleanmake 1>/dev/null

#Stop the script if there was a compiling error.  Does NOT
#stop the script for warnings.
compiler_exit_status=$?

if [ $compiler_exit_status -ne 0 ];
then
    echo "FAIL: Compilation error."
    exit $compiler_exit_status
fi


# Run the compiler with test DATA
./aol < $DIR_TESTING/$TEST_PREFIX.aol > $DIR_TESTING/$TEST_PREFIX.abc

cd $DIR_TESTING
diff $TEST_PREFIX.abc $TEST_PREFIX.ref.abc > $TEST_PREFIX.abc.diff

diff_exit_status=$?

if [ $diff_exit_status -ne 0 ];
then
    echo "FAIL: Generated .abc file differs from reference .abc file."
    exit $diff_exit_status
fi

if [ ! -s $TEST_PREFIX.abc.diff ];
then
    rm $TEST_PREFIX.abc.diff
fi


#Compile the code generator
cd ../codeGenerator
make cleanmake 1>/dev/null

codegen_exit_status=$?

#Stop the script if there was a compiling error.  Does NOT
#stop the script for warnings.
if [ $codegen_exit_status -ne 0 ];
then
    echo "FAIL: Code generation error."
    exit $codegen_exit_status
fi

./aolCodeGen $DIR_TESTING/$TEST_PREFIX.abc $DIR_TESTING/$TEST_PREFIX.xml

cd $DIR_TESTING
diff $TEST_PREFIX.xml $TEST_PREFIX.ref.xml > $TEST_PREFIX.xml.diff

diff_exit_status=$?

if [ $diff_exit_status -ne 0 ];
then
    echo "FAIL: Generated .xml file differs from reference .xml file."
    exit $diff_exit_status
fi

if [ ! -s $TEST_PREFIX.xml.diff ];
then
    rm $TEST_PREFIX.xml.diff
fi

echo "PASS: All compilation and run tests passed."

exit 0
