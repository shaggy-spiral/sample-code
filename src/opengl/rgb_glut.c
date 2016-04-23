//*  Tiago Sobral 
//******************************************************************************/
//	Bibliotecas a incluir //////////////////////////////////////////////////////
//
#include <stdlib.h>
#include <stdio.h>

//
//  Includes	///////////////////////////////////////////////////////////
// linux
#include <GL/freeglut.h>
#include <GL/gl.h>

// Em Windows:
// #include <glut.h>

//
//	Inicialização //////////////////////////////////////////////////////////////
//
GLsizei largura = 800, altura = 600;	        // Dimensões iniciais da janela
float red =  0.0f;							
float green = 0.0f;
float blue = 0.0f;
int selection;								// Seleccionar cor para alterar (triangulos junto as figuras)
int graphStyle = 0;							// Estilo de gráfico: barras(0) e triangulo(1)
//
//	Funções ////////////////////////////////////////////////////////////////////
//
//	FUNCÃO DE INICIALIZAÇÃO
//
void init ( void )
{
	glClearColor ( red , green , blue , 0.0 );   // Cor de fundo da janela = branco
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

//
//  FUNÇÃO DISPLAY 
//
void display( void )
{
	glClear( GL_COLOR_BUFFER_BIT );	 
	//
	// INICIA GRÁFICO DE BARRAS
	//	
	if( graphStyle == 0)
	{		
	glClearColor(red,green,blue, 0.0f);   // preenchimento da cor total (rgb)
	// 1ª COLUNA - COR DE FUNDO "PRETO"
	glColor3f( 0.0, 0.0, 0.0 );
	glBegin(GL_POLYGON);	                
		glVertex2f( 50.0, 100.0 );
		glVertex2f( 250.0, 100.0 );
		glVertex2f( 250.0, 500.0 );
		glVertex2f( 50.0, 500.0 );
	glEnd();
   // 2ª COLUNA - COR DE FUNDO "PRETO"
   glColor3f( 0.0, 0.0, 0.0 );
    glBegin(GL_POLYGON);
		glVertex2f( 300.0, 100.0);
		glVertex2f( 500.0, 100.0);
		glVertex2f( 500.0, 500.00);
		glVertex2f( 300.0, 500.00);
	glEnd();
	// 3ª COLUNA - COR DE FUNDO "PRETO"
	glColor3f( 0.0, 0.0, 0.0 );
	glBegin(GL_POLYGON);
		glVertex2f( 550.0, 100.0 );
		glVertex2f( 750.0, 100.0 );
		glVertex2f( 750.0, 500.0 );
		glVertex2f( 550.0, 500.0 );
	glEnd();
	
	// 1ª COLUNA - PREENCHIMENTO A VERMELHO	
	glColor3f( red, 0.0, 0.0 );
	glBegin(GL_POLYGON);	                
		glVertex2f( 50.0, 100.0 );
		glVertex2f( 250.0, 100.0 );
		glVertex2f( 250.0, 100 + red * 400.0 );
		glVertex2f( 50.0, 100 + red * 400.0 );
	glEnd();

	// 2º COLUNA - PREENCHIMENTO A VERDE
    glColor3f( 0.0, green, 0.0 );
    glBegin(GL_POLYGON);
		glVertex2f( 300.0, 100.0);
		glVertex2f( 500.0, 100.0);
		glVertex2f( 500.0, 100 + green * 400.00);
		glVertex2f( 300.0, 100 + green * 400.00);
	glEnd();
	
	// 3ª COLUNA - PREENCHIMENTO A AZUL
	glColor3f( 0.0, 0.0, blue );
	glBegin(GL_POLYGON);
		glVertex2f( 550.0, 100.0 );
		glVertex2f( 750.0, 100.0 );
		glVertex2f( 750.0, 100 + blue * 400.0 );
		glVertex2f( 550.0, 100 + blue * 400.0 );
	glEnd();
	
	// DESENHA LINHAS À VOLTA DOS RECTÂNGULOS
	// CORES INVERSAS À DE FUNDO
	glColor3f( 1.0f - red, 1.0f - green, 1.0f - blue );
	glLineWidth(10.0);
	// 1ª COLUNA - REBORDO
	glBegin( GL_LINE_LOOP );
		glVertex2f( 50.0, 100.0 );
		glVertex2f( 250.0, 100.0 );
		glVertex2f( 250.0, 500.0 );
		glVertex2f( 50.0, 500.0 );
	glEnd();
	// 2ª COLUNA - REBORDO
	glBegin(GL_LINE_LOOP);
		glVertex2f( 300.0, 100.0);
		glVertex2f( 500.0, 100.0);
		glVertex2f( 500.0, 500.00);
		glVertex2f( 300.0, 500.00);
	glEnd();
	// 3ª COLUNA - REBORDO
	glBegin(GL_LINE_LOOP);
		glVertex2f( 550.0, 100.0 );
		glVertex2f( 750.0, 100.0 );
		glVertex2f( 750.0, 500.0 );
		glVertex2f( 550.0, 500.0 );
	glEnd();
	 
	// MUDA SELECTOR (TRIANGULO EM CIMA DAS BARRAS) 
	switch ( selection ) 
	{
		case 0:
			glBegin( GL_TRIANGLES );
				glColor3f( 1.0, 0.0, 0.0 );
				glVertex2f( 150.0, 525.0 );
				glColor3f( 0.4, 0.0, 0.0 );
				glVertex2f( 175.0, 575.0 );
				glColor3f( 0.4, 0.0, 0.0 );
				glVertex2f( 125.0, 575.0 );
			glEnd();
			break;
		case 1:	
			glBegin( GL_TRIANGLES );
				glColor3f( 0.0, 1.0, 0.0 );
				glVertex2f( 400.0, 525.0 );
				glColor3f( 0.0, 0.4, 0.0 );
				glVertex2f( 425.0, 575.0 );
				glColor3f( 0.0, 0.4, 0.0 );
				glVertex2f( 375.0, 575.0 );
			glEnd();
			break;
		case 2:
			glBegin( GL_TRIANGLES );
				glColor3f( 0.0, 0.0, 1.0 );
				glVertex2f( 650.0, 525.0 );
				glColor3f( 0.0, 0.0, 0.4 );
				glVertex2f( 675.0, 575.0 );
				glColor3f( 0.0, 0.0, 0.4 );
				glVertex2f( 625.0, 575.0 );
			glEnd();
			break;
		}
	}
	// DESENHA GRÁFICO COM O TRIANGULO
	else
	{	
	    glClearColor(red,green,blue, 0.0f);
		// DESENHA TRIANGULO 
		glBegin( GL_TRIANGLES );
			glColor3f(red, 0.0, 0.0),	
			glVertex2f( 200.0, 100.0 );
			glColor3f( 0.0, green, 0.0 );
			glVertex2f( 600.0, 300.0 );
			glColor3f( 0.0, 0.0, blue );
			glVertex2f( 200.0, 500.0 );
		glEnd();
		// SELECCIONA VÉRTICE PARA ALTERAR A COR
		switch ( selection ) 
		{
		case 0:
			glBegin( GL_TRIANGLES );
				glColor3f( 1.0, 0.0, 0.0 );
				glVertex2f( 196.0, 92.0 );
				glColor3f( 0.4, 0.0, 0.0 );
				glVertex2f( 162, 66.0 );
				glColor3f( 0.4, 0.0, 0.0 );
				glVertex2f( 202.0, 52.0 );
			glEnd();
			break;
		case 1:	
			glBegin( GL_TRIANGLES );
				glColor3f( 0.0, 1.0, 0.0 );
				glVertex2f( 608.0, 300.0 );
				glColor3f( 0.0, 0.4, 0.0 );
				glVertex2f( 640.0, 325.0 );
				glColor3f( 0.0, 0.4, 0.0 );
				glVertex2f( 640.0, 275.0 );
			glEnd();
			break;
		case 2:
			glBegin( GL_TRIANGLES );
				glColor3f( 0.0, 0.0, 1.0 );
				glVertex2f( 196.0, 508.0 );
				glColor3f( 0.0, 0.0, 0.4 );
				glVertex2f( 162.0, 534.0 );
				glColor3f( 0.0, 0.0, 0.4 );
				glVertex2f( 202.0, 548.0 );
			glEnd();			
			break;		
		}
		// REBORDO DO TRIANGULO COM COM INVERTIDA
		glColor3f( 1.0f - red, 1.0f - green, 1.0f - blue );
		glLineWidth(2.0);
		glBegin( GL_LINE_LOOP );
			glVertex2f( 200.0, 100.0 );
			glVertex2f( 600.0, 300.0 );
			glVertex2f( 200.0, 500.0 );
		glEnd();
	  }		
	glFlush();
}

//
//	FUNÇÃO PARA REAJUSTAR A JANELA
//
void adaptacao (GLint nova_largura, GLint nova_altura)
{
	glViewport (0, 0, nova_largura, nova_altura);

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	//
	// Aumenta a imagem no interior da janela aquando da mudança de tamanho
	if (nova_largura <= nova_altura)
		gluOrtho2D (0.0, largura, 0.0, altura*nova_altura/nova_largura);
	else
		gluOrtho2D (0.0, largura*nova_altura/nova_altura, 0.0, altura);
	
	glMatrixMode (GL_MODELVIEW);	// Não alterar a projecção durante o desenho
	display ( );
	glFlush ( );
}

// 
//	FUNÇÃO CONTROLO DO RATO
//
void MouseClick( int state, int button, int x, int y) 
{
	// SELECCIONA E ALTERA COR DO GRÁFICO DE BARRAS
	if ( state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && graphStyle == 0)
	{
		if ( y > 100 && y < 600 ) 
		{
			if ( x < 250 && x > 50 )
			{	
				if (selection == 0)
					red += 0.1f;
				else	
				selection = 0;
			}
			if ( x < 500 && x > 300 )
			{
				if (selection == 1)
					green += 0.1f;
				else
				selection = 1;
			}
			if ( x < 750 && x > 550 )
			{
				if( selection == 2 )
				 blue += 0.1f;
				else
				selection = 2;
			}
		}
		
	}
	display();
}

// ESC SAI DO PROGRAMA
void getKey( unsigned char key, int x, int y ) 
{
	if ( key == 'Q' || key == 'q' || key == 27 )
		exit(0);
}

// 
//	FUNÇÃO PARA CONTROLO COM TECLAS ( SETAS )
//
void spsKeys( int key, int x, int y )
{
	switch(key) {
		// SETA PARA CIMA: INCREMENTA A COR
		case GLUT_KEY_UP:
			if ( selection == 0 )
				red += 0.1f;
				if( red > 1.0f )
					red = 1.0f;
			if ( selection == 1 )
				green += 0.1f;
				if( green > 1.0f )
					green = 1.0f;
			if ( selection == 2 )
				blue += 0.1f;
				if( blue > 1.0f)
					blue = 1.0f;
		break;
		// SETA PARA BAIXO: DIMINUI A COR
		case GLUT_KEY_DOWN:
			if ( selection == 0 )
				red -= 0.1f;
				if( red < 0.0f )
					red = 0.0f;
			if ( selection == 1 )
				green -= 0.1;
				if ( green < 0.0f )
					green = 0.0f;
			if ( selection == 2 )
				blue -= 0.1f;
				if ( blue < 0.0f )
					blue = 0.0f;
		break;
		// SETA PARA A ESQUERDA: SELECCIONA BARRA OU VÉRTICE
		case GLUT_KEY_LEFT:
				if ( selection == 0 )
					selection = 2;
				else
					selection -= 1;
		break;
		// SETA PARA A DIREITA: SELECCIONA BARRA OU VÉRTICE
		case GLUT_KEY_RIGHT:
				if ( selection == 2 )
					selection = 0;
				else 
					selection += 1;
		break;
		}	
	display();
} 

//
//	FUNÇÃO DE MENU DE BOTÃO DIREITO DO RATO
//
void mouseMenu( int item )
{
	int rgb_red, rgb_green, rgb_blue;
	switch( item ) 
	{
		// VALORES MÁXIMOS PARA A COR
		case 1:
			red = 1.0f;
			green = 1.0f;
			blue = 1.0f;
			break;
		// RESET AS CORES
		case 2:
			red = 0.0f;
			green = 0.0f;
			blue = 0.0f;
			break;
		// IMPRIME PARA A CONSOLA O CÓDIGO RGB DA COR ACTUAL
		case 3:
			rgb_red = (int)(red*255.0); 
			rgb_green = (int)(green*255.0);
			rgb_blue = (int)(blue * 255.0);
			printf(" RGB: (%d, %d, %d)\n", rgb_red, rgb_green, rgb_blue);
			break;
		// MUDA DE TIPO DE GRÁFICO
		case 4:
			if ( graphStyle == 1 )
				graphStyle = 0;
				else
					graphStyle += 1;
			break;
		// SAI DO PROGRAMA
		case 9:
			exit(0);
			break;
	}
	display();			
}
////////////////////////////////////////////////////////////////////////////////
//	Programa Principal /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main (int argc, char** argv)
{
	printf("***************************************************\n");
	printf("*  _____     _____     _____                      *\n");
	printf("* |  _  \\   |  ___|   |  _  \\       GRAPHS        *\n");
	printf("* | |_| /   | |  _    | |_| /         &           *\n");
	printf("* | | \\ \\   | |_| |   | |_| \\       COLORS        *\n");
	printf("* |_|  \\_\\  |_____|   |_____/                     *\n");
	printf("*                                                 *\n");
	printf("* 									              *\n");	
	printf("***************************************************\n");
	printf("* Teclas de setas selecciona e altera valores.    *\n");
	printf("* Rato selecciona e altera valores no gráfico de  *\n");
	printf("* barras.										  *\n");
	printf("***************************************************\n");
	glutInit(&argc, argv);	                               // Inicializar o GLUT

	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB );	      // Modo de visualização
  
	glutInitWindowSize (largura, altura); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("RGB graphs");
    
	init ( );

	glutDisplayFunc(display);
    glutKeyboardFunc( getKey );
    glutSpecialFunc( spsKeys );  
	glutReshapeFunc (adaptacao);
	glutMouseFunc( MouseClick );
	// CRIA MENU DO RATO
	glutCreateMenu( mouseMenu );   
	glutAddMenuEntry( "Valores Max", 1 );
	glutAddMenuEntry( "Valores Min", 2 );
	glutAddMenuEntry( "Imprime RGB", 3 );
	glutAddMenuEntry( "Mudar Grafico", 4);
	glutAddMenuEntry( "Sair", 9 );
	glutAttachMenu( GLUT_RIGHT_BUTTON );	
	
	glutMainLoop();	
    return EXIT_SUCCESS;
}
