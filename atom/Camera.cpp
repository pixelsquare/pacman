#include "Camera.h"
using namespace CameraLib::Library;

Camera::Camera() {
	this->eye = Vector3(0.0f, 0.0f, 50.0f);
	this->center = Vector3::Zero;
	this->up = Vector3(0.0f, 1.0f, 0.0f);
}

Camera::~Camera() { 
	this->eye.~Vector3();
	this->center.~Vector3();
	this->up.~Vector3();
}

Camera *camera = new Camera;
void Camera::SetCameraEye(Vector3 eyes) {
	camera->eye = eyes;
}

void Camera::SetCameraCenter(Vector3 cent) {
	camera->center = cent;
}

void Camera::SetCameraUp(Vector3 Up) {
	camera->up = Up;
}

Vector3 Camera::GetCameraEye() {
	return camera->eye;
}

Vector3 Camera::GetCameraCenter() {
	return camera->center;
}

Vector3 Camera::GetCameraUp() {
	return camera->up;
}