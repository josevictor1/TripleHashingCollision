#include "cryptohash.h"

int main() {
	cout << execute(500000, 300000, 200000) << " collisions" << endl;
	cout << execute(400000, 300000, 300000) << " collisions" << endl;
	cout << execute(600000, 200000, 200000) << " collisions" << endl;
	cout << execute(800000, 100000, 100000) << " collisions" << endl;
	return 0;
}
