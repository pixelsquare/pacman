#include "AtomEngine.h"
using namespace Atom::Engine;

AtomEngine::AtomEngine() {
	this->windowWidth = 600; this->windowHeight = 600;
	this->projectName = "Atom Engine Project";
}

AtomEngine::~AtomEngine() { }

void AtomEngine::SetProjectName(char* name) { this->projectName = name; }
char* AtomEngine::GetProjectName() { return this->projectName; }

void AtomEngine::SetWindowWidth(int width) { this->windowWidth = width; }
int AtomEngine::GetWindowWidth() { return this->windowWidth; }

void AtomEngine::SetWindowHeight(int height) { this->windowHeight = height; }
int AtomEngine::GetWindowHeight() { return this->windowHeight; }

AtomEngine *engine = new AtomEngine;
void AtomEngine::ShutDown() {
	system("CLS");
	printf("==================== LOG ====================\n");
	engine->CleanUp();
	printf("\n\n===========================================");
	glutDestroyWindow(1);
	getch();
}

void AtomEngine::Clean(ModelLoad object) {
	printf("\nClearing 1 object in ModelLoad.");
	object.~ModelLoad();
}

void AtomEngine::Clean(ModelLoad *object) {
	printf("\nClearing 1 object in ModelLoad.");
	object->~ModelLoad();
}

void AtomEngine::Clean(std::vector<ModelLoad> object) {
	printf("\nClearing %i object in ModelLoad. [Vector buffer]", object.size());
	object.clear();
}

void AtomEngine::Clean(Primitive object) {
	printf("\nClearing 1 object in Primitive.");
	object.~Primitive();
}

void AtomEngine::Clean(Primitive *object) {
	printf("\nClearing 1 object in Primitive.");
	object->~Primitive();
}

void AtomEngine::Clean(std::vector<Primitive> object) {
	printf("\nClearing %i object in Primitive. [Vector buffer]", object.size());
	object.clear();
}

void AtomEngine::Clean(Vector3 vector) {
	printf("\nClearing 1 object in Vector3.");
	vector.~Vector3();
}

void AtomEngine::Clean(Vector3 *vector) {
	printf("\nClearing 1 object in Vector3.");
	vector->~Vector3();
}

void AtomEngine::Clean(std::vector<Vector3> vector) {
	printf("\nClearing %i object in Vector3. [Vector buffer]", vector.size());
	vector.clear();
}

void AtomEngine::Clean(Time time) {
	printf("\nClearing 1 object in Time.");
	time.~Time();
}

void AtomEngine::Clean(Time *time) {
	printf("\nClearing 1 object in Time.");
	time->~Time();
}

void AtomEngine::Clean(std::vector<Time> time) {
	printf("\nClearing %i object in Time. [Vector buffer]", time.size());
	time.clear();
}

void AtomEngine::Clean(int number) {
	number = 0;
	printf("\nSetting integer value to %i.", number);
}

void AtomEngine::Clean(std::vector<int> number) {
	printf("\nClearing %i integer values. [Vector buffer]", number.size());
	number.clear();
}

void AtomEngine::Clean(float number) {
	number = 0.0f;
	printf("\nSetting float value to %.1f.", number);
}

void AtomEngine::Clean(std::vector<float> number) {
	printf("\nClearing %i float values. [Vector buffer]", number.size());
	number.clear();
}

void AtomEngine::Clean(double number) {
	number = 0;
	printf("\nSetting double value to %d.", number);
}

void AtomEngine::Clean(std::vector<double> number) {
	printf("\nClearing %i double values. [Vector buffer]", number.size());
	number.clear();
}

void AtomEngine::Clean(long int number) {
	number = 0;
	printf("\nSetting long integer value to %li.", number);
}

void AtomEngine::Clean(std::vector<long int> number) {
	printf("\nClearing %i long integer values. [Vector buffer]", number.size());
	number.clear();
}

void AtomEngine::Clean(long double number) {
	number = 0;
	printf("\nSetting long double value to %ld.", number);
}

void AtomEngine::Clean(std::vector<long double> number) {
	printf("\nClearing %i long double values. [Vector buffer]", number.size());
	number.clear();
}