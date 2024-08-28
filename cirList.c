#include "cirList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/*
	initCirList: Initialize the circularly linked list
	param:  c pointer to the circularly linked list
	pre: c is not null
	post: memory for c->Sentinel is dynamically allocated
	post: Sentinel links are initialized to point to the sentinel
*/
void initCirList(struct CirList *c) {
	assert(c != NULL);

    c->sentinel = malloc(sizeof(struct DLink));

    c -> sentinel -> value = 0;
    /*Setting value to 0 to indicate that it's an empty node.
    I was getting too many errors without having a value initialized.
    It was adding a random extra node at the end of the CirList.*/

    c->sentinel->next = c->sentinel;
    c->sentinel->prev = c->sentinel;
}

/*
	addFrontCirList: Adds a link to the front of  the circularly linked list
	param: c pointer to the circularly linked list
	param: val value for the link to be added
	pre: c is not null
	post: a link storing val is added to the front of the circularly linked list
	post: memory is dynamically allocated for the new link
	post: pointers have been adjusted
	HINT: there are 4 pointers to update
	HINT: in an empty list the front and back point to the new link
*/
void addFrontCirList(struct CirList *c, TYPE val) {
	printf("Add to front: %d\n", val);
	/* FIX ME*/
	assert(c != NULL);

    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink -> value = val;

    if(c -> sentinel -> value == 0) {
        newLink -> next = newLink;
        newLink -> prev = newLink;
        c -> sentinel -> prev = newLink;
        c -> sentinel -> next = newLink;
        c -> sentinel = newLink;
    } else {
        newLink -> next = c -> sentinel;
        newLink -> prev = c -> sentinel -> prev;
        c -> sentinel -> prev -> next = newLink;
        c -> sentinel -> prev = newLink;
        c -> sentinel = newLink;
    }
}

/*
	addBackCirListDeque: Adds a link to the back of  the circularly linked list
	param: c pointer to the circularly linked list
	param: val value for the link to be added
	pre: c is not null
	post: a link storing val is added to the back of the circularly linked list
	post: memory is dynamically allocated for the new link
	post: pointers have been adjusted
	HINT: there are 4 pointers to update
	HINT: in an empty list the front and back point to the new link
*/
void addBackCirList (struct CirList *c, TYPE val) {
	printf("Add to back %d \n", val);
	/* FIX ME*/
    assert(c != NULL);

    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink -> value = val;

    newLink -> next = c -> sentinel;
    newLink -> prev = c -> sentinel -> prev;
    c -> sentinel -> prev -> next = newLink;
    c -> sentinel -> prev = newLink;
}


/*
	printCirList: Print the links in the circularly linked list from front to back
	param: c pointer to the circularly linked list
	pre: c is not null and q is not empty
	post: the links in the circularly linked list are printed from front to back
	post: no changes to the circularly linked list
*/
void printCirList(struct CirList *c) {
	/* FIX ME*/
    assert(c != NULL);

    struct DLink *curr = c -> sentinel;

    do {
        printf("%d ", curr -> value);
        curr = curr -> next;
    } while(curr != c -> sentinel);

	printf("\n");
}



/*
	frontCirList: Get the value of the front of the circularly linked list
	param: c pointer to the circularly linked list
	ret: value of the front of the circularly linked list
	pre: c is not null
	pre: c is not empty
	post: no changes to the circularly linked list
*/
TYPE frontCirList(struct CirList *c) {
	/* FIX ME*/
    assert(c != NULL);
    assert(c -> sentinel != NULL);

	return c -> sentinel -> value;
}

/*
	backCirListD: Get the value of the back of the circularly linked list
	param: c pointer to the circularly linked list
	ret: value of the back link in the circularly linked list
	pre: c is not null
	pre: c is not empty
	post: no changes to the circularly linked list
*/
TYPE backCirList(struct CirList *c) {
	/* FIX ME*/
    assert(c != NULL);
    assert(c -> sentinel != NULL);

	return c -> sentinel -> prev -> value;
}

