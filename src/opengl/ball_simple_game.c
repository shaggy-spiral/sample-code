#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>

// Dimensões por defeito da janela
int winWidth  = 800;
int winHeight = 600;

// Variáveis gerais
int board[10][10];
//float posStart[] = {-1.5, 1.4, -5.0};	// Posição de inicio do desenho
const float posIncStep = 0.32f;	// Incremento para posicionar as bolas
float posBX = -1.5;
float posBY = 1.4;
float posBZ = -5.0;
int selectionBar = 0;
float glow = 0.7;	// Variável de efeito de brilho
int glowState = 0;
float rotX = 0.0; // Variável de rotação
int rotUP = 0; // Variável de rotação do cubo
float ballScale = 1.0;
int ballScaleStat = 0;
int switchLeft = 0;
int switchRight = 0;
float ballTrans = 0.0f;
// Variáveis da manipulação gráfica
GLfloat ambLight0[] = {0.0, 0.0, 0.0, 1.0};	// Luz ambiente da cena
GLfloat sDefColor[] = {1.0, 1.0, 1.0, 1.0}; // Cor da reflexão do material
GLfloat difLight0[] = {0.4, 0.5, 0.8, 1.0};
GLfloat difLightPos[] = {0.0, 0.0, 2.0};
//
//	Função que evita colocar bolas iguais consecutivamente	////////////
//
int CheckBalls(int a, int b)
{
	if(a == b)
		return 1;
	else
		return 0;
}
//
//	Função que inicializa o quadro de jogo	////////////////////////////
//
void InitBoard()
{
	int l = 0;
	int c = 0;
	for (l = 0; l <= 9; l++)
	{
		for (c = 0; c <= 9; c++)
		{
			if (l >= 2)
			{
				while(CheckBalls(board[l][c], board[l - 1][c] == 1))
					board[l][c] = (int)(rand() % 5);
			}
			board[l][c] = (int)(rand() % 5);
			printf("%d - ", board[l][c]);
		}
		printf("\n");
	}
	printf("\n");
}
//
//	Função Display()	////////////////////////////////////////////////
//
void Display()
{
	// Variáveis
	int l = 0;
	int c = 0;
	int color = 0;
	// Cor de fundo
	float const bgColor = 160.0 / 255.0;
	// Iniciação básica
	glClearColor(bgColor, bgColor, bgColor, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH);
	// Configuração da iluminação
	glEnable(GL_LIGHTING);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambLight0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambLight0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, difLight0);
	glLightfv(GL_LIGHT1, GL_POSITION, difLightPos); 
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, sDefColor);
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	// Desenho dos objectos
	for(l = 0; l <= 9; l++)
	{
		for(c = 0; c <= 9; c++)
		{
			color = board[l][c];
			glLoadIdentity();
			glTranslatef(posBX + (c * posIncStep), posBY - (l * posIncStep), posBZ);
			if(selectionBar == l)
			{
				glScalef(1.0 * ballScale, 1.0 * ballScale, 1.0 * ballScale);
			}
			switch(color)
			{
				case 1:
					glColor3f(1.0 * glow, 0.4, 0.4);
					break;
				case 2:
					glColor3f(0.4, 1.0 * glow, 0.4);
					break;
				case 3:
					glColor3f(0.4, 0.4, 1.0 * glow);
					break;
				case 4:
					glColor3f(1.0 * glow, 0.4, 1.0 * glow);
					break;
				default:
					glColor3f(1.0 * glow, 1.0 * glow, 0.4);
					break;
			}
			if(switchLeft == 1 && l == selectionBar)
			{
				glTranslatef(-ballTrans, 0.0, 0.0);
				glRotatef(10.0, 0.0, 0.0, 1.0);
			}
			if(switchRight == 1 && l == selectionBar)
			{
				glTranslatef(ballTrans, 0.0, 0.0);
				glRotatef(5.0, 0.0, 0.0, 1.0);
			}
			glutSolidSphere(0.1, 32, 32);
			
		}
		glLoadIdentity();		
		glutSolidSphere(0.1, 8, 8);
	}
	// Paralelepípedo de selecção
	glLoadIdentity();
	glTranslatef(-0.05, 1.4 - (selectionBar * posIncStep), posBZ);
	glScalef(32.0, 2.0 * ballScale, 1.0);
	if(rotUP == 1)
		glRotatef(-rotX, 1.0, 0.0, 0.0);
	else
		glRotatef(rotX, 1.0, 0.0, 0.0);
	glColor3f(1.0 * glow, 1.0 * glow, 0.0);
	glutWireCube(0.1);
	//Cor de fundo e buffer
	glClearColor(0.1, 0.1, 0.1, 1.0);
	glFlush();
	glutSwapBuffers();
}
//
//	Função Timer()	////////////////////////////////////////////////////
//
void Timer(int value)
{
	rotX += 3.0;
	if(glowState == 0 && glow < 1.0)
		glow += 0.005;
	else
		glowState = 1;
	if(glowState == 1 && glow > 0.7)
		glow -= 0.005;
	else
		glowState = 0;
	
	if(ballScale < 1.2 && ballScaleStat == 1)
		ballScale += 0.02;
	else
		ballScaleStat = 0;
	if(ballScale > 0.9 && ballScaleStat == 0)
		ballScale -= 0.02;
	else
		ballScaleStat = 1;
		
	if(switchLeft == 1)
	{
		ballTrans += 0.016;
	}
	if(switchRight == 1)
	{
		ballTrans += 0.016;
	}
	if(ballTrans >= posIncStep)
	{
		switchLeft = 0;
		switchRight = 0;
	}
	glutPostRedisplay();
	glutTimerFunc(16, Timer, value);
}
//
//	Função Reshape() ///////////////////////////////////////////////////
//
void Reshape(int x, int y)
{
	if(x == 0 || y == 0)
		return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
}
//
//	Função Keyboard() //////////////////////////////////////////////////
//
void Keyboard(unsigned char key, int x, int y)
{
	if(key == 27)
		system(EXIT_SUCCESS);
}
//
//	Função Special Keys() //////////////////////////////////////////////
//
void SpcKeys(int key, int x, int y)
{
	int i;
	int aux;
	if(key == GLUT_KEY_UP)
	{
		if(selectionBar > 0)
		{
			selectionBar -= 1;
			rotUP = 1;
		}
		else
			selectionBar = 0;
	}
	if(key == GLUT_KEY_DOWN)
	{
		if(selectionBar < 9)
		{
			selectionBar += 1;
			rotUP = 0;
		}
		else
			selectionBar = 9;
	}
	if(key == GLUT_KEY_LEFT)
	{
		aux = board[selectionBar][0];
		for(i = 0; i < 9; i++)
		{
			board[selectionBar][i] = board[selectionBar][i + 1];
		}
		board[selectionBar][9] = aux;
		ballTrans = 0.0;
		switchLeft = 1;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		aux = board[selectionBar][9];
		for(i = 9; i > 0; i--)
		{
			board[selectionBar][i] = board[selectionBar][i - 1];
		}
		board[selectionBar][0] = aux;
		ballTrans = 0.0;
		switchRight = 1;
	}
}
//
// Função Main() ///////////////////////////////////////////////////////
// 
int main(int argc, char **argv)
{
	InitBoard();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("CRUSH MY BALLS!!!!1");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpcKeys);
	glutTimerFunc(16, Timer, 1);
	glutMainLoop();
	return 0;
}
