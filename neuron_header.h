#ifndef NEURON_HEADER_H_INCLUDED
#define NEURON_HEADER_H_INCLUDED
#include"weight_header.h"

typedef struct elem {
   int biais ;
   list  list_weight  ;
} neuron  ;   // structure de neurone



list match ( int n, int weight );

neuron InitNeur( int nbre_input , int seuil, int weight);
list getInput(int nb_input);
int enable (list list_input, list list_weight);// fonction d'activation

int OutNeurone( neuron neur, list list_inputs );

void print_neur(neuron neur);


#endif // NEURON_HEADER_H_INCLUDED
