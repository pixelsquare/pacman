#include "../../atom/AtomEngine.h"
using namespace Atom::Engine;

#include <iostream>
using namespace std;

#pragma region Comments
//
// Developer's Build
//
// A simple Pac-man Game made out of Atom Engine
// this game include sound effects so put up your volume. :)
//
// Author: Dhenz Zerrudo
//
// Atom Engine Authors:
//		Anthony Ganzon
//		Dhenz Zerrudo
//
// NOTE!
// Please inform the author if you want to borrow
// this code/s (script/s) for authorization and copyright.
//
#pragma endregion

#define Title "Pac-Man using Atom Engine Build v1.5"						// Title of GLUT WINDOW

ModelLoad *pacman = new ModelLoad;											// Handles the Pacman Model
std::vector<ModelLoad> pacmanStorage;
Vector3 pacmanInitialPos(0.0f,0.0f, 0.0f);										// Initial position of pacman
float pacmanSpeed = 20.0f;														// Movement speed of pacman

int foodSize = 0;	
int mazeSize = 0;
int innerMazeSize = 0;
bool enableSound = true;
int score = 0;

void AddScore(int num) {
	score += num;
}

// Used in Start Function to Initialize pacman

void pacmanInitialize() {
	Sound::Play("assets\\pacman_beginning");
	pacman->LoadObj("assets\\pacman.obj");
	pacman->SetScale(Vector3::One * 0.5f);
	pacman->SetPosition(pacmanInitialPos);
	pacman->ApplyCollider(true);
	pacman->SetColliderSize(Vector3(2.0f,1.0f,0.5f));
	pacmanStorage.push_back(*pacman);

}

void pacmanRender() {
	if(!pacmanStorage.empty())
		pacmanStorage[0].RenderModel();
}

void pacmanRotate(char key)
{
	if(!pacmanStorage.empty())
	{
			if(key == 'a')
				pacmanStorage[0].SetRotation(0,0.0f,1.0f,0.0f);
			if(key == 'd')
				pacmanStorage[0].SetRotation(180,0.0f,1.0f,0.0f);
			if(key == 'w')
				pacmanStorage[0].SetRotation(-90,0.0f,0.0f,1.0f);
			if(key == 's')
				pacmanStorage[0].SetRotation(90,0.0f,0.0f,1.0f);
	}
	
}

bool rightMove,leftMove,upMove,downMove;
int pacmanSpd = 10;
bool middleUp;
bool middleHor;
int pacmanUpBound, pacmanDownBound, pacmanRightBound,pacmanLeftBound;
bool vertMoveUp, vertMoveDown,horMoveRight,horMoveLeft;

