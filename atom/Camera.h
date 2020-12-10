#ifndef __ATOM_ENGINE_CAMERA_LIBRARY_H__
#define __ATOM_ENGINE_CAMERA_LIBRARY_H__

/* Connected to Atom Engine library header */

#pragma region Comments
//
// This section contains all available Camera settings for the game
// Camera declaration for this section is found at Camera.cpp
//
#pragma endregion

#include "Vector3.h"
using namespace Vector3Lib::Library;

namespace CameraLib {
	namespace Library {
		class Camera {
		public:
			Camera();
			~Camera();

			static void SetCameraEye(Vector3 eye);
			static void SetCameraCenter(Vector3 center);
			static void SetCameraUp(Vector3 up);

			static Vector3 GetCameraEye();
			static Vector3 GetCameraCenter();
			static Vector3 GetCameraUp();

			Vector3 eye;
			Vector3 center;
			Vector3 up;

		private:
		protected:
		};
	}
}

#endif