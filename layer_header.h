#ifndef LAYER_HEADER_H_INCLUDED
#define LAYER_HEADER_H_INCLUDED
#include"neuron_header.h"


typedef struct elt {
   neuron neur ;
   struct elt * suiv_neuron ;
} neurone ;             // liste de neurone

typedef neurone * layer ;    // definition du type Couche

neuron tete_layer(layer lay);
layer reste_layer(layer lay);
layer add_tailNeur(layer lyr , neuron nrn);

layer initCouche (int nbre_neuron, int nbre_input);

list outCouche (layer lyr, list list_inputs);


void print_layer(layer lyr);



#endif // LAYER_HEADER_H_INCLUDED
