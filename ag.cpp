#include <cstdlib>
// #include <iostream>

#include "ag.h"

using namespace std;

void exchange(int element1[4], int element2[4]){
	int i;

	for(i = 0; i < 4; i++){
		element1[i] = element2[i];
	}
}

void quickSort(int solutions[POP][N_SETS+1], int comeco, int fim, int pos){
	int pivot,aux[N_SETS+1];
	int i, j;

	pivot = (comeco+fim)/2;
	i = comeco;
	j = fim;

	while(i <= j){
		while(solutions[i][pos] < solutions[pivot][pos])
			i++;

		while(solutions[j][pos] > solutions[pivot][pos])
			j--;

		if(i <= j){
			exchange(aux,solutions[i]);
			exchange(solutions[i],solutions[j]);
			exchange(solutions[j],aux);
			i++;j--;
		}
	}

	if(j > comeco)
		quickSort(solutions, comeco, j, pos);

	if(i < fim)
		quickSort(solutions, j+1, fim, pos);

}

bool verify(int *vet, int number, int range){
	int i;
	for(i = 0; i < range; i++){
		if(vet[i] == number){
			return false;
		}
	}
	return true;
}

int maxelement(int solutions[POP][4], int *tournamentelements, int tour){

	int i, max = 0;

	for(i = 0; i < tour; i++){
		if(solutions[tournamentelements[max]][3] < solutions[tournamentelements[i]][3]){
			max = i;
		}
	}
	return tournamentelements[max];
}

void crossover(int solutions[POP][4], int parent1[4], int parent2[4], int range){
	int aux[4], pos = random()%3;
	int adjustment = (parent1[pos] - parent2[pos]) / 2;
	int child2 = POP + range;
	int child1 = child2 - 1;

	// clog << "Parent 1: " << parent1[0] << '\t' << parent1[1] << '\t' << parent1[2] << endl;
	// clog << "Parent 2: " << parent2[0] << '\t' << parent2[1] << '\t' << parent2[2] << endl;

	for(size_t i = 0; i < 3; i++){
		if(i == pos){
			solutions[child1][i] = parent2[i];
			solutions[child2][i] = parent1[i];

		}else{
			solutions[child1][i] = parent1[i] + adjustment;
			solutions[child2][i] = parent2[i] - adjustment;
		}
	}

	// clog << "Child 1: " << solutions[child1][0] << '\t' << solutions[child1][1] << '\t' << solutions[child1][2] << endl;
	// clog << "Child 2: " << solutions[child2][0] << '\t' << solutions[child2][1] << '\t' << solutions[child2][2] << endl;

	solutions[child1][3] = execute(solutions[child1][0],solutions[child1][1],solutions[child1][2]);
	solutions[child2][3]= execute(solutions[child2][0],solutions[child2][1],solutions[child2][2]);

}

int search(int vet[3], int value){
	int i;
	for(i = 0; i < 3; i++){
		if(vet[i] == value){
			return i;
		}
	}
	return i;
}
