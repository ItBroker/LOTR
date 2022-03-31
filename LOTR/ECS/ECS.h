#pragma once
#include <array>
#include <bitset>
#include <iostream>

using namespace std;
class Component;
class Entity;
using ComponentTypeID = size_t;
using Group = size_t;
inline ComponentTypeID getUniqueComponentID() {
	static ComponentTypeID lastID = 0u;
	return lastID++;
}
template <typename T> 
inline ComponentTypeID getComponentTypeID() noexcept {
	static_assert(is_base_of<Component, T>::value, "Type not base on component!");
	static const ComponentTypeID typeID = getUniqueComponentID();
	return typeID;
	
}
constexpr size_t maxEntities = 32;
constexpr size_t maxComponents = 32;

using ComponentBitset = bitset<maxComponents>;
using ComponentList = array<Component*, maxComponents>;
using GroupBitset = bitset<maxEntities>;
