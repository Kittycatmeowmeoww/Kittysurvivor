#include <GL/freeglut.h>
#include <iostream>

//=================================================================================================
// CALLBACKS
//=================================================================================================

//-----------------------------------------------------------------------------
// CALLBACK DOCUMENTATION
// https://www.opengl.org/resources/libraries/glut/spec3/node45.html
// http://freeglut.sourceforge.net/docs/api.php#WindowCallback
//-----------------------------------------------------------------------------

//player values
float posX = 0, posY = 0,posZ=0;
float move_unit = 0.1f;
//base npc values
float nonControllablePosX = 0.40f;
float nonControllablePosY = 0.0f;
float nonControllableSpeedX = 0.001f;  // Adjust speed as needed
float nonControllableSpeedY = 0.001f;  // Adjust speed as needed



struct npc {
	float speedX = nonControllableSpeedX;
	float speedY = nonControllableSpeedY;
	float posX = nonControllablePosX;
	float posY = nonControllablePosY;
	void updatepos();
};
void npc::updatepos() {
	posX += speedX;
	posY += speedY;
	//speedX += .0001f;
	//speedY += .0001f;
	if (posX > 1.0f || posX < -1.0f)
		speedX *= -1.0f;
	if (posY > 1.0f || posY < -1.0f)
		speedY *= -1.0f;

}
struct boss : public npc {
	boss() {
		speedX = 20 * speedX;
		speedY = 30 * speedY;
	}
};
npc nonplayer1;
npc nonplayer2;
npc nonplayer3;
npc nonplayer4;
boss nonplayer5;

void updateNonControllableSquare(npc &npc){
	npc.updatepos();

}

bool checkCollision(float x1, float y1, float x2, float y2, float size) {
	return (abs(x1 - x2) * 2 < (size * 2)) && (abs(y1 - y2) * 2 < (size * 2));
}
void checkCollisions() {
	if (checkCollision(posX, posY, nonplayer1.posX, nonplayer1.posY, 0.1f)) {
		posX = 0;
		posY = 0;
	}
	if (checkCollision(posX, posY, nonplayer2.posX, nonplayer2.posY, 0.1f)) {
		posX = 0;
		posY = 0;
	}
	if (checkCollision(posX, posY, nonplayer3.posX, nonplayer3.posY, 0.1f)) {
		posX = 0;
		posY = 0;
	}
	if (checkCollision(posX, posY, nonplayer4.posX, nonplayer4.posY, 0.1f)) {
		posX = 0;
		posY = 0;
	}
	if (checkCollision(posX, posY, nonplayer5.posX, nonplayer5.posY, 0.1f)) {
		posX = 0;
		posY = 0;
	}
}

void idle_func()
{
	// Update the position of the non-controllable square
	updateNonControllableSquare(nonplayer1);
	updateNonControllableSquare(nonplayer2);
	updateNonControllableSquare(nonplayer3);
	updateNonControllableSquare(nonplayer4);
	updateNonControllableSquare(nonplayer5);
	checkCollisions();

	//uncomment below to repeatedly draw new frames
	glutPostRedisplay();
}

void reshape_func( int width, int height )
{
	glViewport( 0, 0, width, height );
	glutPostRedisplay();
}

void keyboard_func( unsigned char key, int x, int y )
{
	switch( key )
	{
		case 'w':
		{
			posY += move_unit;;
			break;
		}

		case 'a':
		{
			posX -= move_unit;;
			break;
		}

		case 's':
		{
			posY -= move_unit;;
			break;
		}

		case 'd':
		{
			posX += move_unit;;
			break;
		}

		// Exit on escape key press
		case '\x1B':
		{
			exit( EXIT_SUCCESS );
			break;
		}
	}

	glutPostRedisplay();
}

void key_released( unsigned char key, int x, int y )
{
	switch (key) {
		case 'w':

			break;

		case 'a':

			break;
	
		case 's':

			break;
	
		case 'd':

			break;

		default:
			break;
		}
	glutPostRedisplay();
}

//=================================================================================================
// RENDERING
//=================================================================================================
void renderHUD() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// Rendering HUD elements
	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2i(10, glutGet(GLUT_WINDOW_HEIGHT) - 20);
	std::string hudText = "Health: ";
	for (const char& letter : hudText) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
	}

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}


