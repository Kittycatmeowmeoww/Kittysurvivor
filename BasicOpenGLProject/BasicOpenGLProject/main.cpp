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
/* � type definitions ������������������ */
float posX = 0, posY = 0,posZ=0;
float move_unit = 0.1f;




//none moving object speed
float nonControllablePosX = 0.40f;
float nonControllablePosY = 0.0f;
float nonControllableSpeedX = 0.1f;  // Adjust speed as needed
float nonControllableSpeedY = 0.20f;  // Adjust speed as needed

void updateNonControllableSquare() //postions of the none moving square
{
	// Update position based on speed
	nonControllablePosX += nonControllableSpeedX;
	nonControllablePosY += nonControllableSpeedY;

	// Example: Reverse direction if square hits boundaries
	if (nonControllablePosX > 1.0f || nonControllablePosX < -1.0f)
		nonControllableSpeedX *= -1.0f;
	if (nonControllablePosY > 1.0f || nonControllablePosY < -1.0f)
		nonControllableSpeedY *= -1.0f;
}



void idle_func()
{
	// Update the position of the non-controllable square
	updateNonControllableSquare();
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



void key_special_pressed( int key, int x, int y )
{
}

void key_special_released( int key, int x, int y )
{
}

void mouse_func( int button, int state, int x, int y )
{
}

void passive_motion_func( int x, int y )
{
}

void active_motion_func( int x, int y )
{
}

//=================================================================================================
// RENDERING
//=================================================================================================


void display_func( void )// Kat thing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	// Update the position of the non-controllable square
	updateNonControllableSquare();

	// Draw non-controllable square at its current position
	glLoadIdentity();  // Reset the modelview matrix
	glTranslatef(nonControllablePosX, nonControllablePosY, posZ);
	glColor3f(0.4f, 0.30f, 0.23f);  // Set color for non-controllable square
	glBegin(GL_POLYGON);
	glVertex2f(-0.2, 0.2);
	glVertex2f(0.9, 0.2);
	glVertex2f(0.9, -0.2);
	glVertex2f(0.91f, 0.1f);
	glVertex2f(0.94f, 0.1f);
	glVertex2f(0.25f, 0.4f);
	glVertex2f(0.4f, 0.1f);
	glVertex2f(0.4f, 0.1f);
	glVertex2f(0.2f, 0.6f);
	glEnd();

	// Draw controllable square (unchanged)
	glLoadIdentity();  // Reset the modelview matrix
	glTranslatef(posX, posY, posZ);
	glColor3f(1.0f, 0.0f, 0.0f);  // Set color for controllable square
	glBegin(GL_POLYGON);
	glVertex2f(-0.1, 0.2);
	glVertex2f(0.91, 0.2);
	glVertex2f(0.91, -0.2);
	glVertex2f(0.91f, 0.1f);
	glVertex2f(0.94f, 0.1f);
	glVertex2f(0.25f, 0.4f);
	glVertex2f(0.4f, 0.1f);
	glVertex2f(0.4f, 0.1f);
	glVertex2f(0.2f, 0.6f);
	glEnd();

	glPopMatrix();
	glFlush();

	glutSwapBuffers();



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
	glutInit( &argc, argv );

	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( 1920, 1080 );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	
	glutCreateWindow( "i shidded in my pants" );

	glutDisplayFunc( display_func );
	//glutIdleFunc( idle_func );

	glutIgnoreKeyRepeat(1);
	glutReshapeFunc( reshape_func );
	glutKeyboardFunc( keyboard_func );
	glutKeyboardUpFunc( key_released );
	glutSpecialFunc( keyboardown );
	glutSpecialUpFunc( key_special_released );
	glutMouseFunc( mouse_func );
	glutMotionFunc( active_motion_func );
	glutPassiveMotionFunc( passive_motion_func );
	glutIdleFunc(idle_func);  // Register idle function to continuously update the scene
	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}
