#ifndef __ATOM_ENGINE_MATH_LIBRARY_H__
#define __ATOM_ENGINE_MATH_LIBRARY_H__

/* Connected to Vector3 Library header */

#pragma region Comments
//
// This section is all about all Math related stuff
// Math declaration for this section is found at Math.cpp
//
#pragma endregion

#include <math.h>
#include <array>

namespace Math {
	namespace Library {
		class Mathf{
		public:
			Mathf();
			~Mathf();

			static float Abs(float f);
			static float Acos(float f);
			static bool Approximately(float a, float b);
			static float Asin(float f);
			static float Atan(float f);
			static float Atan2(float a, float b);
			static float Exp(float f);
			static float Cos(float f);
			static float Sin(float f);
			static float Tan(float f);
			static float Min(float a, float b);
			static float Max(float a, float b);
			static float Log(float f);
			static float Sqrt(float f);
			static float Pow(float f, float p);
			static double Ceil(double f);
			static double Floor(double f);

			static float PI;
			static float DegToRad;
			static float RadToDeg;
		private:
		protected:
		};
	}
}

#endif