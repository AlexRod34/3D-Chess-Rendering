/*
Author: Alex Rodriguez
Class: ECE4122  
Last Date Modified: 11/22/2019
Description: An openGL program that renders a chess set and provides lighting settings: 
key 0 enables/disables ambient lighting
key 1 enables/disables diffused lighting
Also provides rotation of the chess set using key r/R, rotating counterclockwise by 10 degrees about z axis
and eye movement of the chess set by pressing u/U to move eye up and d/D to move eye down.
*/

#include <GL/glut.h>

// global variables to keep track of lights being on/off, viewing angle of Z, and angle of rotation about Z
int light0On = 0;
int light1On = 0;
float zView = 10.0;
float angle = 0.0;

/*
Functon initializes the values of each light, values of materials, and enables all lights to be on when 
program is first opened. Takes in no arguments and returns no arguments
*/
void init(void)
{

	glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    // light0 values
    GLfloat light0_ambient[] = { 0.2, 0.2, 0.2, 1.0 }; 
    GLfloat light0_diffuse[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light0_specular[] = { 0.0, 0.0, 0.0, 1.0 };
	// light1 values
	GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light1_diffuse[] = { 0.5, 0.5, 0.5, 1.0 }; 
    GLfloat light1_position[] = { 5.0, 5.0, 8.0, 1.0};
    GLfloat light1_specular[] = { 0.3, 0.3, 0.3, 1.0 };

    // material values
    GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

	// light 0 initialize
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);


	// light 1 initialize
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	// material initialize
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0); // ambient lighting 
    light0On = 1;
    glEnable(GL_LIGHT1); // diffuse lighting
    light1On = 1;
    glEnable(GL_COLOR_MATERIAL); //
    glEnable(GL_DEPTH_TEST);
    
    
}

