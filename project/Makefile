##################################################
# Make File for run hw3 Program
##################################################

OBJ = main.o admin_menu.o shoppingCart.o printBill.o addItem.o search_menu.o

all: $(OBJ)
	gcc -o all $(OBJ) `mysql_config --cflags --libs`
main.o: main.c structures.h admin_menu.h
	gcc -c main.c `mysql_config --cflags --libs`
admin_menu.o: admin_menu.c admin_menu.h
	gcc -c admin_menu.c `mysql_config --cflags --libs`
shoppingCart.o:
	gcc -c shoppingCart.c
printBill.o:
	gcc -c printBill.c
addItem.o:
	gcc -c addItem.c
search_menu.o:
	gcc -c search_menu.c
clean:
	rm -rf a.out
	rm -rf all
	rm -rf $(OBJ)
