#Makefile
CC=gcc
EXE=hello

SRC_DIR   := funcA funcB
SRC       := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ       := $(patsubst %.c,%.o,$(SRC))

$(warning SRC_DIR=====>$(SRC_DIR))
$(warning SRC=====>$(SRC))
$(warning OBJ=====>$(OBJ))

$(EXE):$(EXE).o $(OBJ)
	$(CC) -o $@ $?

clean:
	rm -rf $(EXE) *.o
	#make -C $(SRC_DIR) clean
	for sdir in $(SRC_DIR) ; do \
    		make -C $$sdir clean ; \
	done
