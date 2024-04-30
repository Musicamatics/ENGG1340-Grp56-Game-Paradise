CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11


snake: main.o snake.o userinput.o
	$(CC) $(CFLAGS) -o snake main.o snake.o userinput.o -lncurses

wordle: wordle_main.o wordle_main2.o wordle.o
	$(CC) $(CFLAGS) -o wordle wordle_main.o wordle_main2.o wordle.o

main.o: main.cpp snake.h
	$(CC) $(CFLAGS) -c main.cpp

snake.o: snake.cpp snake.h
	$(CC) $(CFLAGS) -c snake.cpp

userinput.o: userinput.cpp snake.h
	$(CC) $(CFLAGS) -c userinput.cpp

wordle_main.o: wordle_main.cpp wordle.h
	$(CC) $(CFLAGS) -c wordle_main.cpp

wordle_main2.o: wordle_main2.cpp wordle.h
	$(CC) $(CFLAGS) -c wordle_main2.cpp

wordle.o: wordle.cpp wordle.h
	$(CC) $(CFLAGS) -c wordle.cpp

clean:
	rm -f launcher snake wordle *.o
