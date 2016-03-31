#Makefile
CFLAGS	:=-g -I../../com_lib_src/lib_log
LDFLAGS	:=-L$(BUILD_PATH)
LDLIBS	:=-l_demo_a -l_log
EXE	:=app_a
SRC	:= $(wildcard *.c)
OBJ	:= $(patsubst %.c,%.o,$(SRC))

.*.h : ../../com_lib_src/lib_log/

$(warning OBJ=$(OBJ))

all:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(EXE)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(EXE) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf $(EXE)
