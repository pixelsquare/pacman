#ifndef __ATOM_ENGINE_VECTOR3_LIBRARY_H__
#define __ATOM_ENGINE_VECTOR3_LIBRARY_H__

/* Connected to Matrix4 Library header */

#pragma region Comments
//
// This section is all about Vector in 3-dimension related stuff
// Vector3 declaration for this section is found at Vector3.cpp
//
#pragma endregion

#include <math.h>
#include <stdio.h>
#include <vector>

#include "Math.h"
using namespace Math::Library;

#define ToDegrees 180 / PI
#define ToRadians PI / 180

namespace Vector3Lib {
	namespace Library {
	class Vector3 {
		public:
			Vector3();
			Vector3(float x, float y, float z);
			~Vector3();

			Vector3 &operator=(const Vector3 &rhs);

			Vector3 &operator+=(const Vector3 &rhs);
			Vector3 operator+(const Vector3 &op);

			Vector3 &operator-=(const Vector3 &rhs);
			Vector3 operator-(const Vector3 &op);

			Vector3 &operator*=(const float scalar);
			Vector3 operator*(const float scalar);

			Vector3 &operator*=(const Vector3 &rhs);
			Vector3 operator*(const Vector3 &op);

			float GetLength();
			void Normalize();
			Vector3 Normalized();
			float Dot(const Vector3 &other);
			Vector3 Cross(Vector3 &other);
			
			void PrintLine();

			static Vector3 Zero;		static Vector3 Forward;
			static Vector3 One;			static Vector3 Back;
			static Vector3 Up;			static Vector3 Left;
			static Vector3 Down;		static Vector3 Right;

			static Vector3 MoveUp;		static Vector3 MoveDown;
			static Vector3 MoveLeft;	static Vector3 MoveRight;
			static Vector3 MoveForward; static Vector3 MoveBack;

			static float Dot(Vector3 lhs, Vector3 rhs);
			static Vector3 Cross(Vector3 lhs, Vector3 rhs);
			static float AngleBetweenVectors(Vector3 lhs, Vector3 rhs);
			static float GetDistance(Vector3 pt1, Vector3 pt2);

			Vector3 SineWave(float amplitue, Vector3 direction);

			float X;
			float Y;
			float Z;
		private:
			float tmpTime;
		protected:
		};
	}
}

#endif