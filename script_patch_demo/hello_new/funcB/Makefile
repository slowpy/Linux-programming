#Makefile

SRC_DIR	:= .
SRC	:= $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ	:= $(patsubst %.c,%.o,$(SRC))

all:$(OBJ)

clean:
	rm -rf *.o
