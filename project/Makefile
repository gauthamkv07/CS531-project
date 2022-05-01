##################################################
# Make File for run hw3 Program
##################################################

OBJ = main.o

all: $(OBJ)
	gcc -o all $(OBJ)
main.o: main.c structures.h admin_menu.h
	gcc -c main.c
admin_menu.o: admin_menu.c admin_menu.h
	gcc -c admin_menu.c
clean:
	rm -rf a.out
	rm -rf all
	rm -rf $(OBJ)