/*
Function draws each chess piece in its appropriate square on the board. Handles the rotation of each piece 
when user triggers key r/R. Decides which color each piece is depending on board coordinates.
Takes in no arguments and returns no arguments.
*/
void drawChessPiece()
{
	glEnable(GL_NORMALIZE);
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			if(j < 2 || j > 5) // either the bottom two rows or top two rows
			{
				
				if((j == 0 || j == 7) && (i == 0 || i == 7)) // white rook or black rook
				{
					if(j == 0)
					{
						glColor3f(0.55, 0.55, 0.53); // light colored pieces should have a RGB color of RGB (140, 140, 135).
					}
					else if(j == 7)
					{
						glColor3f(0.59, 0.29, 0.0); // dark colored pieces should have a RGB color of RGB (150, 75, 0)

					}
				    glPushMatrix();
			        glTranslatef(4.0, 4.0, 0.0);
				    glRotatef(angle, 0.0, 0.0, 1.0);
				    glTranslatef(-4.0, -4.0, 0.0);
				    glTranslatef(i+0.5, j+0.5, 0.51);
			        glScalef(0.75, 0.75, 1.0);
			        glutSolidCube(1.0);
				    glPopMatrix();

				}
				else if((j == 0 || j == 7) && (i == 1 || i == 6)) // white or black knight
				{
					if(j == 0)
					{
						glColor3f(0.55, 0.55, 0.53); // light colored pieces should have a RGB color of RGB (140, 140, 135).
					}
					else if(j == 7)
					{
						glColor3f(0.59, 0.29, 0.0); // dark colored pieces should have a RGB color of RGB (150, 75, 0)

					}
				    glPushMatrix();
				    glTranslatef(4.0, 4.0, 0.0);
				    glRotatef(angle, 0.0, 0.0, 1.0);
				    glTranslatef(-4.0, -4.0, 0.0);
			        glTranslatef(i+0.5, j+0.5, 0.29);
			        //glFrontFace(GL_CCW);
			        glScalef(1.0, 1.0, 1.0);
			        glRotatef(90.0, 1.0, 0.0, 0.0);
			        glutSolidTeapot((0.75/2));
				    glPopMatrix();

				}
				else if((j == 0 || j == 7) && (i == 2 || i == 5)) // white or black bishop
				{
					if(j == 0)
					{
						glColor3f(0.55, 0.55, 0.53); // light colored pieces should have a RGB color of RGB (140, 140, 135).
					}
					else if(j == 7)
					{
						glColor3f(0.59, 0.29, 0.0); // dark colored pieces should have a RGB color of RGB (150, 75, 0)

					}
				    glPushMatrix();
				    glTranslatef(4.0, 4.0, 0.0);
				    glRotatef(angle, 0.0, 0.0, 1.0);
				    glTranslatef(-4.0, -4.0, 0.0);
			        glTranslatef(i+0.5, j+0.5, 0.0);
			        glScalef(0.75, 0.75, 1.0);
			        glutSolidCone(0.45, 1.0, 10, 2);
				    glPopMatrix();

				}
				else if((j == 0 || j == 7) && (i == 3)) // white or black queen
				{
					glEnable(GL_NORMALIZE); // prevents over brightened queen
					if(j == 0)
					{
						glColor3f(0.55, 0.55, 0.53); // light colored pieces should have a RGB color of RGB (140, 140, 135).
					}
					else if(j == 7)
					{
						glColor3f(0.59, 0.29, 0.0); // dark colored pieces should have a RGB color of RGB (150, 75, 0)

					}
				    glPushMatrix();
				    glTranslatef(4.0, 4.0, 0.0);
				    glRotatef(angle, 0.0, 0.0, 1.0);
				    glTranslatef(-4.0, -4.0, 0.0);
			        glTranslatef(i+0.5, j+0.5, 0.30);
			        glScalef(0.50, 0.50, 0.50);
			        glutSolidTetrahedron();
				    glPopMatrix();

				}
				else if((j == 0 || j == 7) && (i == 4)) // white or black king
				{
					glEnable(GL_NORMALIZE); // prevents over brightened king
					if(j == 0)
					{
						glColor3f(0.55, 0.55, 0.53); // light colored pieces should have a RGB color of RGB (140, 140, 135).
					}
					else if(j == 7)
					{
						glColor3f(0.59, 0.29, 0.0); // dark colored pieces should have a RGB color of RGB (150, 75, 0)

					}
				    glPushMatrix();
				    glTranslatef(4.0, 4.0, 0.0);
				    glRotatef(angle, 0.0, 0.0, 1.0);
				    glTranslatef(-4.0, -4.0, 0.0);
			        glTranslatef(i+0.5, j+0.5, 0.50);
			        glScalef((0.3), (0.3), 0.5);
			        glutSolidOctahedron();
				    glPopMatrix();

				}
				else if(j == 1 || j == 6) // white or black pawn
				{
					if(j == 1)
					{
						glColor3f(0.55, 0.55, 0.53); // light colored pieces should have a RGB color of RGB (140, 140, 135).
					}
					else if(j == 6)
					{
						glColor3f(0.59, 0.29, 0.0); // dark colored pieces should have a RGB color of RGB (150, 75, 0)

					}
				    glPushMatrix();
				    glTranslatef(4.0, 4.0, 0.0);
				    glRotatef(angle, 0.0, 0.0, 1.0);
				    glTranslatef(-4.0, -4.0, 0.0);
			        glTranslatef(i+0.5, j+0.5, (.75/2));
			        glScalef(1, 1, 1);
			        glutSolidSphere((0.75/2), 20, 20);
				    glPopMatrix();
				}
			}
		}
	}
}

