#include "CollisionDetection.h"
using namespace CollisionDetectionLib::Library;

Collision::Collision() { 
	this->colliderOffset = Vector3::One; 
	this->acquireCollider = false;
	this->showCollider = false;
}

Collision::~Collision() { 
	this->colliderOffset.~Vector3();
	BasicTransformation::~BasicTransformation();
}

void Collision::ApplyCollider(bool flag) {
	this->showCollider = false;
	this->acquireCollider = flag;
	this->colliderOffset = Vector3::One;
}

void Collision::ApplyCollider(bool flag, bool show) {
	this->showCollider = show;
	this->acquireCollider = flag;
	this->colliderOffset = Vector3::One;
}

void Collision::SetColliderSize(float x, float y, float z) {
	this->colliderOffset = Vector3(x, y, z);
}

void Collision::SetColliderSize(Vector3 size) {
	this->colliderOffset = size;
}

void Collision::DrawCollider() { 
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
	//glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	//glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

		glLineWidth(2.0f);
		glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glNormal3f(0.0f, 1.0f, 1.0f);
		glBegin(GL_LINES);
			// FRONT FACE
			glVertex3f(colliderOffset.X, colliderOffset.Y, colliderOffset.Z);
			glVertex3f(-colliderOffset.X, colliderOffset.Y, colliderOffset.Z);
			glVertex3f(-colliderOffset.X, colliderOffset.Y, colliderOffset.Z);
			glVertex3f(-colliderOffset.X, -colliderOffset.Y, colliderOffset.Z);
			// cont..
			glVertex3f(-colliderOffset.X, -colliderOffset.Y, colliderOffset.Z);
			glVertex3f(colliderOffset.X, -colliderOffset.Y, colliderOffset.Z);
			glVertex3f(colliderOffset.X, -colliderOffset.Y, colliderOffset.Z);
			glVertex3f(colliderOffset.X, colliderOffset.Y, colliderOffset.Z);

			// Upper-Right (Going behind)
			glVertex3f(colliderOffset.X, colliderOffset.Y, colliderOffset.Z);
			glVertex3f(colliderOffset.X, colliderOffset.Y, -colliderOffset.Z);
			// Upper-Left (Going behind)
			glVertex3f(-colliderOffset.X, colliderOffset.Y, colliderOffset.Z);
			glVertex3f(-colliderOffset.X, colliderOffset.Y, -colliderOffset.Z);
			// Lower-Left (Going behind)
			glVertex3f(-colliderOffset.X, -colliderOffset.Y, colliderOffset.Z);
			glVertex3f(-colliderOffset.X, -colliderOffset.Y, -colliderOffset.Z);
			// Lower-Right (Going behind)
			glVertex3f(colliderOffset.X, -colliderOffset.Y, colliderOffset.Z);
			glVertex3f(colliderOffset.X, -colliderOffset.Y, -colliderOffset.Z);

			// BACK FACE
			glVertex3f(colliderOffset.X, colliderOffset.Y, -colliderOffset.Z);
			glVertex3f(-colliderOffset.X, colliderOffset.Y, -colliderOffset.Z);
			glVertex3f(-colliderOffset.X, colliderOffset.Y, -colliderOffset.Z);
			glVertex3f(-colliderOffset.X, -colliderOffset.Y, -colliderOffset.Z);
			// cont..
			glVertex3f(-colliderOffset.X, -colliderOffset.Y, -colliderOffset.Z);
			glVertex3f(colliderOffset.X, -colliderOffset.Y, -colliderOffset.Z);
			glVertex3f(colliderOffset.X, -colliderOffset.Y, -colliderOffset.Z);
			glVertex3f(colliderOffset.X, colliderOffset.Y, -colliderOffset.Z);
		glEnd();
		glPopMatrix();

	glPopMatrix();
}

bool Collision::HasCollidedWith(Collision &object) {
	bool xHasNotCollided =
		this->GetPosition().X - this->colliderOffset.X >
		object.GetPosition().X + object.colliderOffset.X ||
		this->GetPosition().X + this->colliderOffset.X <
		object.GetPosition().X - object.colliderOffset.X;

	bool yHasNotCollided = 
		this->GetPosition().Y - this->colliderOffset.Y >
		object.GetPosition().Y + object.colliderOffset.Y ||
		this->GetPosition().Y + this->colliderOffset.Y <
		object.GetPosition().Y - object.colliderOffset.Y;

	bool zHasNotCollided = 
		this->GetPosition().Z - this->colliderOffset.Z >
		object.GetPosition().Z + object.colliderOffset.Z ||
		this->GetPosition().Z + this->colliderOffset.Z <
		object.GetPosition().Z - object.colliderOffset.Z;

	if((xHasNotCollided || yHasNotCollided || zHasNotCollided) ||
		(!this->acquireCollider || !object.acquireCollider) || 
		(this->colliderOffset.X == 0.0f && this->colliderOffset.Y == 0.0f && this->colliderOffset.Z == 0.0f) ||
		(object.colliderOffset.X == 0.0f && object.colliderOffset.Y == 0.0f && object.colliderOffset.Z == 0.0f))
		return false;
	else 
		return true;

}