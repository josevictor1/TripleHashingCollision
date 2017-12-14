#include "cryptohash.h"

#define N_SETS 3
#define POP  50
#define TPOP 80
#define NGER 25
#define TOUR 3
#define PMUT 50

const int TCROSS = TPOP - POP;

void crossover(int solutions[TPOP][4], int parent1[4], int parent2[4], int child1);
int search(int vet[10], int value);
void quickSort(int solutions[][N_SETS+1], int comeco, int fim, int pos);
void exchange(int element1[4], int element2[4]);
bool verify(int *vet, int number, int range);
int maxelement(int solutions[TPOP][4], int *tournamentelements, int tour);