/*
Function that renders scene and calls drawchesspiece function to update the pieces and their rotation, along
with the chessboards rotation. Draws the chess board first, then draws chess pieces. Takes in no arguments 
and returns nothing.
*/
void display(void)
{
	glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears buffer
 
    glEnable(GL_NORMALIZE);
    glLoadIdentity();
    gluLookAt(4.0, -5.0, zView, 4, 4, 0, 0.0, 0.0, 1.0); // points in correct z direction
    for(int i = 0; i < 8; ++i) // iterates over an 8x8 grid
    {
    	for(int j = 0; j < 8; ++j)
    	{
    		bool isBlack = (((i+j)%2) == 0); // checks if square should be black or white
    		if(isBlack) // black square
    		{
    			// rotates correctly in case of r/R triggered event
    			// and draws square 
    			glPushMatrix();
    			glColor3f(0, 0, 0);
    			glTranslatef(4.0, 4.0, 0.0);
			    glRotatef(angle, 0.0f, 0.0f, 1.0f);
			    glTranslatef(-4.0, -4.0, 0.0);
			    glBegin(GL_QUADS);
			    glVertex2f(i, j);
			    glVertex2f(i+1, j);
			    glVertex2f(i+1, j+1);
			    glVertex2f(i, j+1);
			    glEnd();
			    glPopMatrix();

    		}
    		else // white square
    		{
    			// rotates correctly in case of r/R triggered event
    			// and draws square 
    			glPushMatrix();
    			glColor3f(1, 1, 1);
				glTranslatef(4.0, 4.0, 0.0);
			    glRotatef(angle, 0.0f, 0.0f, 1.0f);
			    glTranslatef(-4.0, -4.0, 0.0);
			    glBegin(GL_QUADS);
			    glVertex2f(i, j);
			    glVertex2f(i+1, j);
			    glVertex2f(i+1, j+1);
			    glVertex2f(i, j+1);
			    glEnd();
			    glPopMatrix();
    		}
    	}
    }
    glPushMatrix();
    drawChessPiece(); // calls function to draw all pieces 
    glPopMatrix();
    glutSwapBuffers(); // makes it all visible
}

/*
Function that is called when window size has been set/changed to w by h pixels. Sets the camera
perspective to 60 degrees vertical field of view, a window aspect
ratio of w/h, a near clipping plane at depth 1, and a far clipping
plane at depth 30.0. The viewport is the entire window.

*/
void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0, -5.0, zView, 4, 4, 0, 0.0, 0.0, 1.0);
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

/*
Function that is for User-input callback
key 0: toggles light0 on or off
key 1: toggles light1 on or off
key r/R: rotates all objects by 10 degrees counter clockwise about center 4,4,0
key u/U: moves eye location up z axis by 0.25m
key d/D: moves eye location down z axis by 0.25m
*/
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case '0':
        if(light0On == 1) // light is already on, turn off
        {
        	light0On = 0;
        	glDisable(GL_LIGHT0);
        }
        else if(light0On == 0) // light off already, turn on
        {
        	light0On = 1;
        	glEnable(GL_LIGHT0);

        }
        glutPostRedisplay();
        break;
    case '1':
	    if(light1On == 1) // light is already on, turn off
	        {
	        	light1On = 0;
	        	glDisable(GL_LIGHT1);
	        }
	        else if(light1On == 0) // light off already, turn on
	        {
	        	light1On = 1;
	        	glEnable(GL_LIGHT1);

	        }
	    glutPostRedisplay();
        break;
    case 'r': // rotates about z axis everything, centered at 4,4,0
        angle +=10;
        glutPostRedisplay();
        break;
    case 'R': // rotates about z axis everything, centered at 4,4,0
    	angle +=10;
        glutPostRedisplay();
        break;
    case 'd': //moves the eye location down z –axis 0.25 m each time.
        zView -= 0.25;
        glutPostRedisplay();
        break;
    case 'D': //moves the eye location down z –axis 0.25 m each time.
        zView -= 0.25;
        glutPostRedisplay();
        break;
    case 'u': //moves the eye location up z-axis 0.25 m each time.
        zView += 0.25;
        glutPostRedisplay();
        break;
    case 'U': //moves the eye location up z-axis 0.25 m each time.
        zView += 0.25;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Calls all functions to render objects and constantly renders/updates
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Chess");
    // intializes lighting
    init();
    // register callbacks
    glutDisplayFunc(display); // (re)display callback
    glutReshapeFunc(reshape); // window reshape callback
    glutKeyboardFunc(keyboard); // process standard key clicks
    // enter GLUT event processing cycle
    glutMainLoop();
    return 0;
}
