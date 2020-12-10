#ifndef __ATOM_ENGINE_VECTOR_STORAGE_LIBRARY_H__
#define __ATOM_ENGINE_VECTOR_STORAGE_LIBRARY_H__

#include <vector>
#include "BasicPrimitives.h"
using namespace BasicPrimitivesLib::Library;

namespace VectorStorageLib {
	namespace Library {
		class VectorStorage {
		public:
			VectorStorage();
			~VectorStorage();

			void AddObject(Primitive obj);
			void DeleteObject(Primitive obj);
		private:
			std::vector<Primitive> vecPrimitive;
		protected:
		};
	}
}

#endif