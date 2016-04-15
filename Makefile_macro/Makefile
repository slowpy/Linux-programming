#Makefile

.c.o:
	gcc -c $<
	$(warning "$$@ =$@")
	$(warning "$$< =$<")
	$(warning "$$* =$*")
	$(warning "$$? =$?")

OBJS	=app_a.o funcA.o funcA1.o

#%.o: %.c
#	gcc -c -o $@ $<
#	echo "$$@ =$@"
#	echo "$$< =$<"

app_a: $(OBJS)
	gcc $? -o $@
	$(warning "app_a $$@=$@")
	$(warning "app_a $$<=$<")
	$(warning "app_a $$*=$*")
	$(warning "app_a $$?=$?")
clean:
	rm -rf *.o
	rm -rf app_a
