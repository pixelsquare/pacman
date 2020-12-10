#ifndef __ATOM_ENGINE_KEYBOARD_LIBRARY_H__
#define __ATOM_ENGINE_KEYBOARD_LIBRARY_H__

/* Connected to Atom Engine Library header */

#pragma region Comments
//
// This section is all about Keyboard funtionality
// Keyboard declaration for this section is found at Keyboard.cpp
//
#pragma endregion

namespace KeyboardLib {
	namespace Library {
		class Input {
		public:
			Input();
			~Input();

			static bool KeyDown[256];
			static void KeyHold();
			static void Key(unsigned char key, int x, int y);
			static void KeyUp(unsigned char key, int x, int y);
		private:
		protected:
		};
	}
}

#endif