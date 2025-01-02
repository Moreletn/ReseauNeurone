#ifndef WEIGHT_HEADER_H_INCLUDED
#define WEIGHT_HEADER_H_INCLUDED



typedef struct elemt {
   int val ;
   struct elemt * suiv ;
} element ;

typedef element  * list;

// definition of bool type


int is_empty(list l);

int head ( list l );

list reste ( list l );

list create();

int count(list l );

list add_head(list l , int e);

list add_tail(list l , int e);

void print(list l);


#endif // WEIGHT_HEADER_H_INCLUDED
