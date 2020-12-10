#ifndef __ATOM_ENGINE_MATRIX4_LIBRARY_H__
#define __ATOM_ENGINE_MATRIX4_LIBRARY_H__

/* Connected to Atom Engine Library Header */

#pragma region Comments
//
// This section is all about Matrix related stuff 
// Matrix4 declaration for this section is found at Matrix4.cpp
//
#pragma endregion

#include "Vector3.h"
using namespace Vector3Lib::Library;

namespace Matrix4Lib {
	namespace Library {
		class Matrix4 {
		public:
			Matrix4();
			~Matrix4();

			Matrix4 &operator=(Matrix4 &rhs);
			Vector3 operator*(const Vector3 &vector);
			float &Element(int i, int j);
			Matrix4 operator*(Matrix4 &matrix);

			static Matrix4 CreateRotationX(float angleDeg);
			static Matrix4 CreateRotationY(float angleDeg);
			static Matrix4 CreateRotationZ(float angleDeg);
			static Matrix4 CreateScaling(float x, float y, float z);
			static Matrix4 CreateTranslation(float x, float y, float z);
			void Print();

		private:
		protected:
			float m_elements[16];
		};
	}
}

#endif