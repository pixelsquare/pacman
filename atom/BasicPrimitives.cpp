#include "BasicPrimitives.h"
using namespace BasicPrimitivesLib::Library;

#include <iostream>
Primitive::Primitive() { 
	this->sphereRadius = 1;
	this->stacks = 50; this->slices = 50;
	this->coneBase = 1; this->coneHeight = 3;

	this->innerRadius = 0.5; this->outerRadius = 1.0;
	this->sides = 20; this->rings = 20;
}

Primitive::~Primitive() { 
	this->sphereRadius = 0;
	this->stacks = 0;
	this->slices = 0;
	this->coneBase = 0;
	this->coneHeight = 0;
	this->innerRadius = 0;
	this->outerRadius = 0;
	this->sides = 0;
	this->rings = 0;

	Collision::~Collision();
}

void Primitive::DrawPrimitive(const PrimitiveType* primitive) {
	if(primitive == PrimitiveType::Cube) { this->DrawCube(); }
	if(primitive == PrimitiveType::Triangle) { this->DrawTriangle(); }
	if(primitive == PrimitiveType::Cone) { this->DrawCone(); }
	if(primitive == PrimitiveType::Torus) { this->DrawTorus(); }
	if(primitive == PrimitiveType::Sphere) { this->DrawSphere(); }
	if(primitive == PrimitiveType::Plane) { this->DrawPlane(); }

	if(this->showCollider) this->DrawCollider();
}

void Primitive::DrawPrimitive(const PrimitiveType* primitive, Vector3 position) {
	this->DrawPrimitive(primitive);
	this->SetPosition(position);
}

void Primitive::DrawPrimitive(const PrimitiveType* primitive, float posX, float posY, float posZ) {
	this->DrawPrimitive(primitive);
	this->SetPosition(Vector3(posX, posY, posZ));
}

void Primitive::DrawCube() {
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y , this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

	glutSolidCube(2.0f);

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 0.0f, 1.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();
}

void Primitive::DrawTriangle() {
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y , this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);
		
		glBegin(GL_TRIANGLE_STRIP);
			glVertex3f(-1.0f, -1.0f, 0.0f);
			glVertex3f(1.0f, -1.0f, 0.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);
		glEnd();

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 0.0f, 1.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();
}

void Primitive::DrawCone() { 
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

	glutSolidCone(this->coneBase, this->coneHeight, this->slices, this->stacks);

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 0.0f, 1.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();
}

void Primitive::DrawTorus() { 
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

		glutSolidTorus(this->innerRadius, this->outerRadius, this->sides, this->rings);

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 0.0f, 1.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();
}

void Primitive::DrawSphere() { 
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);

		glutSolidSphere(this->sphereRadius, this->slices, this->stacks);

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 0.0f, 1.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();
}

void Primitive::DrawPlane() {
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);
	glNormal3f(0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLE_STRIP); 
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);

		glVertex3f(1.0f, -1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 0.0f);
		glEnd();

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 0.0f, 1.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(2.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 2.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 2.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();
}

const PrimitiveType* PrimitiveType::Cube = new PrimitiveType();
const PrimitiveType* PrimitiveType::Triangle = new PrimitiveType();
const PrimitiveType* PrimitiveType::Cone = new PrimitiveType();
const PrimitiveType* PrimitiveType::Torus = new PrimitiveType();
const PrimitiveType* PrimitiveType::Sphere = new PrimitiveType();
const PrimitiveType* PrimitiveType::Plane = new PrimitiveType();