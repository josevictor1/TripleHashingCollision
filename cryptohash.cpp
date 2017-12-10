#include <cassert>
#include <map>
#include <random>
#include <string>

#include "md5.h"
#include "cryptohash.h"

using namespace std;

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

const StringToHash message_set = create_messages();

HashToString find_collisons(const HashToString& hashes, int n_messages, StringToHash::const_iterator& iterator) {
	HashToString collisions;

	for (int i = 0; i < n_messages; i++) {
		assert(iterator != message_set.end());

		if (hashes.find(iterator->second) != hashes.end())
			collisions[iterator->second] = iterator->first;

		iterator++;
	}

	return collisions;
}

int execute(int m1, int m2, int m3) {
	auto iterator = message_set.begin();
	HashToString hashes1;

	assert(message_set.size() == SIZE_M);
	assert((m1 + m2 + m3) == SIZE_M);

	for (int i = 0; i < m1; i++) {
		hashes1[iterator->second] = iterator->first;
		iterator++;
	}

	const HashToString hashes2 = find_collisons(hashes1, m2, iterator);
	const HashToString hashes3 = find_collisons(hashes2, m3, iterator);

	return hashes3.size();
}
