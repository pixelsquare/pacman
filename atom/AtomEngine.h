#ifndef __ATOM_ENGINE_H__
#define __ATOM_ENGINE_H__

/* Connected to OpenGL Library Header */

#pragma region Comments
//
// This section contains all available settings for the game
// AtomEngine declaration is included here, so it doesn't have a .cpp file
//
#pragma endregion

#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "Camera.h"
using namespace CameraLib::Library;

//#include "Matrix4.h"
//using namespace Matrix4Lib::Library;

#include "Sound.h"
using namespace SoundLib::Library;

#include "Text.h"
using namespace TextLib::Library;

#include "Time.h"
using namespace TimeLib::Library;

#include "Keyboard.h"
using namespace KeyboardLib::Library;

#include "ModelLoader.h"
using namespace ModelLoaderLib::Library;

#include "BasicPrimitives.h"
using namespace BasicPrimitivesLib::Library;

namespace Atom {
	namespace Engine {
		class AtomEngine {
		public:
			AtomEngine();
			~AtomEngine();

			void SetProjectName(char* name);
			char* GetProjectName();

			void SetWindowWidth(int width);
			int GetWindowWidth();

			void SetWindowHeight(int height);
			int GetWindowHeight();

			void Start();
			void Update();
			void CollisionDetection();
			void CleanUp();
			void TextRender();
			static void ShutDown();

			static void Clean(ModelLoad object);
			static void Clean(ModelLoad *object);
			static void Clean(std::vector<ModelLoad> object);

			static void Clean(Primitive object);
			static void Clean(Primitive *object);
			static void Clean(std::vector<Primitive> object);

			static void Clean(Vector3 vector);
			static void Clean(Vector3 *vector);
			static void Clean(std::vector<Vector3> vector);

			static void Clean(Time time);
			static void Clean(Time *time);
			static void Clean(std::vector<Time> time);

			static void Clean(int number);
			static void Clean(std::vector<int> number);

			static void Clean(float number);
			static void Clean(std::vector<float> number);

			static void Clean(double number);
			static void Clean(std::vector<double> number);

			static void Clean(long int number);
			static void Clean(std::vector<long int> number);

			static void Clean(long double number);
			static void Clean(std::vector<long double> number);
		private:
			char* projectName;
			int windowWidth; int windowHeight;
			unsigned char key; 
		protected:
		};
	}
}

#endif
