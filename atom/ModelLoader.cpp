#include "ModelLoader.h"
using namespace ModelLoaderLib::Library;

#include <fstream>
#include <Windows.h>
#include "ModelParser.h"

ModelLoad::ModelLoad() { }

ModelLoad::~ModelLoad() { 
	this->vertices.clear();
	this->faces.clear();
	this->normals.clear();

	Collision::~Collision();
}

void ModelLoad::LoadObj(const char* OBJFile)
{
	char pwd[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pwd);

	std::string path(pwd);

	if(IsDebuggerPresent())
	{
#if DEBUG
		path = path + "\\Debug.win32\\" + OBJFile;
#else
		path = path + "\\Release.win32\\" + OBJFile;
#endif
	}
	else
	{
		path = path + "\\" + OBJFile;
	}

	printf("Loading .. %s\n", path.c_str());
	std::ifstream ifs(path);

	char data[100];
	while(ifs >> data) {
		if(strcmp(data, "v") == 0) // strcmp = string compare
		{
			float x, y, z;

			// Extract x, y, z
			ifs >> x;
			ifs >> y;
			ifs >> z;

			Vertex3D vert; // create vertex3D Object; look at ModelData.h
			vert.x = x;
			vert.y = y;
			vert.z = z;
			vertices.push_back(vert);
		}
		else if(strcmp(data, "vn") == 0)
		{
			float x, y, z;
			ifs >> x;
			ifs >> y;
			ifs >> z;

			Normal3D norm;
			norm.x = x;
			norm.y = y;
			norm.z = z;
			normals.push_back(norm);
		}
		else if(strcmp(data, "f") == 0)
		{
			char FaceData[100];
			Face face;

			while(true)
			{
				ifs >> FaceData; // f 1//1 2//1 3//1 4//1
				
				if(ContainSlash(FaceData, 100))
				{
					char Vertexindx[15];
					char Normalindx[15];

					ExtractVertexIdx(FaceData, Vertexindx);
					ExtractNormalIdx(FaceData, Normalindx);

					int vIndex = atoi(Vertexindx); // atoi = convert char to int
					int nIndex = atoi(Normalindx);

					face.VertexIndex.push_back(vIndex);
					face.NormalIndex.push_back(nIndex);
				}
				else
				{
					faces.push_back(face);
					ifs.unget();
					break;
				}

			}
		}
	}
}

void ModelLoad::RenderModel()
{
	glLineWidth(2.0);
	glPushMatrix();
	glColor3f(this->GetColor().R, this->GetColor().G, this->GetColor().B);
	glTranslatef(this->GetPosition().X, this->GetPosition().Y, this->GetPosition().Z);
	glRotatef(this->GetAngleRotation(), this->GetAxisRotation().X, this->GetAxisRotation().Y, this->GetAxisRotation().Z);
	glScalef(this->GetScale().X, this->GetScale().Y, this->GetScale().Z);
	for(int i = 0; i < faces.size(); i++)
	{
		glBegin(GL_POLYGON);
		for(int j = 0; j < faces[i].NormalIndex.size(); j++)
		{

		int nIndx = faces[i].NormalIndex[j] - 1;
			float x, y ,z;

			x = normals[nIndx].x;
			y = normals[nIndx].y;
			z = normals[nIndx].z;

			glNormal3f(x, y, z);

		int vIndx = faces[i].VertexIndex[j] - 1;

			x = vertices[vIndx].x;
			y = vertices[vIndx].y;
			z = vertices[vIndx].z;

			glVertex3f(x, y, z);
		}
		glEnd();
	}

	if(this->showPivot) {
		glPushMatrix();
		glNormal3f(0.0f, 1.0f, 0.0f);
		// x-axis
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(15.0f, 0.0f, 0.0f);
		glEnd();

		// y-axis
		glColor3f(0.0f, 1.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 15.0f, 0.0f);
		glEnd();

		// z-axis
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINES);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 15.0f);
		glEnd();
		glPopMatrix();
	}

	glPopMatrix();

	if(this->showCollider) this->DrawCollider();
}