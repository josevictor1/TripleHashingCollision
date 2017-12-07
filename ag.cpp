#include "ag.h"

string create_random_string() {
	static set<string> created;
	static default_random_engine generator;

	int random = generator();
	string str = string(SIZE_STR, ' ');

	do
		for (int i = 0; i < SIZE_STR; i++) {
			str[i] = random % 26 + 'a';
			random /= 26;

			if (random == 0)
				random = generator();
		}
	while ( !created.insert(str).second );
	// clog << created.size() << '\r';

	return str;
}

string cryptohash(const string& original) {
	string hashed = md5(original);
	hashed.resize(SIZE_HASH);
	return hashed;
}

/*inline void show(const HashedToOriginal& hashes) {
	clog << "String\t\tHash" << endl;

	for (auto i = hashes.begin(); i != hashes.end(); ++i)
		clog << i->second << '\t' << i->first << endl;

	clog << endl;
}*/

HashedToOriginal find_collisons(const HashedToOriginal& hashes, int n_messages) {
	HashedToOriginal collisions;
	string hashed, random;

	for (int i = 0; i < n_messages; i++) {
		try {
			random = create_random_string();
			hashed = cryptohash(random);

			//cout << hashes.at(hashed) << endl; 
			//cout << random << endl;
			if (hashes.at(hashed) != random)
				collisions[hashed] = random;
		}

		catch (exception& e) {}
	}

	return collisions;
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

void exchange(int element1[4], int element2[4]){
    int i;

    for(i = 0; i < 4; i++){
        element1[i] = element2[i];
    }
}

int execute(int m1, int m2, int m3){
    HashedToOriginal hashes1, hashes2, hashes3;
    string random;

    for (int i = 0; i < m1; i++) {
        random = create_random_string();
        hashes1[cryptohash(random)] = random;
    }

    // show(hashes1);

    hashes2 = find_collisons(hashes1, m2);
// show(hashes2);

    hashes3 = find_collisons(hashes2, m2);
// show(hashes3);

    //cout << hashes3.size() << " collisions" << endl;

    return hashes3.size();
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
    int aux[4], pos1 = random()%3, pos1 = random()%3;
    
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
/*
void crossover(int solutions[POP][4], int parent1[4], int parent2[4], int number, int range){
    
    int aux[4], current, i;
    memset(aux, -1, sizeof aux);
    aux[number] = parent1[number];
    current = search(parent1,parent2[number]);
    while(aux[number]%3 != parent1[current]%3){
        aux[current] = parent1[current];
        current = search(parent1, parent2[current]);
    }
    for(i = 0;i < 3; i++){

        if(aux[i] != -1){
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
*/
int search(int vet[3], int value){
    int i;
    for(i = 0; i < 3; i++){
        if(vet[i] == value){
            return i;
        }
    }
    return i;
}

