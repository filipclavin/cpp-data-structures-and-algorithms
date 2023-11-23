#pragma once

#include <list>

template <typename Tkey, typename Tvalue>
class Map {
public:
	void Insert(Tkey key, Tvalue value);

	void Put(Tkey key, Tvalue value);

	Tvalue Lookup(Tkey key);

	void Remove(Tkey key);

private:
	class Entry {
	public:
		Tkey key;
		Tvalue value;

		Entry(Tkey key, Tvalue value) {
			this->key = key;
			this->value = value;
		}

	};

	std::list<Entry*> entries = {};
};


template <typename Tkey, typename Tvalue>
void Map<Tkey, Tvalue>::Insert(Tkey key, Tvalue value) {
	entries.push_back(new Entry(key, value));
}

template <typename Tkey, typename Tvalue>
void Map<Tkey, Tvalue>::Put(Tkey key, Tvalue value) {
	for (Entry* entry : entries) {
		if (entry->key == key) {
			entry->value = value;
			return;
		}
	}

	Insert(key, value);
}

template <typename Tkey, typename Tvalue>
Tvalue Map<Tkey, Tvalue>::Lookup(Tkey key) {
	for (Entry* entry : entries) {
		if (entry->key == key) {
			return entry->value;
		}
	}

	return (Tvalue)0;
}

template <typename Tkey, typename Tvalue>
void Map<Tkey, Tvalue>::Remove(Tkey key) {
	for (Entry* entry : entries) {
		if (entry->key == key) {
			entries.remove(entry);
			break;
		}
	}
}