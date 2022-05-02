##################################################
# Make File for run hw3 Program
##################################################

OBJ = main.o admin_menu.o

all: $(OBJ)
	gcc -o all $(OBJ) `mysql_config --cflags --libs`
main.o: main.c structures.h admin_menu.h
	gcc -c main.c `mysql_config --cflags --libs`
admin_menu.o: admin_menu.c admin_menu.h
	gcc -c admin_menu.c `mysql_config --cflags --libs`
clean:
	rm -rf a.out
	rm -rf all
	rm -rf $(OBJ)
