#ifndef __ATOM_ENGINE_TEXT_LIBRARY_H__
#define __ATOM_ENGINE_TEXT_LIBRARY_H__

/* Connected to Atom Engine Library header */

#pragma region Comments
//
// This section is all about Basic Text rendering
// Text declaration for this section is found at Text.cpp
//
#pragma endregion

#include "glut.h"
#include <stdlib.h>
#include <string>
#define GH_DEFAULT_BITMAP_FONT GLUT_BITMAP_HELVETICA_10

namespace TextLib {
	namespace Library {
		class Text{
		public:
			Text();
			~Text();

			static void* font;
			static void AddText(float x, float y, float z, char* string);
			static void AddText(const char* format, float x, float y, float z, char* string);
			static void AddText(const char* format, float value, float x, float y, float z, char* string);
			static void AddText(const char* format, int value, float x, float y, float z, char* string);
			static void AddText(const char* format, double value, float x, float y, float z, char* string);
		private:
		protected:
		};
	}
}

#endif