void BlockDetect()
{
		if(pacmanStorage[0].GetPosition().X >-39.5 && pacmanStorage[0].GetPosition().X < -29.3 || pacmanStorage[0].GetPosition().X >-25.8 && pacmanStorage[0].GetPosition().X < -15.6 ||
			pacmanStorage[0].GetPosition().X >-12.2 && pacmanStorage[0].GetPosition().X < -1.6 || pacmanStorage[0].GetPosition().X < 12.2 && pacmanStorage[0].GetPosition().X > 1.6 || 
			pacmanStorage[0].GetPosition().X < 25.8 && pacmanStorage[0].GetPosition().X > 15.6|| pacmanStorage[0].GetPosition().X < 39.5 && pacmanStorage[0].GetPosition().X > 29.3)
		{
			if( pacmanStorage[0].GetPosition().Y > 39.1 && pacmanStorage[0].GetPosition().Y < 39.3 || pacmanStorage[0].GetPosition().Y < -2.1 && pacmanStorage[0].GetPosition().Y > -2.3)
			{
				vertMoveDown = false;
				vertMoveUp = true;
			}

			else if(pacmanStorage[0].GetPosition().Y < 2.3 && pacmanStorage[0].GetPosition().Y > 2.1  || pacmanStorage[0].GetPosition().Y>-39.3  && pacmanStorage[0].GetPosition().Y<-39.1)
			{
				vertMoveDown = true;
				vertMoveUp = false;
			}
			else
			{
				vertMoveUp = true;
				vertMoveDown = true;
			}
		}
		
		else
		{
			vertMoveUp = true;
			vertMoveDown = true;
		}

		if(pacmanStorage[0].GetPosition().Y < 39.2 && pacmanStorage[0].GetPosition().Y > 2.2 || pacmanStorage[0].GetPosition().Y < -2.2 && pacmanStorage[0].GetPosition().Y > -39.2)
		{
			if(pacmanStorage[0].GetPosition().X < 39.7 && pacmanStorage[0].GetPosition().X > 39.5 || pacmanStorage[0].GetPosition().X < 25.9 && pacmanStorage[0].GetPosition().X > 25.7 ||
				pacmanStorage[0].GetPosition().X < 12.3 && pacmanStorage[0].GetPosition().X > 12.1 || pacmanStorage[0].GetPosition().X > -1.7 && pacmanStorage[0].GetPosition().X < -1.5 || 
				pacmanStorage[0].GetPosition().X > -15.7 && pacmanStorage[0].GetPosition().X < -15.5 || pacmanStorage[0].GetPosition().X > -29.3 && pacmanStorage[0].GetPosition().X < -29.1)
			{
				horMoveLeft = false;
				horMoveRight = true;
			}

			else if(pacmanStorage[0].GetPosition().X > -39.9 && pacmanStorage[0].GetPosition().X < -39.7 || pacmanStorage[0].GetPosition().X > -25.9 && pacmanStorage[0].GetPosition().X < -25.7 || 
				pacmanStorage[0].GetPosition().X > -12.3 && pacmanStorage[0].GetPosition().X < -12.1 || pacmanStorage[0].GetPosition().X < 1.7 && pacmanStorage[0].GetPosition().X > 1.5 ||
				pacmanStorage[0].GetPosition().X < 15.7 && pacmanStorage[0].GetPosition().X > 15.5 || pacmanStorage[0].GetPosition().X < 29.3 && pacmanStorage[0].GetPosition().X > 29.1)
			{
				horMoveLeft = true;
				horMoveRight = false;
			}

			else
			{
				horMoveRight = true;
				horMoveLeft = true;
			}
		}

		else
		{
			horMoveRight = true;
			horMoveLeft = true;
		}
}

void pacmanMovement() {
		if(pacmanStorage[0].GetPosition().X > -2 && pacmanStorage[0].GetPosition().X < 2)
			middleUp = true;
		if(pacmanStorage[0].GetPosition().X < -2 || pacmanStorage[0].GetPosition().X > 2)
			middleUp = false;
		if(pacmanStorage[0].GetPosition().Y > -2 && pacmanStorage[0].GetPosition().Y < 2)
			middleHor = true;
		if(pacmanStorage[0].GetPosition().Y < -2 || pacmanStorage[0].GetPosition().Y > 2)
			middleHor = false;

		if(middleUp)
		{
			pacmanUpBound = 46;
			pacmanDownBound = -46;
		}
		if(middleUp == false)
		{
			pacmanUpBound = 43;
			pacmanDownBound = -43;
		}
		if(middleHor)
		{
			pacmanRightBound = 46;
			pacmanLeftBound = -46;
		}
		if(middleHor == false)
		{
			pacmanRightBound = 43;
			pacmanLeftBound = -43;
		}

		if(horMoveLeft && leftMove && pacmanStorage[0].GetPosition().X > pacmanLeftBound)
			pacmanStorage[0].Move(pacmanSpd,Vector3(-1.0f,0.0f,0.0f));
		if(horMoveRight && rightMove && pacmanStorage[0].GetPosition().X < pacmanRightBound)
			pacmanStorage[0].Move(pacmanSpd,Vector3(1.0f,0.0f,0.0f));
		if(vertMoveDown && downMove && pacmanStorage[0].GetPosition().Y > pacmanDownBound)
			pacmanStorage[0].Move(pacmanSpd,Vector3(0.0f,-1.0f,0.0f));
		if(vertMoveUp && upMove && pacmanStorage[0].GetPosition().Y < pacmanUpBound)
			pacmanStorage[0].Move(pacmanSpd,Vector3(0.0f,1.0f,0.0f));


		if(pacmanStorage[0].GetPosition().X > -2 && pacmanStorage[0].GetPosition().X < 2 && pacmanStorage[0].GetPosition().Y >= 45)
			pacmanStorage[0].SetPosition(0.0f,-44,0.0f);
		if(pacmanStorage[0].GetPosition().X > -2 && pacmanStorage[0].GetPosition().X < 2 && pacmanStorage[0].GetPosition().Y <=-45)
			pacmanStorage[0].SetPosition(0.0f,44.0f,0.0f);	
		if(pacmanStorage[0].GetPosition().Y > -2 && pacmanStorage[0].GetPosition().Y < 2 && pacmanStorage[0].GetPosition().X >= 45)
			pacmanStorage[0].SetPosition(-44.0f,0.0f,0.0f);
		if(pacmanStorage[0].GetPosition().Y > -2 && pacmanStorage[0].GetPosition().Y < 2 && pacmanStorage[0].GetPosition().X <=-45)
			pacmanStorage[0].SetPosition(44.0f,0.0f,0.0f);	
}

