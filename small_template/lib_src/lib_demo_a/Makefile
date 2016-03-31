#Makefile
CFLAGS	:=-shared -fPIC -I../../com_lib_src/lib_log/
LDFLAGS :=-L$(BUILD_PATH)
LDLIBS 	:=-l_log
LIB_NAME	:=lib_demo_a.so

SRC=$(wildcard *.c)
$(warning SRC=$(SRC))

all:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC) -o $(LIB_NAME)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(LIB_NAME) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf *.so
