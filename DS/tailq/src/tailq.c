#include <stdio.h>
#include <sys/queue.h>


/* ======================================================================= */

/* struct node declaration,
 * This is the struct whose tailq will be created.
 */
struct node {
    TAILQ_ENTRY(node) tailq;
    int data;
};
typedef struct node node_t;


/* struct nodeListHead will be declared such that,
 * it has FIRST and LAST pointers to struct node variable.
 */
TAILQ_HEAD(nodeListHead, node);
typedef struct nodeListHead nodeListHead_t;

/* ======================================================================= */

/* Function nodeInit,
 * initialises int variable data to the value passed as argument and
 * returns an object of struct node.
 */
node_t nodeInit (int val) {
    node_t x = { { 0, 0 }, val };
    return x;
}

void printTailq (nodeListHead_t* headTailq) {

    /* iterator pointer to be used during traversal. */
    node_t *itr = NULL;

    printf("Printing tailq now.\n");
    TAILQ_FOREACH(itr, headTailq, tailq) {
        printf(" prev_pointer(%p):current_pointer(%p):date(%d):next_pointer(%p)\n",
                    *(itr->tailq.tqe_prev),
                    itr,
                    itr->data,
                    itr->tailq.tqe_next);
    }
    printf("\n");

}

/* ======================================================================= */

/* Main function.
 */
int main ()
{
    /* Declare variables of tyoe nodeListHead_t.
     * This variables will hold the FIRST and LAST node details of their respective tailqs.
     */
    nodeListHead_t q1;
    nodeListHead_t head2;

    /* data array initialised to use as our sample data/nodes for both queues. */
    node_t data[3] = { nodeInit(1), nodeInit(2), nodeInit(3) };
    node_t data2[4] = { nodeInit(5), nodeInit(6), nodeInit(7), nodeInit(8) };

    /* iterator pointer to be used during traversal. */
    node_t *itr = NULL;

    /* Initialise both the heads of the tailq. */
    TAILQ_INIT(&q1);
    TAILQ_INIT(&head2);

    /* Print fresh tailqs */
    printTailq(&q1);
    printTailq(&head2);


    /* Initialise tailqs */
    TAILQ_INSERT_HEAD(&q1, &data[0], tailq);
    TAILQ_INSERT_TAIL(&q1, &data[1], tailq);
    TAILQ_INSERT_AFTER(&q1, &data[0], &data[2], tailq);

    TAILQ_INSERT_HEAD(&head2, &data2[0], tailq);
    TAILQ_INSERT_TAIL(&head2, &data2[1], tailq);
    TAILQ_INSERT_AFTER(&head2, &data2[0], &data2[2], tailq);
    TAILQ_INSERT_TAIL(&head2, &data2[3], tailq);


    /* print initialised tailqs*/
    printTailq(&q1);
    printTailq(&head2);


    /* Manipulate the tailqs.*/



    /* Clear the tailqs. */
    while (!TAILQ_EMPTY(&q1)) {
        itr = TAILQ_FIRST(&q1);
        TAILQ_REMOVE(&q1, itr, tailq);
    }

    while (!TAILQ_EMPTY(&head2)) {
        itr = TAILQ_FIRST(&head2);
        TAILQ_REMOVE(&head2, itr, tailq);
    }

    printTailq(&q1);
    printTailq(&head2);

    return 0;
}
