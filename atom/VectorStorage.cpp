#include "VectorStorage.h"
using namespace VectorStorageLib::Library;

VectorStorage::VectorStorage() { }

VectorStorage::~VectorStorage() { }

void VectorStorage::AddObject(Primitive obj) {
	vecPrimitive.push_back(obj);
}

void VectorStorage::DeleteObject(Primitive obj) {
	for(int i = 0; i < vecPrimitive.size(); i++){
		if(vecPrimitive[i] == obj)
			vecPrimitive.erase(vecPrimitive.begin() + i);
	}

}