/*
	removeFrontCirList: Remove the front of the circularly linked list
	param: c pointer to the circularly linked list
	pre: c is not null
	pre: c is is not empty
	post: the front node is removed from the circularly linked list
	post: memory is freed for the front link
	post: pointers are adjusted
*/
void removeFrontCirList(struct CirList *c) {
	assert(c != 0);
	assert(c -> sentinel != NULL);
	printf("Remove front: %d\n", c->sentinel->next->value);
	/* FIX ME*/

    struct DLink *curr = c -> sentinel;

    c -> sentinel -> next -> prev = c -> sentinel -> prev;
    c -> sentinel = c -> sentinel -> next;
    free(curr);
    curr = 0;
}


/*
	removeBackCirList: Remove the back of the circularly linked list
	param: c pointer to the circularly linked list
	pre: c is not null
	pre: c is is not empty
	post: the back node is removed from the circularly linked list
	post: memory is freed for the back link
	post: pointers are adjusted
*/
void removeBackCirList(struct CirList *c) {
	assert(c != 0);
	assert(c -> sentinel != NULL);
	printf("Remove back: %d\n", c->sentinel->prev->value);
	/* FIX ME*/

    struct DLink *curr = c -> sentinel -> prev;

    if(c -> sentinel -> prev == c -> sentinel){
        c -> sentinel -> prev = c -> sentinel;
        c -> sentinel -> prev -> next = c -> sentinel;
        c -> sentinel = 0;
    } else {
        c -> sentinel -> prev -> prev -> next = c -> sentinel;
        c -> sentinel -> prev = c -> sentinel -> prev -> prev;
    }
    free(curr);
    curr = 0;

}

/*
	isEmptyCirList: Check whether the circularly linked list is empty
	param: c pointer to the circularly linked list
	ret: 1 if the circularly linked list is empty - otherwise return 0
	pre: c is not null
*/
int isEmptyCirList(struct CirList *c) {
	/* FIX ME*/

	if(c -> sentinel == NULL) {
        return 1;
	} else {
        return 0;
	}
}



/*
	freeCirList: Free all links of the circularly linked list
	param: c pointer to the circularly linked list
	pre: c is not null
	post: All links including sentinel have been freed
*/
void freeCirList(struct CirList *c) {
	/* FIX ME*/
    assert(c != NULL);

    if(c -> sentinel == NULL) {
        return;
    }/*If list is empty, return early because there is no memory to free*/

    struct DLink *curr = c -> sentinel;
    struct DLink *freeLink = curr;

    while(curr != c -> sentinel -> prev) {
        freeLink = curr;
        free(freeLink);
        freeLink = 0;
        curr = curr -> next;
    }
    free(c);
    c = 0;
}


/***********************************Stack Interface***********************************/


/*
	initStack: Initialize the stack
	param: s pointer to the stack
	pre: s is not null
	post: memory is allocated for the underlying circularly linked list
	post: size is set to 0
	post: s->lst is passed to initCirList()
*/
void initStack(struct Stack *s) {
    printf("Init stack\n");
    s->lst = malloc(sizeof(struct CirList));
    initCirList(s->lst);
    s->size = 0;
}

/*
	push: Add to the stack
	param: s pointer to the stack
	param: val value to be added
	pre: s is not null
	post: size is incremented
	post: an item has been pushed to the stack
	HINT: pass s->lst to a circularly linked list function
*/
void push(struct Stack *s, TYPE val) {
    /* FIX ME*/
    assert(s != 0);

    addFrontCirList(s -> lst, val);
    s -> size++;
}

/*
	pop: Pop from stack
	param: s pointer to the stack
	pre: s is not null
	pre: s lst is not empty
	post: size is decremented
	post: an item has been popped from the stack
	HINT: pass s->lst to a circularly linked list function
*/
void pop(struct Stack *s) {
    /* FIX ME*/
    assert(s != 0);
    assert(s -> size != 0);

    removeFrontCirList(s -> lst);
    s -> size--;
}

/*
	peek: Return the value at the top of the stack
	param: s pointer to the stack
	return: value of the top items of the stack
	pre: s is not null
	pre: s->lst is not empty
	post: value at the top of the stack is returned
	post: no changes to the stack
	HINT: pass s->lst to a circularly linked list function
*/
TYPE peek(struct Stack *s){
    /* FIX ME*/
    assert(s != 0);
    assert(s -> size != 0);

    return frontCirList(s -> lst);
}

