#Makefile
CFLAGS	:=-g -I../../com_lib_src/lib_common -I../../drv_src/drv_caller
LDFLAGS	:=-L$(BUILD_PATH)
LDLIBS	:=-l_demo_a -l_common
EXE	:=app_a
SRC	:= $(wildcard *.c)
OBJ	:= $(patsubst %.c,%.o,$(SRC))

.*.h : ../../com_lib_src/lib_common/

$(warning OBJ=$(OBJ))

all:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(EXE)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(EXE) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf $(EXE)
