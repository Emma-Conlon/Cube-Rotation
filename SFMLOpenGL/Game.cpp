#include <Game.h>

bool updatable = false;



Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube")
{
	
	index = glGenLists(1);
}

Game::~Game() {}

void Game::run()
{

	initialize();
	
	sf::Event event;

	while (isRunning) {

		cout << "Game running..." << endl;
	
		while (window.pollEvent(event))
		{
		
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
			processEvents(event);
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
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{


		////Front Face---------------------------------------------------------
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());


		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());



		////Back Face----------------------------------------------------------

		glColor3f(0.0f, 1.0f, 0.0f);

		glVertex3f(points[6].getX(), points[6].getY(), points[6].getZ());
		glVertex3f(points[7].getX(), points[7].getY(), points[7].getZ());
		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());

		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());
		glVertex3f(points[5].getX(), points[5].getY(), points[5].getZ());
		glVertex3f(points[6].getX(), points[6].getY(), points[6].getZ());


		////Side n0 1----------------------------------------------------------

		glColor3f(0.8f, 0.498039f, 0.196078f);//GOLD FACE   
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glColor3f(1.0f, 0.0f, 0.0f);//o FACE  
		glVertex3f(points[7].getX(), points[7].getY(), points[7].getZ());
		glColor3f(1.0f, 0.498039f, 0.0f);//COARL FACE  
		glVertex3f(points[6].getX(), points[6].getY(), points[6].getZ());

		glColor3f(1.0f, 0.0f, 0.0f);//o FACE  
		glVertex3f(points[7].getX(), points[7].getY(), points[7].getZ());
		glColor3f(0.8f, 0.498039f, 0.196078f);//RED FACE  
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glColor3f(1.0f, 0.498039f, 0.0f);//CORAL FACE  
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());

		////Side n0 2-----------------------------------------------------------

		glColor3f(0.85f, 0.85f, 0.95f);//YELLOW FACE  
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glColor3f(1.00f, 0.43f, 0.78f);//dr FACE
		glVertex3f(points[6].getX(), points[6].getY(), points[6].getZ());
		glColor3f(0.560784f, 0.737255f, 0.560784f);//YELLOW FACE
		glVertex3f(points[5].getX(), points[5].getY(), points[5].getZ());

		glColor3f(0.85f, 0.85f, 0.95f);//YELLOW FACE  
		glVertex3f(points[2].getX(), points[2].getY(), points[2].getZ());
		glColor3f(0.560784f, 0.737255f, 0.560784f);//YELLOW FACE
		glVertex3f(points[5].getX(), points[5].getY(), points[5].getZ());
		glColor3f(1.00f, 0.43f, 0.78f);//dr FACE
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());

		////Side n0 3----------------------------------------------------------

		glColor3f(0.0f, 0.0f, 1.0f);//PURPLE FACE 
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glColor3f(1.0f, 0.0f, 0.0f);//PURPLE FACE  
		glVertex3f(points[5].getX(), points[5].getY(), points[5].getZ());
		glColor3f(0.22f, 0.69f, 0.87f);//PURPLE FACE  
		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());

		glColor3f(0.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(points[1].getX(), points[1].getY(), points[1].getZ());
		glColor3f(0.22f, 0.69f, 0.87f);//PURPLE FACE  
		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());
		glColor3f(1.0f, 0.0f, 0.0f);//PURPLE FACE  
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());



		////Side n0 4----------------------------------------------------------
		/// 
		glColor3f(1.0f, 1.0f, 1.0f);//WHITE FACE  
		glVertex3f(points[4].getX(), points[4].getY(), points[4].getZ());
		glColor3f(0.0f, 20.0f, 55.0f);//CYAN FACE  
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glColor3f(1.0f, 0.0f, 1.0f);//PURPLE FACE  
		glVertex3f(points[7].getX(), points[7].getY(), points[7].getZ());

		glColor3f(0.0f, 20.0f, 55.0f);//CYAN FACE  
		glVertex3f(points[0].getX(), points[0].getY(), points[0].getZ());
		glColor3f(1.0f, 0.0f, 1.0f);//PURPLE FACE 
		glVertex3f(points[7].getX(), points[7].getY(), points[7].getZ());
		glColor3f(1.0f, 1.0f, 1.0f);//WHITE FACE  
		glVertex3f(points[3].getX(), points[3].getY(), points[3].getZ());

	}
	glEnd();
	glEndList();
	
	


	//glEnable()
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	glTranslatef(0, 0, -8);
	glCallList(1);
	glDeleteLists(0, 1);
	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::processEvents(sf::Event t_event)
{
	if (sf::Keyboard::Z == t_event.key.code)//rotating the Z axis but broken ;-; 
	{
		Matrix3 rz;
		rz = rz.RotationZ(m_angle);

		if (t_event.key.shift)
		{
			//backwards on Z axis 
			rz = rz.RotationZ(-m_angle);
		}
		for (int i = 0; i < 8; i++)
		{
			points[i] = rz * points[i];
		}
	}

	if (sf::Keyboard::X == t_event.key.code)//rotating the X axis
	{
		Matrix3 rx;
		rx = rx.RotationX(m_angle);

		if (t_event.key.shift)
		{
			//backwards on X axis 
			rx = rx.RotationX(-m_angle);
		}
		for (int i = 0; i < 8; i++)
		{
			points[i] = rx * points[i];
		}
	}

	if (sf::Keyboard::Y == t_event.key.code)//rotating the Y axis 
	{
		Matrix3 ry;
		ry = ry.RotationY(m_angle);

		if (t_event.key.shift)
		{
			//backwards on Y  axis 
			ry = ry.RotationY(-m_angle);
		}
		for (int i = 0; i < 8; i++)
		{
			points[i] = ry * points[i];
		}
	}

	if (sf::Keyboard::E == t_event.key.code)//scaling 
	{
		Matrix3 scale;
		scale = scale.Scale(101, 101);

		if (t_event.key.shift)
		{
			//backwards
			scale = scale.Scale(99, 99);
		}
		for (int i = 0; i < 8; i++)
		{
			points[i] = scale * points[i];
		}
	}

	if (sf::Keyboard::W == t_event.key.code)//going up 
	{
		Matrix3 up;
		up = up.Translate(0.0, -1.1);

		for (int i = 0; i < 8; i++)
		{
			points[i] = up * points[i];
		}
	}

	if (sf::Keyboard::S == t_event.key.code)//going down 
	{
		Matrix3 down;
		down = down.Translate(0.0, 1.1);

		for (int i = 0; i < 8; i++)
		{
			points[i] = down * points[i];
		}
	}

	if (sf::Keyboard::A == t_event.key.code)//going left 
	{
		Matrix3 left;
		left = left.Translate(-1.1, 0.0);

		for (int i = 0; i < 8; i++)
		{
			points[i] = left * points[i];
		}
	}

	if (sf::Keyboard::D == t_event.key.code)//going right 
	{
		Matrix3 right;
		right = right.Translate(1.1, 0.0);

		for (int i = 0; i < 8; i++)
		{
			points[i] = right * points[i];
		}
		cout << "WENT RIGHT";
	}


}

