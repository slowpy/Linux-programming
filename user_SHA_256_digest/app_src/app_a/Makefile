#Makefile
CFLAGS	:=-g
LDFLAGS	:=-L$(BUILD_PATH)
LDLIBS	:=-lcrypto
EXE	:=app_a
SCRIPT	:=
SRC	:= $(wildcard *.c)
OBJ	:= $(patsubst %.c,%.o,$(SRC))


$(warning OBJ=$(OBJ))

all:$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(EXE)
	@mkdir -p $(BUILD_PATH)
	@cp -rf $(SCRIPT) $(EXE) $(BUILD_PATH)

clean:
	rm -rf *.o
	rm -rf $(EXE)
