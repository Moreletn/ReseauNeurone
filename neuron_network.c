//#include<stdio.h>
//#include<stdlib.h>
#include"neuron_network.h"
#include "layer_implementation.c"


layer tete_resNeur(list_layer list_lay){
    return list_lay->val_lyr;
}
list_layer reste_resNeur(list_layer list_lay){
    return list_lay->suiv_lyr ;
}

// ajout en queue d'un neurone
list_layer add_tailLayer(list_layer list_lay, layer lay){
list_layer temp;
list_layer p;
temp=( n_network *) malloc(sizeof( n_network ));
temp->val_lyr=lay;
temp->suiv_lyr=NULL;
if(lay == NULL) {
       lay=temp;
    } else {
p= lay;
while (p->suiv_lyr !=NULL) {
        p=p->suiv_lyr;
    }
p->suiv_lyr=temp; }
return lay;
}
list getNeuron(int nb_neuron){
    int entree;
    list list_entree = create();
   for(int i = 1;i<=nb_neuron; i++)
    {
        printf("Veuillez fournir le nombre de neurones de la couche %d \n", i);
        scanf("%d",&entree);
        list_entree = add_tail(list_entree, entree);
    }
    return list_entree;
}





list_layer CreerResNeur (int nbre_layer, list nbre_neurL){
    int nbre_inputs;
    list_layer reseau = create();
    printf("entrer le nombre d'entrees pour chaque neurone");
    scanf("%d", &nbre_inputs);

        printf("les informations de la premiere couche ");
        layer lay = create();
        lay = initCouche(head(nbre_neurL),nbre_inputs);
        reseau = add_tailLayer(reseau,lay);

    return reseau;


}






/*list_layer CreerResNeur (int nbre_layer, list nbre_neurL){

int nbre_input;
layer lyr=create();
list_layer list_lyr=create();


    for (int i=1;i<= nbre_layer;i++)
    {

// pour demander le nbre d'entrees par couche
        printf("give the number of  for  %d \n" ,i );
        scanf("%d" , &nbre_input);

        lyr = initCouche (tete(nbre_neurL),nbre_input);
        list_lyr = add_tailLayer(list_lyr , lyr);
    }
    return list_lyr;

}*/

void print_list_layer(list_layer list_lyr){
    layer lay=create();
  while (!is_empty(list_lyr)){
        lay = tete_resNeur(list_lyr);
        print_layer(lay);
        list_lyr=reste_resNeur(list_lyr);

    }

}
