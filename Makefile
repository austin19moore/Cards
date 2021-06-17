output: main.o cards.o
	g++ main.o cards.o -o output

main.o: main.c
	g++ -c main.c
	
cards.o: cards.c cards.h
	g++ -c cards.c

clean: 
	rm *.o output