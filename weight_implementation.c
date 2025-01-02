//#include<stdio.h>
//#include<stdlib.h>

#include "weight_header.h"


// verify if list is empty or not
int is_empty(list l) {
    if (l == NULL) {
        return 1;
    } else {
        return 0;
}
}


// head list
 int head( list l ){
 return l->val ;
 }

// le reste de la liste
list reste(list l){
return l->suiv ;
}

// create list
list create(){
    return NULL ;
}

// count element of list
int count(list l ){

  if ( is_empty(l)){
    return 0 ;
  }else{
    return 1 + count(reste(l)) ;
  }
}


// add in head
list add_head(list l , int e){
list temp;
temp=(element *) malloc(sizeof(element));
temp->val=e;
temp->suiv=l;
return temp;
}

// add in tail
list add_tail(list l , int e){
list temp;
list p;
temp=(element *) malloc(sizeof(element));
temp->val=e;
temp->suiv=NULL;
if(l == NULL) {
       l=temp;
    } else {
p= l;
while (p->suiv !=NULL) { p=p->suiv;
}
p->suiv=temp; }
return l;
}


// supprimer en queue
list remove_tail_list(list l ) { if (l != NULL) {
if (l->suiv == NULL) { free(l);
           l=NULL;
       } else {
list p=l;
while (p->suiv->suiv!=NULL) { p=p->suiv;
}
free(p->suiv);
p->suiv=NULL; }
}
return l;
}

//supprimer en tete
list remove_head(list l) { list p;
    if (l == NULL) {
       p=NULL;
} else { p=l->suiv;
free(l); }
return p;
}

// supprimer toute la liste
list remove_all_list(list l){

while (!is_empty(l)){
    l = remove_head(l);
    l=l->suiv;
}
return l ;
}



// print list
void print(list l){

if( is_empty(l) ) {
printf(" *** EMPTY LIST *** \n");
    } else {
       list p=l;
      printf ("[ " );
      while (p->suiv !=NULL) {
      printf("%d ", p->val);
      p=p->suiv; }
      printf (" %d ]\n",p->val);
    }
}

