#include <string>
#include <iostream>
#include <chrono>

#include "Map.h"

int main() {
	Map<std::string, std::string>* dictionary = new Map<std::string, std::string>();

	dictionary->Insert("hello", "hej");
	dictionary->Insert("goodbye", "hejdå");
	dictionary->Insert("yes", "ja");
	dictionary->Insert("no", "nej");

	while (true) {
		std::string englishWord = "";
		std::cout << "Insert english word to translate to swedish: ";
		std::cin >> englishWord;

		auto start = std::chrono::high_resolution_clock::now();
		std::string swedishWord = dictionary->Lookup(englishWord);
		auto end = std::chrono::high_resolution_clock::now();

		std::cout << "The swedish word for hello is " << swedishWord << std::endl;
		std::cout << "Lookup took " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds" << std::endl;

		std::string entryToRemove = "";
		std::cout << "Insert english word to remove from dictionary: ";
		std::cin >> entryToRemove;

		dictionary->Remove(entryToRemove);
	}
	


	return 0;
}