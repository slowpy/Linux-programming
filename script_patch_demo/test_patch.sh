#!/bin/bash
#clear 
rm -rf ./hello_test_patch
#create patch
echo "create hello.patch..."
diff -ruN hello_old/ hello_new/ > hello.patch
echo "create hello.patch success."
echo "copy hello_old to hello_test_patch for testing..."
cp -rf ./hello_old ./hello_test_patch
mv ./hello.patch ./hello_test_patch/
echo "enter ./hello_test_patch..."
cd ./hello_test_patch
echo "patch hello.patch to ./hello_test_patch"
patch -p1 < hello.patch
echo "building code..."
make
echo "running hello(after patch)..."
./hello
cd ../
