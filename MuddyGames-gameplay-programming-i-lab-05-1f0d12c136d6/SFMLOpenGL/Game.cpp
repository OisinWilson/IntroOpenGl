#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
	index = glGenLists(primatives);
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


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();

}

void Game::update()
{
	//cout << "Update up" << endl;
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	//glMatrixMode(GL_PROJECTION); 
	//glLoadIdentity(); 
	//gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	//glMatrixMode(GL_MODELVIEW);

	//glLoadIdentity();

	//glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);

	//glTranslatef(0.0001f, 0.0f, 0.0f);

	//glScalef(0.999f, 0.999f, 1.0f);


	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
}

void Game::draw()
{
	cout << "Draw up" << endl;

	/*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glBegin(GL_TRIANGLES); { 
		glVertex3f(4.0, 5.0, -15.0);
		glVertex3f(5.0, 5.0, -15.0);
		glVertex3f(4.5, 4.0, -15.0); 
	}
	glEnd();

	glPointSize(10);
	glBegin(GL_POINTS); {

		glVertex3f(-2.0, 2.0, -5.0);
		glVertex3f(-2.0, 1.8, -5.0);
		glVertex3f(-1.9, 1.9, -5.0);
	}
	glEnd();


	glBegin(GL_LINES); {
		glVertex3f(-1.5, 2.0, -5.0);
		glVertex3f(-1.3, 1.8, -5.0);
	}
	glEnd();

	glBegin(GL_LINE_STRIP); {
		glVertex3f(-1.4, 2.0, -5.0);
		glVertex3f(-1.2, 1.8, -5.0);
	}
	glEnd();

	glBegin(GL_LINE_LOOP); {
		glVertex3f(-1.6, 2.0, -5.0);
		glVertex3f(-1.4, 1.8, -5.0);
	}
	glEnd();
	
	glBegin(GL_TRIANGLE_STRIP); {
		glVertex3f(-1.4, 0.3, -5.0);
		glVertex3f(-1.8, 0.7, -5.0);
		glVertex3f(-2.0, 0.5, -5.0);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN); {
		glVertex3f(1.8, 0.3, -5.0);
		glVertex3f(2.0, 0.7, -5.0);
		glVertex3f(1.6, 0.5, -5.0);
	}
	glEnd();

	glBegin(GL_QUADS); {
		glVertex3f(-1.0, -0.1, -5.0);
		glVertex3f(-1.0, -0.3, -5.0);
		glVertex3f(-1.5, -0.3, -5.0);
		glVertex3f(-1.5, -0.1, -5.0);
	}
	glEnd();

	glBegin(GL_QUAD_STRIP); {
		glVertex3f(-1.6, -0.4, -5.0);
		glVertex3f(-1.6, -0.3, -5.0);
		glVertex3f(-1.8, -0.3, -5.0);
		glVertex3f(-1.8, -0.4, -5.0);
	}
	glEnd();

	glBegin(GL_POLYGON); {
		glVertex3f(-1.0, -0.6, -5.0);
		glVertex3f(-1.0, -0.8, -5.0);
		glVertex3f(-1.5, -0.8, -5.0);
		glVertex3f(-1.5, -0.6, -5.0);
		glVertex3f(-1.2, -0.9, -5.0);
	}
	glEnd();*/


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Primative " << current << endl;

	glCallList(current);

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

