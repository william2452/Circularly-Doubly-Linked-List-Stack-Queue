#ifndef __CIRLIST_H
#define __CIRLIST_H

# ifndef TYPE
# define TYPE int
# define TYPE_SIZE sizeof(int)
# endif

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

/*Structure for the circularly linked list*/
struct CirList{
	struct DLink* sentinel; /*Sentinel of the list*/
};

/*Structure for the stack*/
struct Stack{
	struct CirList *lst;/*Circularly Linked list that implements the stack*/
	int size;
};

/*Structure for the queue*/
struct Queue{
	struct CirList *lst;/*Circularly Linked list that implements the queue*/
	int size;
};

/*Circularly Linked list with sentinel*/
void initCirList(struct CirList *lst);
void addFrontCirList(struct CirList *lst, TYPE val);
void addBackCirList(struct CirList *lst, TYPE val);
void printCirList(struct CirList *lst);
TYPE frontCirList(struct CirList *lst);
TYPE backCirList(struct CirList *lst);
void removeFrontCirList(struct CirList *lst);
void removeBackCirList(struct CirList *lst);
int isEmptyCirList(struct CirList *lst);
void freeCirList(struct CirList *lst);

/* Stack interface*/
void initStack(struct Stack *s);
void push(struct Stack *s, TYPE val);
void pop(struct Stack *s);
TYPE peek(struct Stack *s);
int isEmptyStack(struct Stack *s);
void freeStack(struct Stack *s);

/* Queue interface*/
void initQueue(struct Queue* q);
void enqueue(struct Queue* q, TYPE val);
void dequeue(struct Queue* q);
TYPE getFront(struct Queue* q);
TYPE getBack(struct Queue* q);
int isEmptyQueue(struct Queue* q);
void freeQueue(struct Queue* q);

#endif
