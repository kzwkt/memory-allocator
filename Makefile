default: run

run: simple
	./simple

simple: simple.c
	gcc -o $@ $<

buddy: buddy.c
	gcc -o $@ $<
