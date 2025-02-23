//#include<stdio.h>
//#include<stdlib.h>
#include"neuron_header.h"
#include"weight_implementation.c"


// methode pour creer une liste de poids
list match ( int n ){  // n representant le nombre d'entr�es

int weight;
list inter = NULL; // nom de la liste inter

    for ( int i=1 ; i<=n ; i++){

        printf("Veuillez fournir le poids de l'entree %d \n", i);
        scanf("%d",&weight);

        inter=add_tail(inter , weight);
    }
    return inter ;
}


neuron InitNeur( int nbre_input , int seuil, list list_poids){
    neuron neur;
    neur.biais = seuil ;
    neur.list_weight = list_poids;
     // a enlever

    return neur ;
}

// pour recuperer les valeurs des entrees

list getInput(int nb_input){
    int entree;
    list list_entree = create();
   for(int i = 1;i<=nb_input; i++)
    {
        printf("Veuillez fournir la valeur de l'entree %d \n", i);
        scanf("%d",&entree);
        list_entree = add_tail(list_entree, entree);
    }
    return list_entree;
}



// fonction d'activation
int enable (list list_input, list list_weight){

    if(list_input == NULL || list_weight==NULL ){
        return 0 ;
    } else {
        return (head(list_input)*head(list_weight))+ enable(reste(list_input) ,reste(list_weight));
    }



}

int OutNeurone( neuron neur, list list_inputs ){

int x = enable(list_inputs,neur.list_weight) ;
if ( x<neur.biais){
    return 0 ;
} else {
    return 1 ;
}
}

// pour l'affichage des neurones
void print_neur(neuron neur){
    printf("le neuron est donc \n");
    printf("le biais est %d \n" , neur.biais );
    printf("la liste des poids est \n");
    print(neur.list_weight);
    printf("..... \n");

}
