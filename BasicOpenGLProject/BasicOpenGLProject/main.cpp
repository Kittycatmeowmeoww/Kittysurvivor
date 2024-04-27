#include <GL/freeglut.h>
#include <iostream>
#define myTranslate2D(x,y) glTranslated(x, y, 0.0)
#define myScale2D(x,y) glScalef(x, y, 1.0)
#define MAX_ACC_PLAYER  0.15
#define MAX_VELO_PLAYER 2
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








void idle_func()
{
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

void display_func( void )
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.1, -0.2);
	glVertex2f(-0.1, 0.2);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.1, -0.2);
	glEnd();
	glPopMatrix();
	glFlush();



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
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
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

	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}