Primitive *particle = new Primitive;
std::vector<Primitive> particleStorage;
Vector3 *direction = new Vector3();
std::vector<Vector3> directionStorage;
const int PARTICLE_SIZE = 30;
const float MAX_ENERGY = 2.5f;
Time *particleTime = new Time();
float particleSpeed = 5.0f;

void ColorRandomizer(float &r, float &g, float &b) {
	r = (rand() % 100 + 1) / 100.0f;
	g = (rand() % 100 + 1) / 100.0f;
	b = (rand() % 100 + 1) / 100.0f;
}

void DirectionRandomizer(Vector3 &direction) {
	Vector3 dir;
	dir.X = (rand() % 100 + 1);
	dir.Y = (rand() % 100 + 1);
	dir.Z = (rand() % 100 + 1);

	int randX = rand() % 2;
	if(randX == 0) dir.X = -dir.X;

	int randY = rand() % 2;
	if(randY == 0) dir.Y = -dir.Y;

	int randZ = rand() % 2;
	if(randZ == 0) dir.Z = -dir.Z;

	direction = Vector3(dir.X, dir.Y, dir.Z);
}

void ParticleInitialize(Vector3 position) {
	for(int i = 0; i < PARTICLE_SIZE; i++) {
		if(i >= PARTICLE_SIZE)
			break;

		float r; float g; float b;
		r = 0.0f, g = 0.0f, b = 0.0f;
		ColorRandomizer(r, g, b);

		particle->SetColor(r, g, b);
		particle->SetPosition(position);
		particle->SetScale(Vector3::One * 0.3f);
		particleStorage.push_back(*particle);

		DirectionRandomizer(*direction);				// Explosion size is determined by the speed.
		direction->Normalize();
		directionStorage.push_back(*direction);
	}

	particleTime->LocalReset();
}
bool show, doneShow,actFalse,final,doneShowFinal;
void ParticleRender() {
	if(!particleStorage.empty()) {
		for(int i = 0; i < particleStorage.size(); i++){
			particleStorage.at(i).DrawPrimitive(PrimitiveType::Plane);
			particleStorage[i].Move(particleSpeed, directionStorage[i]);
		}
		if(final == true)
		{
			if(particleTime->LocalTimeElapsed() > MAX_ENERGY+2.5f) {
				particleStorage.clear();
				directionStorage.clear();
			}
		}
		else if(final == false)
		{
			if(particleTime->LocalTimeElapsed() > MAX_ENERGY) {
				particleStorage.clear();
				directionStorage.clear();
			}
		}
	}
	else {
		particleStorage.clear();
		directionStorage.clear();
	}
}

