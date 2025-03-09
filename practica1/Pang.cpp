#include "freeglut.h"

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}
void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	gluLookAt(2, 2, 4,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	//aqui es donde hay que poner el código de dibujo
    // Corpo da casa (cubo)
    glColor3f(0.8f, 0.5f, 0.2f);
    glutSolidCube(1.0);

    // Telhado (pirâmide)
    glColor3f(0.6f, 0.2f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.6f, 0.5f, 0.6f);
    glVertex3f(0.6f, 0.5f, 0.6f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-0.6f, 0.5f, -0.6f);
    glVertex3f(0.6f, 0.5f, -0.6f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glVertex3f(-0.6f, 0.5f, -0.6f);
    glVertex3f(-0.6f, 0.5f, 0.6f);
    glVertex3f(0.0f, 1.0f, 0.0f);

    glVertex3f(0.6f, 0.5f, -0.6f);
    glVertex3f(0.6f, 0.5f, 0.6f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();

    // Porta
    glColor3f(0.3f, 0.2f, 0.1f);
    glPushMatrix();
    glTranslatef(0.0f, -0.25f, 0.51f);
    glScalef(0.3f, 0.5f, 0.1f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Árvore (tronco)
    glColor3f(0.5f, 0.3f, 0.1f);
    glPushMatrix();
    glTranslatef(1.2f, -0.25f, -1.0f);
    glScalef(0.2f, 1.0f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Copa da árvore (esfera)
    glColor3f(0.0f, 0.6f, 0.0f);
    glPushMatrix();
    glTranslatef(1.2f, 0.5f, -1.0f);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

}

void OnTimer(int value)
{
	
}

