#include <cassert>
#include "ag.h"

using HashToString = map<int, string>;
using StringToHash = map<string, int>;

int cryptohash(const string& original) {
	string hashed = md5(original);
	hashed.resize(SIZE_HASH);
	return stoi(hashed, nullptr, 16);
}

StringToHash create_messages() {
	default_random_engine generator;
	StringToHash messages;
	string created;
	int random;

	for (int i = 0; i < SIZE_M; i++) {
		created = string(SIZE_STR, ' ');
		random = generator();

		do
			for (int i = 0; i < SIZE_STR; i++) {
				created[i] = random % 26 + 'a';
				random /= 26;

				if (random == 0)
					random = generator();
			}
		while (messages.find(created) != messages.end());

		messages[created] = cryptohash(created);
	}

	return messages;
}

HashToString find_collisons(const HashToString& hashes, int n_messages, StringToHash::const_iterator& iterator) {
	HashToString collisions;

	for (int i = 0; i < n_messages; i++) {
		if (hashes.count(iterator->second) > 0)
			collisions[iterator->second] = iterator->first;

		iterator++;
	}

	return collisions;
}

const StringToHash message_set = create_messages();

int execute(int m1, int m2, int m3){
	HashToString hashes1, hashes2, hashes3;
	auto iterator = message_set.begin();

	assert((m1 + m2 + m3) == SIZE_M);

	for (int i = 0; i < m1; i++) {
		hashes1[iterator->second] = iterator->first;
		iterator++;
	}

	hashes2 = find_collisons(hashes1, m2, iterator);
	hashes3 = find_collisons(hashes2, m2, iterator);

	return hashes3.size();
}

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
	int aux[4], pos1 = random()%3, pos2 = random()%3;

	for(size_t i = 0; i < 3; i++){

		if(i == pos1 || i == pos2){
			solutions[POP + range - 1][i] = parent2[i];
			solutions[POP + range][i] = parent1[i];

		}else{
			solutions[POP + range - 1][i] = parent1[i];
			solutions[POP + range][i] = parent2[i];
		}
	}

	solutions[POP + range - 1][3] = execute(solutions[POP + range - 1][0],solutions[POP + range - 1][1],solutions[POP + range - 1][2]);
	solutions[POP + range][3]= execute(solutions[POP + range][0],solutions[POP + range][1],solutions[POP + range][2]);

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