Time *finalParticleTime = new Time();
int particleCount = 0;
bool resetTime,doneReset;
void showParticle()
{
	
	if(score % 200 == 0 && score != 0)
	{
		show = true;
	}
	else
	{
		doneShow = false;
		show = false;
	}
	if(score == 1660)
	{
		final = true;
		particleCount = 1;
		resetTime = true;
	}

	else
	{
		resetTime = false;
		final = false;
		doneShowFinal = false;
		doneReset = false;
	}

	if(doneShow == false){
		if(show)
		{
			ParticleInitialize(pacmanStorage[0].GetPosition());	
			doneShow = true;
		}
	}

	if(doneReset == false)
	{
		if(resetTime)
		{
			finalParticleTime->LocalReset();
			doneReset = true;
		}
	}

	if(doneShowFinal == false)
	{
		if(final)
		{
			if(finalParticleTime->LocalTimeElapsed() > 0.0f && finalParticleTime->LocalTimeElapsed() < 0.1f)
			{
				Sound::Play("assets\\Explosion");
				ParticleInitialize(Vector3(-27.2f,0.0f,0.0f));
				ParticleInitialize(Vector3(27.2f,0.0f,0.0f));
			}

			else if(finalParticleTime->LocalTimeElapsed() > 1.0f && finalParticleTime->LocalTimeElapsed() < 1.1f)
			{
				Sound::Play("assets\\Explosion");
				ParticleInitialize(Vector3(0.0f,-37.2f,0.0f));
				ParticleInitialize(Vector3(0.0f,37.2f,0.0f));
			}

			else if(finalParticleTime->LocalTimeElapsed() > 2.0f && finalParticleTime->LocalTimeElapsed() < 2.1f)
			{
				Sound::Play("assets\\Explosion");
				ParticleInitialize(Vector3(27.6f,32.4f,0.0f));
				ParticleInitialize(Vector3(27.6f,-32.4f,0.0f));
			}

			else if(finalParticleTime->LocalTimeElapsed() > 3.0f && finalParticleTime->LocalTimeElapsed() < 3.1f)
			{
				Sound::Play("assets\\Explosion");
				ParticleInitialize(Vector3(-26.8f,-32.6f,0.0f));
				ParticleInitialize(Vector3(-26.8f,32.6f,0.0f));
			}

			else if(finalParticleTime->LocalTimeElapsed() > 4.0f && finalParticleTime->LocalTimeElapsed() < 4.1f)
			{
				Sound::Play("assets\\Explosion");
				ParticleInitialize(Vector3(-42.6f,41.2f,0.0f));
				ParticleInitialize(Vector3(42.6f,41.2f,0.0f));
			}

			else if(finalParticleTime->LocalTimeElapsed() > 5.0f && finalParticleTime->LocalTimeElapsed() < 5.1f)
			{
				Sound::Play("assets\\Explosion");
				ParticleInitialize(Vector3(-42.6f,-41.2f,0.0f));
				ParticleInitialize(Vector3(42.6f,-41.2f,0.0f));
			}
			else if(finalParticleTime->LocalTimeElapsed() > 6.0f && finalParticleTime->LocalTimeElapsed() < 6.1f)
			{
				doneShowFinal = true;
			}
		}
	}

}


Primitive *food = new Primitive;
std::vector<Primitive> foodStorage;
float xOffsetfood = 4.6;
float yOffsetfood = 4.6;

void foodInitialize() {
	for(int innerHeight = -9; innerHeight < 10; innerHeight++) {
		if(innerHeight > - 9 && innerHeight < 0 || innerHeight > 0 && innerHeight < 9)
		{
			for(int innerWidth = -9; innerWidth < 10; innerWidth++) {
				if(innerWidth == -9 || innerWidth == -6 || innerWidth == -3 || innerWidth == 3 || innerWidth == 6 || innerWidth == 9)
				{
					food->SetPosition(Vector3(innerWidth * xOffsetfood, innerHeight * yOffsetfood, 0.0f));
					food->ApplyCollider(true);
					foodStorage.push_back(*food);
				}

				if(innerWidth == 0)
				{
					if(innerHeight > -10 && innerHeight < -1 || innerHeight > 1 && innerHeight < 10)
					food->SetPosition(Vector3(innerWidth * xOffsetfood, innerHeight * yOffsetfood, 0.0f));
					food->ApplyCollider(true);
					foodStorage.push_back(*food);
				}
			}
		}

		if(innerHeight == -9 || innerHeight == 9)
		{
			for(int innerWidth = -9; innerWidth < 10; innerWidth++) {
				
					food->SetPosition(Vector3(innerWidth * xOffsetfood, innerHeight * yOffsetfood, 0.0f));
					food->ApplyCollider(true);
					foodStorage.push_back(*food);
			}
		}

		if(innerHeight == 0)
		{
			for(int innerWidth = -9; innerWidth < 10; innerWidth++) {
				if(innerWidth > -10 && innerWidth < -1 || innerWidth > 1 && innerWidth < 10)
				{
					food->SetPosition(Vector3(innerWidth * xOffsetfood, innerHeight * yOffsetfood, 0.0f));
					food->ApplyCollider(true);
					foodStorage.push_back(*food);
				}
			}
		}
	}
}

void foodRender() {
	if(!foodStorage.empty()) {
		for(int i = 0; i < foodStorage.size(); i++){
			if(i >= foodStorage.size())
				break;

			foodStorage[i].DrawPrimitive(PrimitiveType::Cube);
		}
	}
	else
		foodStorage.clear();

	foodSize = foodStorage.size();
	return;
}


