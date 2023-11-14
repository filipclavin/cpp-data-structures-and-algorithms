#pragma once

#include "Monster.h"

struct Node {
	Monster *monster;
	Node *next;
};