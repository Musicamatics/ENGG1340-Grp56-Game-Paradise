FLAGS = -pedantic-errors -std=c++11

wordle.o: wordle.cpp wordle.h
	g++ $(FLAGS) -c $<

wordle_main.o: wordle_main.cpp wordle.h
	g++ $(FLAGS) -c $<

wordle: wordle.o wordle_main.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f wordle wordle.o wordle_main.o wordle.tgz
tar:
	tar -czvf wordle.tgz *.cpp *.h

.PHONY: clean tar