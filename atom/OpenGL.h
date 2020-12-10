#ifndef __GLUTSETUP_H__
#define __GLUTSETUP_H__

/* Connected to OpenGL.CPP (Entry Point of the program) */

#pragma region Comments
//
// This section is all about glut related stuff
// OpenGL declaration for this section is found at OpenGL.cpp
//
#pragma endregion

#include <time.h>

#include "AtomEngine.h"
using namespace Atom::Engine;

namespace Glut {
	namespace OpenGL {
		AtomEngine *engine = new AtomEngine;

		void MainScene() { 
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(Camera::GetCameraEye().X, Camera::GetCameraEye().Y, Camera::GetCameraEye().Z,
				      Camera::GetCameraCenter().X, Camera::GetCameraCenter().Y, Camera::GetCameraCenter().Z,
				      Camera::GetCameraUp().X, Camera::GetCameraUp().Y, Camera::GetCameraUp().Z);
			Time::Observe();
			engine->Update();
			engine->CollisionDetection();
			engine->TextRender();
			Input::KeyHold();

			glutSwapBuffers();
		}

		void Timer(int extra) {
			glutPostRedisplay();
			glutTimerFunc(10, Timer, extra);
		}

		void ResizeWindow(int w, int h) {
			float ratio = 1.0f * w / h;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
		
			glViewport(0, 0, w, h);
			gluPerspective(45, ratio, 1, 1000);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
		}

		void SpecialKeys(int key, int x, int y) {
			switch(key) {
			case GLUT_KEY_UP:
				break;
		
			case GLUT_KEY_DOWN:
				break;
		
			case GLUT_KEY_LEFT:
				break;
		
			case GLUT_KEY_RIGHT:
				break;
			}
		}

		void MouseButton(int button, int state, int x, int y) {

		}

		void MouseMove(int x, int y) {

		}

		//void KeyUp(unsigned char key, int x, int y) {
		//	Input::KeyDown[key] = false;
		//}
		
		void InitRendering() {
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_COLOR_MATERIAL);
			glEnable(GL_LIGHTING); //Enable lighting
			glEnable(GL_LIGHT0); //Enable light #0
			glEnable(GL_LIGHT1); //Enable light #1
			glEnable(GL_NORMALIZE); //Automatically normalize normals
			glShadeModel(GL_SMOOTH); //Enable smooth shading
		
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glEnable(GL_LINE_SMOOTH);

			/*float lightAmbient[] = {0.5f, 0.5f, 0.5f, 1.0f };
			float ambientPosition[] = {50.0f, 50.0f, 50.0f, 1.0f};
			glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
			glLightfv(GL_LIGHT1, GL_POSITION, ambientPosition);*/
		}
		
		void GlutMain(int argc, char **argv) {
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		
			glutInitWindowPosition(0, 0);
			glutInitWindowSize(engine->GetWindowWidth(), engine->GetWindowHeight());
			glutCreateWindow(engine->GetProjectName());
		
			glutDisplayFunc(MainScene);
			glutReshapeFunc(ResizeWindow);
			glutTimerFunc(0, Timer, 0);
		
			glutSpecialFunc(SpecialKeys);

			glutMouseFunc(MouseButton);
			glutMotionFunc(MouseMove);

			glutKeyboardFunc(Input::KeyUp);
			glutKeyboardUpFunc(Input::Key);
		
			InitRendering();
		
			glutMainLoop();
		}
	}
}
#endif