
#include <stdio.h>
#include <stdlib.h>
//#include "weight_implementation.c"
#include "neuron_implementation.c"
//#include "layer_implementation.c"
#include"neuron_network.c"
int main(){


    int seuil , n_input , test;
    neuron neurone1;
    list list_input = create();
    list list_poids = create();

    layer lyr1=NULL;
    int n_neur ;
    list liste_out = create(); //liste de sortie du neurone

    int n_layer , n_neurL;
    list_layer res_neurL=create();
    list list_nbre_neurL = create();


      /* creation d'un neurone : partie 1 */

  /* printf(" ********creation d'un neurone : partie 1***********\n ");


        // demande du seuil a l'utilisateur
    printf(" Entrer le seuil du neurone \n ");
    scanf("%d", &seuil);

        // demande du nbre d'entrées a l'utilisateur
    printf("Entrer le nombre d'entrees du neurone \n");
    scanf( "%d" , &n_input);

        // demande du poids a l'utilisateur
    list_poids = match(n_input);

        // cretion du neurone
    neurone1 = InitNeur(n_input , seuil,list_poids );
    print_neur(neurone1);

        // pour recupere les valeurs des entrées du neurone
    list_input = getInput(n_input);

        // calcul de la sortie du neurone
    test = OutNeurone( neurone1, list_input);

        // afficher le resulat de la sortie de neurone
    printf(" La sortie de ce neurone est donc : %d \n" , test );
*/

        /* creation d'une couche de neurone : partie2 */
 /*   printf("**************creation d'une couche de neurone : partie2********** \n ");

        //Demande du nombre de neurone
    printf("Entrer le nombre de neurone pour la couche\n");
    scanf( "%d" , &n_neur);

     // demande du nbre d'entrées a l'utilisateur
    printf("Entrer le nombre d'entrees du neurone \n");
    scanf( "%d" , &n_input);

        //Creation de la couche de neurone
    lyr1 = initCouche(n_neur , n_input);

        //afficher la couche
    print_layer(lyr1);

        //calcul la liste des sorties de la couche
    liste_out = outCouche(lyr1,list_input);

        // Affiche la lisste des sorties de la couche
    printf("la liste des sorties de la couche est \n");
    print(liste_out);

*/
            /* creation du reseau de neurone : partie3 */
    printf("**************creation du reseau de neurone : partie3********** \n ");

        //demande du nombre de couche pour le reseau de neurone
    printf("Entrer le nombre de couche\n");
    scanf( "%d" , &n_layer);

        // pour recupere les valeurs du nombre de neurone par couche
    list_nbre_neurL = getNeuron(n_layer);

        // creation du reseau de neurone
    res_neurL = CreerResNeur ( n_layer, list_nbre_neurL);

        // afficher le reseau de neurone
   // print_list_layer(res_neurL);



return 0;

}
