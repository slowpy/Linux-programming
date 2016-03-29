#Build shared library(*.so) Sample code
This sample demo how to bulid and use shared library.

# Code Description
1. Build shared library: check the code in /user_build_library/lib_src/lib_demo_a/Makefile
<pre>
$(CC) $(CFLAGS) $(SRC) -o $(LIB_NAME)
</pre>
CFLAGS :=-shared -fPIC ==> tell compiler that you want to build as shared library.

2. Link shared library "lib_demo_a.so": check the code in /user_build_library/app_src/app_a/Makefile
<pre>
$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(EXE)
</pre>
"LDFLAGS" indicate shared library location. "LDLIBS := -l_demo_a" means linking "lib_demo_a.so"

3. Calling shared library functions: check the code in /user_build_library/app_src/app_a/app_a.c
<pre>
int main( int argc, char* argv[])
{
    //calling function in library
    test_lib_a();
    test_lib_a1();
    return 0;
}
</pre>

#How to test
1. build code
<pre>$ make</pre>
2. set LD_LIBRARY_PATH environment variable to export shared library path
in folder "user_build_library", then run below command.
<pre>$ export LD_LIBRARY_PATH=$(pwd)/build</pre>
3. check build folder and find out build result 
<pre>
app_a - application
lib_demo_a.so, lib_demo_b.so - shared library
hello.ko - driver
</pre>
4. run app_a and see some log from shared library.
<pre>$ ./app_a </pre>
you will see logs:
<pre>
test_lib_a() is called (in lib_a.c)
test_lib_a1() is called (in lib_a1.c)
</pre>

5. remove all build result
<pre>$ make clean</pre> 


