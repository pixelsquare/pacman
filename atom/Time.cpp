#include "Time.h"
using namespace TimeLib::Library;

#include <iostream>
Time::Time() { 
	this->presTime
		= this->prevTime
		= this->dt
		= this->time_elapsed = 0.0f;
	this->startTime = glutGet(GLUT_ELAPSED_TIME);
}

Time::~Time() { 
	this->presTime = 0.0f;
	this->presTime = 0.0f;
	this->startTime = 0.0f;
	this->dt = 0.0f;
	this->time_elapsed = 0.0f;
}

void Time::LocalObserve() {
	this->presTime = glutGet(GLUT_ELAPSED_TIME);
	this->dt = this->presTime - this->prevTime;
	this->prevTime = this->presTime;
}

float Time::LocalDeltaTime() {
	this->dt /= 1000.0f;
	return this->dt;
}

float Time::LocalTimeElapsed() {
	float timeNow = glutGet(GLUT_ELAPSED_TIME);
	this->time_elapsed = timeNow - this->startTime;
	this->time_elapsed /= 1000.0f;
	return this->time_elapsed;
}

void Time::LocalReset() {
	this->startTime = glutGet(GLUT_ELAPSED_TIME);
}

Time *t = new Time;
void Time::Observe() {
	t->presTime = glutGet(GLUT_ELAPSED_TIME);
	t->dt = t->presTime - t->prevTime;
	t->prevTime = t->presTime;
}

float Time::DeltaTime() {
	t->dt /= 1000.0f;
	return t->dt;
}

float Time::TimeElapsed() {
	float timeNow = glutGet(GLUT_ELAPSED_TIME);
	t->time_elapsed = timeNow - t->startTime;
	t->time_elapsed /= 1000.0f;
	return t->time_elapsed;
}

void Time::Reset() {
	t->startTime = glutGet(GLUT_ELAPSED_TIME);
}

float Time::GetFPS() {
	return 1.0f / t->DeltaTime();
}