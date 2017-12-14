#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "ag.h"

using namespace std;

int main() {
	int pop[TPOP][4];
	int parents[TCROSS];

	srand( time(NULL) );

	for(size_t i = 0; i < POP; i++){
		int generated;

		pop[i][2] = SIZE_M;

		for(size_t j = 0; j < 2; j++){
			generated = random();
			pop[i][j] = (generated % pop[i][2]) + 1;
			pop[i][2] -= pop[i][j];
		}

		// clog << pop[i][0] << '\t' << pop[i][1] << '\t' << pop[i][2] << endl ;
		pop[i][3] = execute(pop[i][0], pop[i][1], pop[i][2]);
	}

	quickSort(pop, 0, POP - 1, 3);

	for(size_t nger = 1; nger <= NGER; nger++) {
		int tournamentelements[TOUR], number;

		clog << "Geração " << nger << endl;
		clog << "m1 " << pop[0][0] << endl;
		clog << "m2 " << pop[0][1] << endl;
		clog << "m3 " << pop[0][2] << endl;
		clog << "collision " << pop[0][3] << endl << endl;

		// clog << "tournament" << endl;
		for(size_t i = 0; i < TCROSS; i++) {
			for (size_t j = 0; j < TOUR; j++) {
				number = random()%POP;
				/*while(!verify(tournamentelements, number, j)){
					number = random()%POP;
				}*/
				tournamentelements[j] = number;

			}
			parents[i] = maxelement(pop, tournamentelements, TOUR);
			assert(parents[i] >= 0 && parents[i] < POP);
		}

		// clog << "crossover" << endl;
		for(size_t i = 0; i < TCROSS; i = i + 2){
			// number = random()%10;
			crossover(pop, pop[parents[i]], pop[parents[i + 1]], i + POP);
		}

		int n1, n2, p;

		// clog << "mutate" << endl;
		for(size_t i = POP; i < TPOP; i++){
			p = random()%100;
			n1 = random()%3;

			// do {
				n2 = random()%3;
			// } while (n1 == n2);

			if(p <= PMUT){
				number = pop[i][n1];
				pop[i][n1] = pop[i][n2];
				pop[i][n2] = number;
				// clog << pop[i][0] << '\t' << pop[i][1] << '\t' << pop[i][2] << endl;
				pop[i][3] = execute(pop[i][0],pop[i][1],pop[i][2]);
			}

		}

		// clog << "survival" << endl;
		quickSort(pop, 0, TPOP - 1, 3);
	}

	clog << "Solution" << endl;
	clog << "m1 " << pop[0][0] << endl;
	clog << "m2 " << pop[0][1] << endl;
	clog << "m3 " << pop[0][2] << endl;
	clog << "collision " << pop[0][3] << endl << endl;

	return 0;
}
