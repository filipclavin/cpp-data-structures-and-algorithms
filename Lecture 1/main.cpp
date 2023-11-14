#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>

#include "Monster.h"
#include "LinkedList.h"

float randomFloat(float min, float max)
{
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

int main() {
	Monster monstersArray[100]{};

	std::queue<Monster> monstersQueue;
	std::stack<Monster> monstersStack;
	LinkedList<Monster> monstersLinkedList;

	for (int i = 0; i < 100; i++) {
		monstersArray[i] = {
			1 + rand() % 1000,
			1 + rand() % 100,
			Vec3{ randomFloat(0, 100), randomFloat(0, 100), randomFloat(0, 100) }
		};

		monstersQueue.push(monstersArray[i]);
		monstersStack.push(monstersArray[i]);
		monstersLinkedList.Add(&monstersArray[i]);
	}

	std::cout << "---------- ARRAY ----------" << std::endl;

	for (Monster m : monstersArray) {
		std::cout << "Monster health: " << m.health << std::endl;
		std::cout << "Monster attack: " << m.attack << std::endl;
		std::cout << "Monster position: " << m.position.toString() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "---------- QUEUE ----------" << std::endl;

	do {
		Monster m = monstersQueue.front();
		std::cout << "Monster health: " << m.health << std::endl;
		std::cout << "Monster attack: " << m.attack << std::endl;
		std::cout << "Monster position: " << m.position.toString() << std::endl;
		std::cout << std::endl;

		monstersQueue.pop();
	} while (!monstersQueue.empty());

	std::cout << "---------- STACK ----------" << std::endl;

	do {
		Monster m = monstersStack.top();
		std::cout << "Monster health: " << m.health << std::endl;
		std::cout << "Monster attack: " << m.attack << std::endl;
		std::cout << "Monster position: " << m.position.toString() << std::endl;
		std::cout << std::endl;

		monstersStack.pop();
	} while (!monstersStack.empty());

	std::cout << "---------- LINKED LIST ----------" << std::endl;

	for (int i = 0; i < monstersLinkedList.Count(); i++) {
		Monster* m = monstersLinkedList.Get(i);
		std::cout << "Monster health: " << m->health << std::endl;
		std::cout << "Monster attack: " << m->attack << std::endl;
		std::cout << "Monster position: " << m->position.toString() << std::endl;
		std::cout << std::endl;

		monstersLinkedList.Remove(m);
	}

	std::cout << "---------- REMOVE TEST ----------" << std::endl;

	for (int i = 0; i < monstersLinkedList.Count(); i++) {
		Monster* m = monstersLinkedList.Get(i);
		std::cout << "Monster health: " << m->health << std::endl;
		std::cout << "Monster attack: " << m->attack << std::endl;
		std::cout << "Monster position: " << m->position.toString() << std::endl;
		std::cout << std::endl;
	}

	return 0;
}