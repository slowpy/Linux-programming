#Smart log sample code
This sample demo how to create and using smart log which auto adding application name as log prefix.

#Code Description
1. add print_app_name function in the code /user_smart_log/lib_src/lib_log/lib_log.c
<pre>
void print_app_name() {
     size_t linknamelen;
     char file[256], cmdline[256] = {0};

     sprintf(file, "/proc/%d/exe", getpid());
     linknamelen = readlink(file, cmdline, sizeof(cmdline) / sizeof(*cmdline) - 1);
     cmdline[linknamelen + 1] = 0;

     printf("[LOG][%s]", cmdline);
}
</pre>
2. add log macro in the code user_smart_log/lib_src/lib_log/lib_log.h
<pre>
  void print_app_name();

  #define log(x, ...)  print_app_name();\
	                   printf("[%s()]"x, __FUNCTION__,##__VA_ARGS__);
</pre>
3. indicate log.h location in the code /user_smart_log/app_src/app_a/Makefile
<pre>
CFLAGS	:=-g -I../../lib_src/lib_log/
...
$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(EXE)
</pre>
4. include lib_log.h and calling log() in the code /user_smart_log/app_src/app_a/app_a.c
<pre>
  #include "lib_log.h"

  int main( int argc, char* argv[])
  { 
      log("output smart log...(%s)(number=%d)\n", "hello",238); 
      return 0;
  }
</pre>

#Setup test environment
1.set LD_LIBRARY_PATH, in the user_smart_log directory, run following command:
<pre>
$ export LD_LIBRARY_PATH=$(pwd)/build
</pre>


#How to test
1. build code
<pre>$ make</pre>
2. in the user_smart_log directory, run ./build/app_a to see log with application name printed in the screen
<pre>$ ./build/app_a</pre>
3. clean build result
<pre>$ make clean</pre>