Primitive *maze = new Primitive;
std::vector<Primitive> mazeStorage;
float xOffsetMaze = 2.3;
float yOffsetMaze = 2.3;

void MazeInitialize()
{	
	for(int mazeHeight = -20; mazeHeight < 21; mazeHeight++)
	{
		if(mazeHeight== -20 || mazeHeight == 20)
		{
			for(int i = -20; i < 21; i++)
			{	
				if(i>1 || i<-1)
				{
					maze->SetPosition(Vector3(i * xOffsetMaze, mazeHeight * yOffsetMaze, 0.0f));
					maze->ApplyCollider(true);
					maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));						
					mazeStorage.push_back(*maze);	
				}
				if(mazeHeight == 20)
				{
					if(i == 2 || i == -2)
					{
						maze->SetPosition(Vector3(i * xOffsetMaze, yOffsetMaze + (mazeHeight * yOffsetMaze), 0.0f));
						maze->ApplyCollider(true);
						maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));
						mazeStorage.push_back(*maze);	
					}
				}
				if(mazeHeight == -20)
				{
					if(i == 2 || i == -2)
					{
						maze->SetPosition(Vector3(i * xOffsetMaze, (mazeHeight * yOffsetMaze) - yOffsetMaze, 0.0f));
						maze->ApplyCollider(true);
						maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));
						mazeStorage.push_back(*maze);	
					}
				}
				if(mazeHeight == 20)
				{
					if(i == 2 || i == -2)
					{
						maze->SetPosition(Vector3(i * xOffsetMaze, (mazeHeight * yOffsetMaze), 0.0f));
						maze->ApplyCollider(true);
						maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));
						mazeStorage.push_back(*maze);	
					}
				}
			}
		}

		else 
		{
			for(int width = -20; width < 21; width++)
			{
				if(mazeHeight>1 || mazeHeight<-1)
				{
					if(width == -20 || width == 20)
					{
						maze->SetPosition(Vector3(width * xOffsetMaze,mazeHeight * yOffsetMaze, 0.0f));
						maze->ApplyCollider(true);
						maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));
						mazeStorage.push_back(*maze);
					}
				}
				if(width == -20)
				{
					if(mazeHeight == 2 || mazeHeight == -2)
					{
						maze->SetPosition(Vector3((width * xOffsetMaze) - xOffsetMaze,mazeHeight * yOffsetMaze, 0.0f));
						maze->ApplyCollider(true);
						maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));
						mazeStorage.push_back(*maze);
					}
				}
				if(width == 20)
				{
					if(mazeHeight == 2 || mazeHeight == -2)
					{
						maze->SetPosition(Vector3(xOffsetMaze + (width * xOffsetMaze),mazeHeight * yOffsetMaze, 0.0f));
						maze->ApplyCollider(true);
						maze->SetColliderSize(Vector3(1.0,1.0f,1.0f));
						mazeStorage.push_back(*maze);
					}
				}
			}	
		}
	}
}

void MazeRender() {
	if(!mazeStorage.empty()) {
		for(int i = 0; i < mazeStorage.size(); i++){
			if(i >= mazeStorage.size())
				break;

			mazeStorage[i].DrawPrimitive(PrimitiveType::Cube);
		}
	}
	else
		mazeStorage.clear();

	mazeSize = mazeStorage.size();
	return;
}

Primitive *innerMaze = new Primitive;
std::vector<Primitive> innerMazeStorage;
float xOffsetInnerMaze = 2.3;
float yOffsetInnerMaze = 2.3;

void innerMazeInitialize() {
	
	for(int innerHeight = -16; innerHeight < 17; innerHeight++) {
		if(innerHeight < -1 || innerHeight > 1)
		{
			for(int innerWidth = -16; innerWidth < 17; innerWidth++) {
				if(innerWidth == -16 || innerWidth == -15 || innerWidth == -14 || innerWidth == -10 || innerWidth == -9 || innerWidth == -8 ||
				innerWidth == -4 || innerWidth == -3 || innerWidth == -2 || innerWidth == 2 || innerWidth == 3 || innerWidth == 4 || 
				innerWidth == 8 || innerWidth == 9 || innerWidth == 10 || innerWidth == 14 || innerWidth == 15 || innerWidth == 16)
				{
					innerMaze->SetPosition(Vector3(innerWidth * xOffsetInnerMaze, innerHeight * yOffsetInnerMaze, 0.0f));
					innerMaze->ApplyCollider(true);
					innerMazeStorage.push_back(*innerMaze);
				}
			}
		}
	}
}

