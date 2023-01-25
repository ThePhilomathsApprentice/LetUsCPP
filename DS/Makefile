fresh: q
	rm -rf bin/*

q: tail
	./bin/q.out

tail: src/tailq.c
	gcc src/tailq.c -o bin/q.out
