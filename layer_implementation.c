#include"layer_header.h"

neuron tete_layer(layer lay){
    return lay->neur;
}
layer reste_layer(layer lay){
    return lay->suiv_neuron;
}

// ajout en queue d'un neurone
layer add_tailNeur(layer lyr , neuron nrn){
layer temp;
layer p;
temp=(neurone *) malloc(sizeof(neurone));
temp->neur=nrn;
temp->suiv_neuron=NULL;
if(lyr == NULL) {
       lyr=temp;
    } else {
p= lyr;
while (p->suiv_neuron !=NULL) {
        p=p->suiv_neuron;
    }
p->suiv_neuron=temp; }
return lyr;
}
/*

// supprimer en queue
layer remove_tailNeur(layer lyr) { if (lyr != NULL) {
if (lyr->suiv_neuron == NULL) { free(lyr);
           lyr=NULL;
       } else {
layer p=lyr;
while (p->suiv_neuron->suiv_neuron !=NULL) { p=p->suiv_neuron;
}
free(p->suiv_neuron);
p->suiv_neuron=NULL; }
}
return lyr;
}
// supprimer toute la couche
layer remove_all_layer (layer lyr){

while (!is_empty(lyr)){
    lyr = remove_tailNeur(lyr);
}
return lyr ;
}
*/

//cretion d'une couche de neurone


layer initCouche (int nbre_neuron, int nbre_input){

 int seuil , weight ;
 neuron neur ;
layer lyr=create() ;

    for (int i=1;i<= nbre_neuron;i++)
    {

// pour demander le seuil pour chaque neurone
        printf("Entrer le biais du neuron %d \n" ,i );
        scanf("%d" , &seuil);

        printf(" Entrer le poids du neuron %d \n" , i);
        scanf("%d" , &weight);


        neur = InitNeur(nbre_input,seuil,weight);
        lyr = add_tailNeur(lyr , neur);

    }

    return lyr ;

}


list outCouche (layer lyr, list list_input){

list list_output = NULL ;
 while(!is_empty(lyr)){
        list_output=add_tail(list_output,OutNeurone((tete_layer(lyr)),list_input));
        lyr=reste_layer(lyr);

 }
return list_output ;

}



void print_layer(layer lyr){

    while (!is_empty(lyr)){
        print_neur(tete_layer(lyr));
        lyr=reste_layer(lyr);
    }

}