void innerMazeRender() {
	if(!innerMazeStorage.empty()) {
		for(int i = 0; i < innerMazeStorage.size(); i++){
			if(i >= innerMazeStorage.size())
				break;

			innerMazeStorage[i].DrawPrimitive(PrimitiveType::Cube);
		}
	}
	else
		innerMazeStorage.clear();

	innerMazeSize = innerMazeStorage.size();
	return;
}

void CleanUp() {
	innerMazeStorage.clear();
	foodStorage.clear();
	mazeStorage.clear();
}

void AtomEngine::Start() {
	AtomEngine::SetProjectName(Title);
	Camera::SetCameraEye(Vector3(0.0f, 0.0f, 120.0f));

	pacmanInitialize();
	foodInitialize();
	MazeInitialize();
	innerMazeInitialize();
}
//int timer;
void AtomEngine::Update() {
	//timer = Time::TimeElapsed();
	//if(timer > fireRate) {
	//	isFired = false;
	//}
	//cout<<timer<<endl;


	pacmanRender();
	BlockDetect();
	pacmanMovement();
	foodRender();
	ParticleRender();
	showParticle();
	innerMazeRender();
	MazeRender();
	TextRender();
}

void AtomEngine::CollisionDetection() {
	if(!pacmanStorage.empty()) {
		for(int i = 0; i < pacmanStorage.size(); i++){
			if(!pacmanStorage.empty() && !foodStorage.empty()) {
				for(int j = 0; j < foodStorage.size(); j++){
					if(pacmanStorage.size() > 0 && pacmanStorage[i].HasCollidedWith(foodStorage[j])) {
						foodStorage.erase(foodStorage.begin() + j);
						AddScore(10);
						Sound::Play("assets\\pacman_chomp");
					}
				}
			}
		}
	}

}

void AtomEngine::CleanUp() {


	AtomEngine::Clean(pacman);
	AtomEngine::Clean(pacmanInitialPos);
	AtomEngine::Clean(pacmanStorage);
	AtomEngine::Clean(pacmanSpeed);
	AtomEngine::Clean(score);

	AtomEngine::Clean(innerMaze);
	AtomEngine::Clean(innerMazeStorage);
	AtomEngine::Clean(xOffsetInnerMaze);
	AtomEngine::Clean(xOffsetInnerMaze);
	
	AtomEngine::Clean(maze);
	AtomEngine::Clean(mazeStorage);
	AtomEngine::Clean(xOffsetMaze);
	AtomEngine::Clean(xOffsetMaze);


	AtomEngine::Clean(food);
	AtomEngine::Clean(foodStorage);
	AtomEngine::Clean(xOffsetfood);
	AtomEngine::Clean(yOffsetfood);

}

void AtomEngine::TextRender()
{
	char text[100];

	sprintf(text,"Score: %d",score);
	Text::AddText(-3.0f,0.0f,0.0f, text);
}

void Input::KeyHold()
{

}

void Input::KeyUp(unsigned char key, int x, int y) {
	Input::KeyDown[key] = true;

	switch(key) {
	case 'a':
		pacmanRotate('a');
		rightMove = false;
		leftMove = true;
		upMove = false;
		downMove = false;
		break;
	case 'd':
		pacmanRotate('d');
		rightMove = true;
		leftMove = false;
		upMove = false;
		downMove = false;
		break;
	case 'w':
		pacmanRotate('w');
		rightMove = false;
		leftMove = false;
		upMove = true;
		downMove = false;
		break;
	case 's':
		pacmanRotate('s');
		rightMove = false;
		leftMove = false;
		upMove = false;
		downMove = true;
		break;

	case 'r':
		cout<<"X: "<<pacmanStorage[0].GetPosition().X<<endl;
		cout<<"Y: "<<pacmanStorage[0].GetPosition().Y<<endl;
		break;

	case 'm':
		enableSound = !enableSound;
		if(enableSound)
			Sound::Mute(false);
		else
			Sound::Mute(true);
		break;

	case 27:
		AtomEngine::ShutDown();
		exit(0);
		break;
	}
}