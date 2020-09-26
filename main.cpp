
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <C:\GLUT\include\GL\glut.h>
#include <stdlib.h>

/* Variables */

static void display(void)
{
    glClearColor(1.0,1.0,0.0,1.0);//color de pantalla
    glClear(GL_COLOR_BUFFER_BIT);//limpia la pantalla
    glLineWidth(7);//define el grosor de linea
    glColor3f(0.0,0.0,1.0);//color azul fuerte (RGB) para los elementos dibujados dentro del glBegin()
    //GLBegin se utiliza para encapsular o escribir toda primitiva
    //GL_LINE_STRIP permite trazar series de segmentos conectados
    glBegin(GL_LINE_STRIP);
        //primer for dibuja las lineas verticales
        //controla y
        double j=1.0;
        //controla x
        for(double i=-0.1;i<=1.0;i=i+0.1){
                glVertex2d(i,j);// dibuja un vertice en la coordenada (x,y)
                glVertex2d(i,-j);
                glVertex2d(-i,-j);
                glVertex2d(-i,j);
        }
        //segundo for dibuja las lineas horizontales
        //controla x
        double i=1.0;
            //controla y
            for(double j=-1.0;j<=1.0;j=j+0.1){
                glVertex2d(-i,j);// dibuja un vertice en la coordenada (x,y)
                glVertex2d(-i,-j);
                glVertex2d(i,-j);
                glVertex2d(-i,-j);
                //glColor3f(1.0,1.0,0.0);
                //glVertex2d(i,-j);

            }

    glEnd();//cierra glBegin()
    glFlush();//refuerzo de pintado

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//recoger los parametros de la linea de comandos
    //le dice al motor grafico que hay que renderizar, refrescar
    //o no la pantalla, que buffer hay que activar o desactivar y
    //la modalidad de colores que queremos usar
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);//establece el tamaño de la pantalla donde se mostrará nuestro dibujo o animacion
    glutInitWindowPosition(50,50);//establecen las coordenadas del lugar de la pantalla donde se quiere que aparezca la ventana
    glutCreateWindow("Dibuja Cuadricula");//Titulo de la Ventana
    glutDisplayFunc(display);//manda llamar el metodo a ejecutar
    //Es entrar al bucle infinito que domina cualquier aplicacion
    glutMainLoop();

}
