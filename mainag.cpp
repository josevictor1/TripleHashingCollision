#include "ag.h"

int main() {
	int pop[POP][4];
	int parents[TCROSS];

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

	for(size_t nger = 0; nger < NGER; nger++){
		clog << "Geração " << nger << endl;
		int tournamentelements[TOUR], number;

		// cout << "tournament" << endl;
		for(size_t i = 0; i < TCROSS; i++){
			for (size_t j = 0; j < TOUR; j++) {
				number = random()%POP;
				while(!verify(tournamentelements, number, j)){
					number = random()%POP;
				}
				tournamentelements[j] = number;

			}
			parents[i] = maxelement(pop, tournamentelements, TOUR);
		}

		// cout << "crossover" << endl;
		for(size_t i = 1; i < TCROSS; i = i + 2){
			// number = random()%10;
			crossover(pop, pop[parents[i-1]], pop[parents[i]], i);
		}

		int n1, n2, p;

		// cout << "mutate" << endl;
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
				// clog << pop[i][0] << '\t' << pop[i][1] << '\t' << pop[i][2] << endl ;
				pop[i][3] = execute(pop[i][0],pop[i][1],pop[i][2]);
			}

		}

		// cout << "elitism" << endl;
		quickSort(pop, 0, TPOP - 1, 3);
	}

}
