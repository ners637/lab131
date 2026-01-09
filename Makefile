
compile:
	gcc main.c deque.c bubblesort.c heapsort.c -o main


run: compile
	./main --run


file: compile
	./main --file

heap10: compile
	./main --10 --heap

heap100: compile
	./main --100 --heap

heap1000: compile
	./main --1000 --heap

heap10000: compile
	./main --10000 --heap

heap100000: compile
	./main --100000 --heap

heapall: compile
	./main --10 --heap
	./main --100 --heap
	./main --1000 --heap
	./main --10000 --heap
	./main --100000 --heap

bubble10: compile
	./main --10 --bubble

bubble100: compile
	./main --100 --bubble

bubble1000: compile
	./main --1000 --bubble

bubble10000: compile
	./main --10000 --bubble

bubble100000: compile
	./main --100000 --bubble

bubbleall: compile
	./main --10 --bubble
	./main --100 --bubble
	./main --1000 --bubble
	./main --10000 --bubble
	./main --100000 --bubble


clean:
	rm -f main time.txt stalin.txt sorted.txt
