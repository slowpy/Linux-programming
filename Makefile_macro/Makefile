#Makefile

.c.o:
	gcc -c $<
	echo "$$@ =$@"
	echo "$$< =$<"
	echo "$$* =$*"

OBJS	=app_a.o funcA.o funcA1.o

#%.o: %.c
#	gcc -c -o $@ $<
#	echo "$$@ =$@"
#	echo "$$< =$<"

app_a: $(OBJS)
	gcc $(OBJS) -o $@
	echo "app_a $$@=$@"
	echo "app_a $$<=$<"
	echo "app_a $$*=$*"
clean:
	rm -rf *.o
	rm -rf app_a
