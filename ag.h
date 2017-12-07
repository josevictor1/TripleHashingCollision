#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include "md5.h"

#define SIZE_HASH	4
#define SIZE_M      10000
#define N_SETS      3
#define SIZE_STR	10

#define POP  100
#define TPOP 180
#define NGER 1000
#define TOUR 3
#define TCROSS int(POP*0.4)
#define PMUT 20

using namespace std;

string create_random_string();
int execute(int m1, int m2, int m3);
void crossover(int solutions[TPOP][4], int parent1[4], int parent2[4], int number, int range);
int search(int vet[10], int value);
void quickSort(int solutions[POP][N_SETS+1], int comeco, int fim, int pos);
void exchange(int element1[4], int element2[4]);
bool verify(int *vet, int number, int range);
int maxelement(int solutions[TPOP][4], int *tournamentelements, int tour);
