CFLAGS = -Wall -Wextra -Werror

all: main

main: bin/main

bin/main: obj/src/main/main.o obj/src/libmain/libmain.a
	gcc $(CFLAGS) -o $@ $^ -lm

obj/src/main/main.o: src/main/main.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/libmain.a: obj/src/libmain/skipCircle.o obj/src/libmain/skipSign.o obj/src/libmain/skipDigit.o obj/src/libmain/checkEndStr.o obj/src/libmain/perimeterCircle.o obj/src/libmain/areaCircle.o 
	ar rcs $@ $^




obj/src/libmain/skipCircle.o: src/libmain/skipCircle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/skipSign.o: src/libmain/skipSign.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	
	
obj/src/libmain/skipDigit.o: src/libmain/skipDigit.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/checkEndStr.o: src/libmain/checkEndStr.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm

obj/src/libmain/perimeterCircle.o: src/libmain/perimeterCircle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	

obj/src/libmain/areaCircle.o: src/libmain/areaCircle.c
	gcc -c -I src $(CFLAGS) -o $@ $< -lm	



.PHONY: clean

clean:
	rm obj/src/libmain/*.a obj/src/libmain/*.o obj/src/main/*.o bin/main

