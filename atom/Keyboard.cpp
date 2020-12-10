#include "Keyboard.h"
using namespace KeyboardLib::Library;

Input::Input() { }

Input::~Input() { }

bool Input::KeyDown[256];

void Input::Key(unsigned char key, int x, int y) {
	Input::KeyDown[key] = false;
}