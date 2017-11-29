#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include "md5.h"

#define SIZE_HASH	4
#define SIZE_M1		10000
#define SIZE_M2		10000
#define SIZE_M3		10000
#define SIZE_STR	10

using namespace std;
using HashedToOriginal = map<string, string>;

string create_random_string();
string cryptohash(const string& original);
// inline void show(const HashedToOriginal& hashes);
HashedToOriginal find_collisons(const HashedToOriginal& hashes, int n_messages);

int main() {
	HashedToOriginal hashes1, hashes2, hashes3;
	string random;

	for (int i = 0; i < SIZE_M1; i++) {
		random = create_random_string();
		hashes1[cryptohash(random)] = random;
	}

	// show(hashes1);

	hashes2 = find_collisons(hashes1, SIZE_M2);
	// show(hashes2);

	hashes3 = find_collisons(hashes2, SIZE_M3);
	// show(hashes3);

	cout << hashes3.size() << " collisions" << endl;
	/*cout << "String 1\tString 2\tString 3\tHash" << endl;
	for (auto i = hashes3.begin(); i != hashes3.end(); ++i) {
		cout << hashes1[i->first] << '\t';
		cout << hashes2[i->first] << '\t';
		cout << hashes3[i->first] << '\t';
		cout << i->first << endl;
	}*/

	return 0;
}

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

	for (int i = 0; i < SIZE_M2; i++) {
		try {
			random = create_random_string();
			hashed = cryptohash(random);

			if (hashes.at(hashed) != random)
				collisions[hashed] = random;
		}

		catch (exception& e) {}
	}

	return collisions;
}
