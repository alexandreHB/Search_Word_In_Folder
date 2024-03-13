app : wordList.o main.o
	g++ -o app wordList.o main.o

wordList.o : wordList.cpp wordList.hpp
	g++ -c wordList.cpp -std=c++20

main.o : main.cpp main.hpp 
	g++ -c main.cpp -std=c++20

clean:
	rm -rf *.o
	rm -f app
