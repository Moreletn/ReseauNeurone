#ifndef NEURON_NETWORK_H_INCLUDED
#define NEURON_NETWORK_H_INCLUDED
#include"weight_header.h"
#include"layer_header.h"

typedef struct n_res {
   layer val_lyr;
   struct n_res * suiv_lyr ;
} n_network ;  // un element d'un reseau de neurone

list getNeuron(int nb_neuron);
typedef n_network* list_layer;  // une liste de couche

list_layer CreerResNeur (int nbre_layer, list nbre_neurL);

#endif // NEURON_NETWORK_H_INCLUDED
