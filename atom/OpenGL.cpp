#include "OpenGL.h"
using namespace Glut::OpenGL;

int main(int argc, char **argv) {
	srand(time(NULL));
	engine->Start();
	GlutMain(argc, argv);
	AtomEngine::ShutDown();
	return 0;
}