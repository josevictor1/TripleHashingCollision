#include "ag.h"

int main(){

    int pop[POP][4];
    int parents[TCROSS];

    cout << "passou" << endl;

    for(size_t i = 0; i < POP; i++){
        pop[i][2] = SIZE_M;
        for(size_t j = 0; j < 2; j++){
            cout << "passou loop" << endl;
            int generated = random();
            pop[i][j] = (generated % pop[i][2]) + 1;
            pop[i][2] -= pop[i][j];
        }

        // clog << pop[i][0] << '\t' << pop[i][1] << '\t' << pop[i][2] << endl ;
        pop[i][3] = execute(pop[i][0], pop[i][1], pop[i][2]);

        // cout << "colisoes:" << pop[i][3] << endl;
    }
    cout << "passou" << endl;
    for(size_t nger = 0; nger < NGER; nger++){
        clog << "Geração " << nger << '\r';
        int tournamentelements[TOUR], number;

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
        // cout << "torneio" << endl;
        for(size_t i = 1; i < TCROSS; i = i + 2){
            number = random()%10;
            //printf("%d\n",number);
            crossover(pop, pop[parents[i-1]], pop[parents[i]], i);
        }
        // cout << "crossover" << endl;


        int n1, n2, p;

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
        // cout << "mutate" << endl;

        quickSort(pop, 0, TPOP - 1, 3);
        // cout << "elitismo" << endl;

    }

}
