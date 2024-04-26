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
/* — type definitions —————————————————— */
typedef struct {
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

typedef struct Coords {
	double x, y;
} Coords;

typedef struct {
	double  x, y, phi, dx, dy, vmax, vmax2, radius;
} Player;
/* — function prototypes ————————————————— */

static void initialize();

// Keyboard
void keyboard(unsigned char, int, int);
void keyPress(int, int, int);
void keyRelease(int, int, int);


// Player
void drawPlayer(Player* p);
void movePlayer();
void checkMapBoundries();

// Display
void display();
void myReshape(int, int);

void setWindowValues();
/* — global variables —————————————————— */

static glutWindow win;

// State of cursor keys
static int up = 0;
static int down = 0;
static int left = 0;
static int right = 0;

static double x2;
static double y2;
static Player player;
static Coords coords;


void drawPlayer(Player* p) {

	glLineWidth(1.5);
	glEnable(GL_LINE_SMOOTH);
	glColor3f(0.2f, 0.9f, 1.0f);
	glPushMatrix();
		myTranslate2D(p->x, p->y);
		myScale2D(5, 5);
	/* Starting position */
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0f, 2.0f, 0.0f);   // Top
		glVertex3f(-1.0f, -1.0f, 0.0f);   // Bottom Left
		glVertex3f(1.0f, -1.0f, 0.0f);   // Bottom Right
	glEnd();
	glPopMatrix();
}
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
			left = 1;
			break;
		}

		case 'a':
		{
			up = 1;
			break;
		}

		case 's':
		{
			right = 1;
			break;
		}

		case 'd':
		{
			down = 1;
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


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	drawPlayer(&player);
	glutSwapBuffers();
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
	player.x = 50.0;
	player.y = 50.0;
	player.dx = player.dy = 0;
	player.vmax = MAX_VELO_PLAYER;
	player.vmax2 = MAX_VELO_PLAYER * MAX_VELO_PLAYER;
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
	glutIdleFunc( idle_func );

	glutIgnoreKeyRepeat(1);
	glutReshapeFunc( reshape_func );
	glutKeyboardFunc( keyboard_func );
	glutKeyboardUpFunc( key_released );
	glutSpecialFunc( key_special_pressed );
	glutSpecialUpFunc( key_special_released );
	glutMouseFunc( mouse_func );
	glutMotionFunc( active_motion_func );
	glutPassiveMotionFunc( passive_motion_func );

	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}
