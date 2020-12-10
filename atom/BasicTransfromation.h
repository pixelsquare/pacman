#ifndef __BASIC_TRANSFORMATION_LIBRARY_H__
#define __BASIC_TRANSFORMATION_LIBRARY_H__

/* Connected to Collision Detection Library header */

#pragma region Comments
//
// This section is all about Basic Transformation in 3-dimension
// it includes Translation, Rotation, Scaling and Color Properties
// BasicTransformation declaration for this section is found at BasicTransformation.cpp
//
#pragma endregion

#include "Vector3.h"
using namespace Vector3Lib::Library;

#include "Matrix4.h"
using namespace Matrix4Lib::Library;

namespace BasicTransformationLib {
	namespace Library {
		class Color {
		public:
			Color() { 
				this->R = 0.0f;
				this->G = 0.0f;
				this->B = 0.0f;

				this->Red = Color(1.0f, 0.0f, 0.0f); this->Green = Color(0.0f, 1.0f, 0.0f);
				this->Blue = Color(0.0f, 0.0f, 1.0f); this->Yellow = Color(1.0f, 1.0f, 0.0f);
				this->Magenta = Color(1.0f, 0.0f, 1.0f); this->Cyan = Color(0.0f, 1.0f, 1.0f);
				this->White = Color(1.0f, 1.0f, 1.0f); this->Orange = Color(1.0f, 0.5f, 0.0f);
			}

			Color(float r, float g, float b) {  
				this->R = r;
				this->G = g;
				this->B = b;
			}

			~Color() { 
				this->R = 0;
				this->G = 0;
				this->B = 0;
			}

			static Color Red; static Color Green; static Color Blue;
			static Color Yellow; static Color Magenta; static Color Cyan;
			static Color White; static Color Orange;

			Color operator*(const float scalar) {
				Color rhs;
				rhs.R = this->R * scalar;
				rhs.G = this->G * scalar;
				rhs.B = this->B * scalar;

				return rhs;
			}
			Color operator+(const Color &op) {
				Color rhs;
				rhs.R = this->R + op.R;
				rhs.G = this->G + op.G;
				rhs.B = this->B + op.B;
				return rhs;
			}

			float R;
			float G;
			float B;
		private:
		protected:
		};

		class BasicTransformation {
		public:
			BasicTransformation();
			~BasicTransformation();

			void SetPosition(float posX, float posY, float posZ);
			void SetPosition(Vector3 *pos);
			void SetPosition(Vector3 pos);
			Vector3 GetPosition();

			void SetRotation(int angle, Vector3 *axis);
			void SetRotation(int angle, Vector3 axis);
			void SetRotation(int angle, float axisX, float axisY, float axisZ);
			int GetAngleRotation();
			Vector3 GetAxisRotation();

			void SetColor(float R, float G, float B);
			void SetColor(Color color);
			Color GetColor();

			void SetScale(float scaleX, float scaleY, float scaleZ);
			void SetScale(Vector3 *scale);
			void SetScale(Vector3 scale);

			Vector3 GetScale();

			void ShowPivot(bool show);

			Vector3 Move(float speed, Vector3 *direction);
			Vector3 Move(float speed, Vector3 direction);

			Vector3 MoveUp(float speed);		Vector3 MoveDown(float speed);
			Vector3 MoveRight(float speed);		Vector3 MoveLeft(float speed);
			Vector3 MoveForward(float speed);	Vector3 MoveBack(float speed);

			void MoveSine(float amplitude, Vector3 *direction);
			void MoveSine(float amplitude, Vector3 direction);
			void MoveSine(float amplitude, float x, float y, float z);
			void SetSineTime(float time);

		private:
			Vector3 Position; 
			Vector3 axisRot; 
			Vector3 objectScale;
			Color objectColor;
			int angleRot; int tmpTime;
		protected:
			bool showPivot;
		};
	}
}

#endif