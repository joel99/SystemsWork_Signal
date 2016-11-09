compile: signal.c
	gcc signal.c -o signal

run:
	./signal

clean:
	rm *~