void drawNPC(npc &npc) {

	// Update the position of the non-controllable square

	updateNonControllableSquare(npc);
	// Draw non-controllable square at its current position
	glLoadIdentity();  // Reset the modelview matrix
	glTranslatef(npc.posX,npc.posY, posZ);
	glColor3f(1.4f, 0.0f, 0.f);  // Set color for non-controllable square
	glBegin(GL_POLYGON);
	glVertex2f(-0.02, 0.02);
	glVertex2f(0.09, 0.02);
	glVertex2f(0.09, -0.02);
	glVertex2f(0.091f, 0.01f);
	glVertex2f(0.094f, 0.01f);
	glVertex2f(0.025f, 0.04f);
	glVertex2f(0.04f, 0.01f);
	glVertex2f(0.04f, 0.01f);
	glVertex2f(0.02f, 0.06f);
	glEnd();
}
void drawBoss(npc& npc) {

	// Update the position of the non-controllable square

	updateNonControllableSquare(npc);
	// Draw non-controllable square at its current position
	glLoadIdentity();  // Reset the modelview matrix
	glTranslatef(npc.posX, npc.posY, posZ);
	glColor3f(1.4f, 1.0f, 0.f);  // Set color for non-controllable square
	glBegin(GL_POLYGON);
	glVertex2f(-0.02, 0.02);
	glVertex2f(0.09, 0.02);
	glVertex2f(0.09, -0.02);
	glVertex2f(0.091f, 0.01f);
	glVertex2f(0.094f, 0.01f);
	glVertex2f(0.025f, 0.04f);
	glVertex2f(0.04f, 0.01f);
	glVertex2f(0.04f, 0.01f);
	glVertex2f(0.02f, 0.06f);
	glEnd();
}
void drawPlayer() {
	glLoadIdentity();
	glTranslatef(posX, posY, posZ);
	glColor3f(0.f, 0.0f, 0.f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.01, 0.02);
	glVertex2f(0.091, 0.02);
	glVertex2f(0.091, -0.02);
	glVertex2f(0.091f, 0.01f);
	glVertex2f(0.094f, 0.01f);
	glVertex2f(0.025f, 0.04f);
	glVertex2f(0.04f, 0.01f);
	glVertex2f(0.04f, 0.01f);
	glVertex2f(0.02f, 0.06f);
	glEnd();
	glPopMatrix();
	glFlush();
}


void display_func(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();




	drawNPC(nonplayer1);
	drawNPC(nonplayer2);
	drawNPC(nonplayer3);
	drawNPC(nonplayer4);
	drawBoss(nonplayer5);
	renderHUD();


	drawPlayer();



	glutSwapBuffers();
}
void keyboardown(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
		posX += move_unit;;
		break;

	case GLUT_KEY_LEFT:
		posX -= move_unit;;
		break;

	case GLUT_KEY_UP:
		posY += move_unit;;
		break;

	case GLUT_KEY_DOWN:
		posY -= move_unit;;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


//=================================================================================================
// INIT
//=================================================================================================

void init( void )
{
	// Print some info
	std::cout << "Vendor:         " << glGetString( GL_VENDOR   ) << "\n";
	std::cout << "Renderer:       " << glGetString( GL_RENDERER ) << "\n";
	std::cout << "OpenGL Version: " << glGetString( GL_VERSION  ) << "\n\n";

	// Set the background color
	glClearColor( 0.4f, 0.9f, 0.4f, 0.0f );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	std::cout << "Dont forget to like and subscribe.\n";
	std::cout << "Kittycat\n";
	std::cout << "Finished initializing...\n\n";
}

//=================================================================================================
// MAIN
//=================================================================================================

int main( int argc, char** argv )
{


	nonplayer2.posX = 0.2f;
	nonplayer3.posX = 1.0f;
	nonplayer4.posX = -0.2f;
	nonplayer2.posY = -0.2f;
	nonplayer3.posY = -0.2f;
	srand(time(nullptr));

	// Generate random starting positions for non-players
	nonplayer1.posX = (rand() % 200 - 100) / 100.0f; // Random value between -1.0 and 1.0
	nonplayer1.posY = (rand() % 200 - 100) / 100.0f; // Random value between -1.0 and 1.0

	nonplayer2.posX = (rand() % 200 - 100) / 100.0f;
	nonplayer2.posY = (rand() % 200 - 100) / 100.0f;

	nonplayer3.posX = (rand() % 200 - 100) / 100.0f;
	nonplayer3.posY = (rand() % 200 - 100) / 100.0f;

	nonplayer4.posX = (rand() % 200 - 100) / 100.0f;
	nonplayer4.posY = (rand() % 200 - 100) / 100.0f;

	nonplayer5.posX = (rand() % 200 - 100) / 100.0f;
	nonplayer5.posY = (rand() % 200 - 100) / 100.0f;
	//nonplayer4.speedX = .01f;
	glutInit( &argc, argv );
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( 1920, 1080 );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutCreateWindow( "Kitty Survivor" );



	glutDisplayFunc( display_func);
	glutIdleFunc(idle_func);

	glutIgnoreKeyRepeat(1);
	glutReshapeFunc( reshape_func );
	glutKeyboardFunc( keyboard_func );
	glutKeyboardUpFunc( key_released );
	glutSpecialFunc( keyboardown );


	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}