/*
	isEmptyStack: Determine if the stack is empty
	param: s pointer to the stack
	return: int - 1 for true, 0 for false
	pre: s is not null
	post: no changes to the stack
*/
int isEmptyStack(struct Stack *s) {
    /* FIX ME*/
    assert(s != 0);

    if(s -> size == 0) {
        return -1;
    } else {
        return 0;
    }
}

/*
	freeStack: Free memory for the stack and underlying list
	param: s pointer to the stack
	pre: s is not null
	post: memory has been freed for s->lst
	post: memory has been freed for the stack
*/
void freeStack(struct Stack *s) {
    /* FIX ME*/
    assert(s != 0);

    freeCirList(s -> lst);
    free(s);
    s = 0;
}


/***********************************Queue Interface***********************************/

/*
	initStack: Initialize the queue
	param: s pointer to the queue
	pre: s is not null
	post: memory is allocated for the underlying circularly linked list
	post: size is set to 0
	post: s->lst is passed to initCirList()
*/
void initQueue(struct Queue* q) {
    /* FIX ME*/
    assert(q != NULL);

    initCirList(q -> lst);
    q -> size = 0;
}

/*
	push: Add to the queue
	param: q pointer to the queue
	param: val value to be added
	pre: q is not null
	post: size is incremented
	post: an item has been added to the back to the queue
	HINT: pass q->lst to a circularly linked list function
*/
void enqueue(struct Queue* q, TYPE val){
    /* FIX ME*/
    assert(q != NULL);

    addFrontCirList(q -> lst, val);
    q -> size++;
}

/*
	dequeue: Remove from the queue
	param: q pointer to the queue
	pre: q is not null
    pre: q is not empty
	post: size is decremented
	post: an item has been removed from the front the queue
	HINT: pass q->lst to a circularly linked list function
*/
void dequeue(struct Queue* q) {
    /* FIX ME*/
    assert(q != NULL);
    assert(q -> size != 0);

    removeFrontCirList(q -> lst);
    q -> size--;
    /* I called the removeFrontCirList() function and it fails some tests,
    but it also fails with removeBackCirList(). Based on the numbers being
    checked, I think it is a mix of removeFrontCirList() and removeBackCirList()
    numbers that would pass the checks. */
}

/*
	getFront: Return the value at the front of the queue
	param: q pointer to the queue
	return: value of the top items of the queue
	pre: q is not null
	pre: q->lst is not empty
	post: value at the top of the queue is returned
	post: no changes to the queue
	HINT: pass s->lst to a circularly linked list function
*/
TYPE getFront(struct Queue* q) {
    /* FIX ME*/
    assert(q != NULL);
    assert(q -> size != 0);

    return frontCirList(q -> lst);

}

/*
	getBack: Return the value at the back of the queue
	param: q pointer to the queue
	return: value of the top items of the queue
	pre: q is not null
	pre: q->lst is not empty
	post: value at the back of the queue is returned
	post: no changes to the queue
	HINT: pass s->lst to a circularly linked list function
*/
TYPE getBack(struct Queue* q) {
    /* FIX ME*/
    assert(q != NULL);
    assert(q -> size != 0);

    return backCirList(q -> lst);
}

/*
	isEmptyQueue: Determine if the queue is empty
	param: q pointer to the queue
	return: int - 1 for true, 0 for false
	pre: q is not null
	post: no changes to the queue
*/
int isEmptyQueue(struct Queue* q) {
    /* FIX ME*/
    assert(q != NULL);

    if(q -> size == 0) {
        return -1;
    } else {
        return 0;
    }
}

/*
	freeQueue: Free memory for the queue and underlying list
	param: s pointer to the queue
	pre: s is not null
	post: memory has been freed for q->lst
	post: memory has been freed for the queue
*/
void freeQueue(struct Queue* q) {
    /* FIX ME*/
    assert(q != NULL);

    freeCirList(q -> lst);
    free(q);
    q = 0;
}


