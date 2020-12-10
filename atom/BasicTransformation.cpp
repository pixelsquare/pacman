#include "BasicTransfromation.h"
using namespace BasicTransformationLib::Library;

#include <iostream>

BasicTransformation::BasicTransformation() { 
	this->Position = Vector3::Zero;
	this->angleRot = 0.0f;
	this->axisRot = Vector3::Zero;
	this->objectScale = Vector3::One;
	this->objectColor = Color::White;
	this->tmpTime = 0;
	this->showPivot = false;
}

BasicTransformation::~BasicTransformation() { 
	this->Position.~Vector3();
	this->axisRot.~Vector3();
	this->objectScale.~Vector3();
	this->objectColor.~Color();
	this->angleRot = 0;
	this->tmpTime = 0;
}

void BasicTransformation::SetPosition(float posX, float posY, float posZ) {
	this->Position = Vector3(posX, posY, posZ);
}

void BasicTransformation::SetPosition(Vector3 *pos) {
	this->Position = *pos;
}

void BasicTransformation::SetPosition(Vector3 pos) {
	this->Position = pos;
}

Vector3 BasicTransformation::GetPosition() { return this->Position; }

void BasicTransformation::SetRotation(int angle, Vector3 *axis) {
	this->angleRot = angle;
	this->axisRot = *axis;
}

void BasicTransformation::SetRotation(int angle, Vector3 axis) {
	this->angleRot = angle;
	this->axisRot = axis;
}

void BasicTransformation::SetRotation(int angle, float axisX, float axisY, float axisZ) {
	this->angleRot = angle;
	this->axisRot = Vector3(axisX, axisY, axisZ);
}

int BasicTransformation::GetAngleRotation() { return this->angleRot; }

Vector3 BasicTransformation::GetAxisRotation() { return this->axisRot; }

void BasicTransformation::SetColor(Color color) {
	this->objectColor = color;
}

void BasicTransformation::SetColor(float R, float G, float B) {
	this->objectColor = Color(R, G, B);
}

Color BasicTransformation::GetColor() { return this->objectColor; }

void BasicTransformation::SetScale(float scaleX, float scaleY, float scaleZ) {
	this->objectScale = Vector3(scaleX, scaleY, scaleZ);
}

void BasicTransformation::SetScale(Vector3 *scale) {
	this->objectScale = *scale;
}

void BasicTransformation::SetScale(Vector3 scale) {
	this->objectScale = scale;
}

Vector3 BasicTransformation::GetScale() { return this->objectScale; }

void BasicTransformation::ShowPivot(bool show) {
	this->showPivot = show;
}

Vector3 BasicTransformation::Move(float speed, Vector3 *direction) {
	direction->Normalize();
	return this->Position += *direction * speed * 0.02f;
}

Vector3 BasicTransformation::Move(float speed, Vector3 direction) {
	direction.Normalize();
	return this->Position += direction * speed * 0.02f;
}

Vector3 BasicTransformation::MoveUp(float speed) {
	return this->Position += Vector3(0.0f, 1.0f, 0.0f) * speed * 0.02f;
}

Vector3 BasicTransformation::MoveDown(float speed) {
	return this->Position += Vector3(0.0f, -1.0f, 0.0f) * speed * 0.02f;
}

Vector3 BasicTransformation::MoveRight(float speed) {
	return this->Position += Vector3(1.0f, 0.0f, 0.0f) * speed * 0.02f;
}

Vector3 BasicTransformation::MoveLeft(float speed) {
	return this->Position += Vector3(-1.0f, 0.0f, 0.0f) * speed * 0.02f;
}

Vector3 BasicTransformation::MoveForward(float speed) {
	return this->Position += Vector3(0.0f, 0.0f, 1.0f) * speed * 0.02f;
}

Vector3 BasicTransformation::MoveBack(float speed) {
	return this->Position += Vector3(0.0f, 0.0f, -1.0f) * speed * 0.02f;
}

void BasicTransformation::MoveSine(float amplitude, Vector3 *direction) {
	this->MoveSine(amplitude, *direction);
}

void BasicTransformation::MoveSine(float amplitude, Vector3 direction) {
	this->tmpTime++;

	if(direction.X == 1.0f && direction.Y == 0.0f && direction.Z == 0.0f) {
		this->Position.X += (amplitude / 50) * Mathf::Sin(this->tmpTime * Mathf::DegToRad);
	}
	else if(direction.X == 0.0f && direction.Y == 1.0f && direction.Z == 0.0f) {
		this->Position.Y += (amplitude / 50) * Mathf::Sin(this->tmpTime * Mathf::DegToRad);
	}
	else if(direction.X == 0.0f && direction.Y == 0.0f && direction.Z == 1.0f) {
		this->Position.Z += (amplitude / 50) * Mathf::Sin(this->tmpTime * Mathf::DegToRad);
	}
	else 
		return;

}

void BasicTransformation::MoveSine(float amplitude, float x, float y, float z) {
	this->MoveSine(amplitude, Vector3(x, y, z));
}

void BasicTransformation::SetSineTime(float time) {
	this->tmpTime = time;
}

Color Color::Red; Color Color::Green;
Color Color::Blue; Color Color::Yellow;
Color Color::Magenta; Color Color::Cyan;
Color Color::White; Color Color::Orange;