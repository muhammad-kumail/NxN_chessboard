#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

void initGL() {
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void box(float x,float y,float x1,float y1){
	glBegin(GL_QUADS);
		glVertex2f(x, y);
		glVertex2f(x1, y);
		glVertex2f(x1, y1);
		glVertex2f(x, y1);
	glEnd();
}


void chessBoard(int n){
	glColor3f(1.0f,1.0f,1.0f);
	glBegin(GL_LINES);
	glVertex2f(-0.9,0.9);
	glVertex2f(0.9,0.9);
	
	glVertex2f(0.9,0.9);
	glVertex2f(0.9,-0.9);
	
	glVertex2f(0.9,-0.9);
	glVertex2f(-0.9,-0.9);
	
	glVertex2f(-0.9,-0.9);
	glVertex2f(-0.9,0.9);
	glEnd();
	
	float rows=0.9/(n/2.0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				if(j%2==0&&i%2==1){
					glColor3f(1.0f,1.0f,1.0f);
					box(-0.9+((j-1)*rows),0.9-((i-1)*rows),-0.9+(j*rows),0.9-(i*rows));
				}
				else if(j%2==1&&i%2==0){
					
					glColor3f(1.0f,1.0f,1.0f);
					box(-0.9+((j-1)*rows),0.9-((i-1)*rows),-0.9+(j*rows),0.9-(i*rows));
				}
		}
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	chessBoard(16); //It's your choice you can choose hard coded value or value input from user
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Chessboard using GL_QUADS");  // Create window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutInitWindowPosition(50, 50); 
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();	
	return 0;
}
