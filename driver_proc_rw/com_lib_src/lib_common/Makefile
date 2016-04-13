#Makefile
CFLAGS	:=-shared -fPIC
LIB_NAME	:=lib_common.so

SRC=$(wildcard *.c)
$(warning SRC=$(SRC))

all:
	$(CC) $(CFLAGS) $(SRC) -o $(LIB_NAME)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(LIB_NAME) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf *.so
