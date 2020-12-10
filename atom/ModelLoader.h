#ifndef __ATOM_ENGINE_MODEL_LOADER_LIBRARY_H__
#define __ATOM_ENGINE_MODEL_LOADER_LIBRARY_H__

/* Connected to Atom Engine.cpp */

#pragma region Comments
//
// This section is all about Model loading related stuff
// ModelLoader declaration for this section is found at ModelLoader.cpp
// You are able to load your 3D models as long as it is in .OBJ format
//
#pragma endregion

#include "ModelData.h"
#include "glut.h"
#include "CollisionDetection.h"
using namespace CollisionDetectionLib::Library;

namespace ModelLoaderLib {
	namespace Library { 
		class ModelLoad : public Collision {
		public:
			std::vector<Vertex3D> vertices;
			std::vector<Normal3D> normals;
			std::vector<Face> faces;

			ModelLoad();
			~ModelLoad();

			void LoadObj(const char *OBJFile);
			void RenderModel();
		private:
		protected:
		};
	}
}

#endif