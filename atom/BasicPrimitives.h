#ifndef __ATOM_ENGINE_BASIC_PRIMITIVES_LIBRARY_H__
#define __ATOM_ENGINE_BASIC_PRIMITIVES_LIBRARY_H__

/* Connected to AtomEngine Library Header */

#pragma region Comments
//
// This section contains all available basic primitives
// and render it on scene. Primitive includes Cube, Triangle, Cone,
// Torus, Sphere, and Plane.
// Basic Primitives declaration for this section is found at BasicPrimitives.cpp
//
#pragma endregion

#include "glut.h"

#include "CollisionDetection.h"
using namespace CollisionDetectionLib::Library;

namespace BasicPrimitivesLib {
	namespace Library {
		class PrimitiveType {
		public:
			PrimitiveType() { }
			~PrimitiveType() { }

			static const PrimitiveType* Cube;
			static const PrimitiveType* Triangle;
			static const PrimitiveType* Cone;
			static const PrimitiveType* Torus;
			static const PrimitiveType* Sphere;
			static const PrimitiveType* Plane;
		private:
		protected:
		};

		class Primitive : public Collision {
		public:
			Primitive();
			~Primitive();
			
			void DrawPrimitive(const PrimitiveType* primitive);
			void DrawPrimitive(const PrimitiveType* primitive, Vector3 position);
			void DrawPrimitive(const PrimitiveType* primitive, float posX, float posY, float posZ);
		private:
			// Cone and Sphere
			double sphereRadius;
			int stacks; int slices;
			double coneBase; double coneHeight;
			// Torus
			double innerRadius; double outerRadius;
			int sides; int rings;

		protected:
			void DrawCube();
			void DrawTriangle();
			void DrawCone();
			void DrawTorus();
			void DrawSphere();
			void DrawPlane();

		};
	}
}

#endif