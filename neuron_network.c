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

// pour former la liste des neurpns d'une couche
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
    list enter = create();
    list output = create();
    int nbre;
    list sortie = create();// pour la sortie du reseau de neurone

    int nb_neur ; // pour le nombre de neurone du premier if

    if(nbre_layer == 1){
        printf("entrer le nombre d'entrees du neurone");
        scanf("%d",&nbre_inputs);
        layer lay = create();  // on cree la couche et on appelle initcouche
        lay = initCouche(head(nbre_neurL),nbre_inputs);


        enter = getInput(nbre_inputs);  // liste des entrees , recupere la valeur des entrées de la premiere couche

        reseau = add_tailLayer(reseau, lay); //et on ajoute la couche en queue du reseau

        sortie = outCouche(lay,enter);
        print(sortie);



    }
    else{
        printf("creation de la couche 1 \n");
        printf("entrer le nombre d'entrees pour les neurone de la couche1 \n");
        scanf("%d", &nbre_inputs);
        layer lay = create();
        lay = initCouche(head(nbre_neurL),nbre_inputs);
        nbre_neurL = reste(nbre_neurL);  // reste de le liste du nombre neurone par couche

        enter = getInput(nbre_inputs);  // liste des entrees , recupere la valeur des entrées de la premiere couche

        output = outCouche(lay,enter);  // liste des sorties , calcul la liste de sorties
        nbre=count(output);   // recupere le nombre des elements de la liste de sortie pour pouvoir creer la prochaine couche
        reseau = add_tailLayer(reseau, lay);






        for(int i=2;i<=nbre_layer;i++){
            printf("creation de la couche %d \n",i);
            layer lay2 = create();
            lay2 =initCouche(head(nbre_neurL),nbre) ;
            nbre_neurL = reste(nbre_neurL);
            reseau = add_tailLayer(reseau,lay2);
            output = outCouche(lay2,output);
            nbre = count(output);
            lay2 = NULL;
        }
        print(output);



    return reseau;
    }


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
    //layer lay=create();
  while (!is_empty(list_lyr)){

        //lay = tete_resNeur(list_lyr);
        print_layer(tete_resNeur(list_lyr));
        list_lyr=reste_resNeur(list_lyr);

    }

}
