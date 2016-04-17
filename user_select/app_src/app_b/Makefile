#Makefile
CFLAGS	:=-g
LDFLAGS	:=-L$(BUILD_PATH)
LDLIBS	:=
EXE	:=app_b
SRC	:= $(wildcard *.c)
OBJ	:= $(patsubst %.c,%.o,$(SRC))


$(warning OBJ=$(OBJ))

all:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(EXE)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(EXE) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf $(EXE)
