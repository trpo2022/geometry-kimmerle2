CFLAGS = -Wall -Wextra -Werror

all: main

main: bin/main

bin/main: obj/src/main/main.o obj/src/libmain/libmain.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/main/main.o: src/main/main.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/libmain.a: obj/src/libmain/Area_and_Perimetr.o obj/src/libmain/Read.o
	ar rcs $@ $^




obj/src/libmain/Area_and_Perimetr.o: src/libmain/Area_and_Perimetr.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/Read.o: src/libmain/Read.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	
	



.PHONY: clean

clean:
	rm obj/src/libmain/*.a obj/src/libmain/*.o obj/src/main/*.o bin/main

