#include <stdio.h>
#include <sys/queue.h>

struct foo {
    TAILQ_ENTRY(foo) tailq;
    int datum;
};

struct foo foo (int val) {
    struct foo x = { { 0, 0 }, val };
    return x;
}

TAILQ_HEAD(fooq, foo);

int main ()
{
    struct fooq q;
    struct foo data[3] = { foo(3), foo(7), foo(1) };
    struct foo *p;

    TAILQ_INIT(&q);
    TAILQ_INSERT_HEAD(&q, &data[0], tailq);
    TAILQ_INSERT_AFTER(&q, &data[0], &data[1], tailq);
    TAILQ_INSERT_TAIL(&q, &data[2], tailq);

    TAILQ_FOREACH(p, &q, tailq) {
        printf(" %d", p->datum);
    }
    puts("");

    TAILQ_FOREACH_REVERSE(p, &q, fooq, tailq) {
        printf(" %d", p->datum);
    }
    puts("");

    while (!TAILQ_EMPTY(&q)) {
        p = TAILQ_FIRST(&q);
        TAILQ_REMOVE(&q, p, tailq);
    }

    return 0;
}
