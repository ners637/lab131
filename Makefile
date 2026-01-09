
compile: main2.c deque2.c bubblesort2.c heapsort2.c
	gcc main2.c deque2.c bubblesort2.c heapsort2.c -o main

run: compile
	./main --run

10: compile
	./main --10

100: compile
	./main --100

1000: compile
	./main --1000

10000: compile
	./main --10000

100000: compile
	./main --100000

all_numbers: compile
	./main --10
	./main --100
	./main --1000
	./main --10000
	./main --100000

all: all_numbers 

clean:
	rm -f main time.txt stalin.txt sorted.txt
