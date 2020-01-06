#include <Game.h>

bool updatable = false;

gpp::Vector3 v3;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(v3.getX(), 1.0f, -5.0f);
		glVertex3f(-1.0f, 1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);

		glVertex3f(1.0f, -1.0f, -5.0f);
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glVertex3f(v3.getX(), 1.0f, -5.0f);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -15.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);
		glVertex3f(1.0f, -1.0f, -15.0f);

		glVertex3f(-1.0f, 1.0f, -15.0f);
		glVertex3f(1.0f, 1.0f, -15.0f);
		glVertex3f(-1.0f, -1.0f, -15.0f);


		//Side n0 1
		glColor3f(0.8f, 0.498039f, 0.196078f);//GOLD FACE   
		glVertex3f(v3.getX(), 1.0f, -5.0f);
		glColor3f(1.0f, 0.0f, 0.0f);//o FACE  
		glVertex3f(-1.0f, 1.0f, -15.0f);
		glColor3f(1.0f, 0.498039f, 0.0f);//COARL FACE  
		glVertex3f(1.0f, 1.0f, -15.0f);

		glColor3f(1.0f, 0.0f, 0.0f);//o FACE  
		glVertex3f(-1.0f, 1.0f, -15.0f);
		glColor3f(0.8f, 0.498039f, 0.196078f);//RED FACE  
		glVertex3f(v3.getX(), 1.0f, -5.0f);
		glColor3f(1.0f, 0.498039f, 0.0f);//CORAL FACE  
		glVertex3f(-1.0f, 1.0f, -5.0f);

		//Side n0 2
		glColor3f(0.85f, 0.85f, 0.95f);//YELLOW FACE  
		glVertex3f(v3.getX(), 1.0f, -5.0f);
		glColor3f(1.00f, 0.43f, 0.78f);//dr FACE
		glVertex3f(1.0f, 1.0f, -15.0f);
		glColor3f(0.560784f, 0.737255f, 0.560784f);//YELLOW FACE
		glVertex3f(1.0f, -1.0f, -15.0f);

		glColor3f(0.85f, 0.85f, 0.95f);//YELLOW FACE  
		glVertex3f(v3.getX(), 1.0f, -5.0f);
		glColor3f(0.560784f, 0.737255f, 0.560784f);//YELLOW FACE
		glVertex3f(1.0f, -1.0f, -15.0f);
		glColor3f(1.00f, 0.43f, 0.78f);//dr FACE
		glVertex3f(1.0f, -1.0f, -5.0f);

		//Side n0 3
		glColor3f(0.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(1.0f, -1.0f, -5.0f);
		glColor3f(1.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(1.0f, -1.0f, -15.0f);
		glColor3f(0.22f, 0.69f, 0.87f);//PURPLE FACE  
		glVertex3f(-1.0f, -1.0f, -15.0f);

		glColor3f(0.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(1.0f, -1.0f, -5.0f);
		glColor3f(0.22f, 0.69f, 0.87f);//PURPLE FACE  
		glVertex3f(-1.0f, -1.0f, -15.0f);
		glColor3f(1.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(-1.0f, -1.0f, -5.0f);



		//Side n0 4
		glColor3f(1.0f, 1.0f, 1.0f);//WHITE FACE  
		glVertex3f(-1.0f, -1.0f, -15.0f);
		glColor3f(0.0f, 20.0f, 55.0f);//CYAN FACE  
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glColor3f(1.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(-1.0f, 1.0f, -15.0f);

		glColor3f(0.0f, 20.0f, 55.0f);//CYAN FACE  
		glVertex3f(-1.0f, -1.0f, -5.0f);
		glColor3f(1.0f, 0.0f, 1.0f);//PURPLE FACE 
		glVertex3f(-1.0f, 1.0f, -15.0f);
		glColor3f(1.0f, 1.0f, 1.0f);//WHITE FACE  
		glVertex3f(-1.0f, 1.0f, -5.0f);

	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

