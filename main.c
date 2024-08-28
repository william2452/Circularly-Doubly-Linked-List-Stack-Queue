#include "cirList.h"
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}


int main () {
	struct CirList *theCirList = malloc(sizeof(struct CirList));

    printf("-------------Testing Circularly Linked List Interface-------------\n");

	/*Initialize the circularly linked list */
	initCirList(theCirList);

	printf("-------------Testing addFrontCirList-------------\n");
	/*Add 3 to the back */
	addFrontCirList(theCirList, 3);
	/*Add 4 to the back */
	addFrontCirList(theCirList, 2);
	/*Add 5 to the back */
	addFrontCirList(theCirList, 1);

	printf("Print list - should print 1 2 3\n");
	printCirList(theCirList);


	printf("-------------Testing addBackCirList-------------\n");
	/*Add 2 to the front */
	addBackCirList(theCirList, 4);
	/*Add 1 to the front */
	addBackCirList(theCirList, 5);

	printf("Print list - should print 1 2 3 4 5\n");
	printCirList(theCirList);

	printf("-------------Testing frontCirList-------------\n");
	assertTrue(frontCirList(theCirList) == 1, "Testing frontCirList(theCirList) == 1 ");

	printf("-------------Testing backCirList-------------\n");
	assertTrue(backCirList(theCirList) == 5, "Testing backCirList(theCirList) == 5 ");

    printf("-------------Testing removeFrontCirList-------------\n");
	removeFrontCirList(theCirList);
	assertTrue(frontCirList(theCirList) == 2, "Testing frontCirList(theCirList) == 2 ");
    removeFrontCirList(theCirList);
	assertTrue(frontCirList(theCirList) == 3, "Testing frontCirList(theCirList) == 3 ");
	assertTrue(backCirList(theCirList) == 5, "Testing backCirList(theCirList) == 5 ");

    printf("-------------Testing removeBackCirList-------------\n");
	removeBackCirList(theCirList);
	assertTrue(backCirList(theCirList) == 4, "Testing backCirList(theCirList) == 4 ");
    removeBackCirList(theCirList);
	assertTrue(frontCirList(theCirList) == 3, "Testing frontCirList(theCirList) == 3 ");
	assertTrue(backCirList(theCirList) == 3, "Testing backCirList(theCirList) == 3 ");


    printf("-------------Testing isEmptyCirList-------------\n");
	assertTrue(isEmptyCirList(theCirList) == 0, "Testing isEmptyCirList(theCirList) == 0 ");
	removeBackCirList(theCirList);
	assertTrue(isEmptyCirList(theCirList) == 1, "Testing isEmptyCirList(theCirList) == 1 ");

	printf("-------------Testing freeCirList-------------\n");
	freeCirList(theCirList);

    printf("-------------Testing Stack Interface-------------\n");

    struct Stack *s = malloc(sizeof(struct Stack));
    initStack(s);

    printf("-------------Testing push-------------\n");
    push(s, 20);
    push(s, 25);
    push(s, 15);
    assertTrue(frontCirList(s->lst) == 15, "Testing frontCirList(s->lst) == 15 ");
	assertTrue(backCirList(s->lst) == 20, "Testing backCirList(s->lst) == 20 ");

    printf("-------------Testing pop-------------\n");
    pop(s);
    assertTrue(frontCirList(s->lst) == 25, "Testing frontCirList(s->lst) == 25 ");
    pop(s);
	assertTrue(frontCirList(s->lst) == 20, "Testing frontCirList(s->lst) == 20 ");
	assertTrue(backCirList(s->lst) == 20, "Testing backCirList(s->lst) == 20 ");

	printf("-------------Testing peek-------------\n");
    assertTrue((peek(s) == 20), "Testing peek(s->lst) == 20 ");



    printf("-------------Testing Queue Interface-------------\n");

    struct Queue *q = malloc(sizeof(struct Queue));
    initQueue(q);

    printf("-------------Testing enqueue-------------\n");
    enqueue(q, 8);
    enqueue(q, 7);
    enqueue(q, 6);
    enqueue(q, -6);
    enqueue(q, 2);
    assertTrue(frontCirList(q->lst) == 2, "Testing frontCirList(q->lst) == 2 ");
	assertTrue(backCirList(q->lst) == 8, "Testing backCirList(q->lst) == 8 ");

    printf("-------------Testing dequeue-------------\n");
    dequeue(q);
    assertTrue(frontCirList(q->lst) == 7, "Testing frontCirList(q->lst) == 7 ");
    dequeue(q);
    assertTrue(frontCirList(q->lst) == 6, "Testing frontCirList(q->lst) == 6 ");
    assertTrue(backCirList(q->lst) == 2, "Testing backCirList(q->lst) == 2 ");

    printf("-------------Testing getFront & getBack-------------\n");
    assertTrue(frontCirList(q->lst) == getFront(q), "Testing frontCirList(q->lst) == getFront(q)");
    assertTrue(backCirList(q->lst) == getBack(q), "Testing backCirList(q->lst) == getBack(q)");

	return 0;
}
