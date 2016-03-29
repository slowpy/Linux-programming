#Makefile
CFLAGS	:=-g
LDFLAGS	:=-L$(BUILD_PATH)
LDLIBS	:=-l_demo_a
EXE	:=app_a
SRC	:= $(wildcard *.c)
OBJ	:= $(patsubst %.c,%.o,$(SRC))

$(warning OBJ=$(OBJ))

all:$(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $(EXE)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(EXE) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf $(EXE)
