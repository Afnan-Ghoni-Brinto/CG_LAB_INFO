
//    #include <GL/glut.h>
//    Includes the GLUT library for OpenGL.
//    GL      → OpenGL
//    glut.h  → GLUT header file
//    GLUT (OpenGL Utility Toolkit) is used to:
//    - Create windows
//    - Handle keyboard and mouse input
//    - Control the display loop
//    Without GLUT, window creation and event handling are not possible.

#include <GL/glut.h>
void display()
{
     //This is a callback function.
     // OpenGL automatically calls this function when:
     //- The window needs to be drawn
     //- The screen refreshes or updates

    glClear(GL_COLOR_BUFFER_BIT);   // Clears the screen. Removes old drawings. GL_COLOR_BUFFER_BIT → means clear colour buffer.Think of it like: Erase the board before drawing again.

    glPointSize(10.0f);             // Sets point size to 10 pixels. Default size is very small (1 pixel). So this makes it visible.
    glPointSize(10.0f);             // Sets point size to 10 pixels. Default size is very small (1 pixel). So this makes it visible.

    glBegin(GL_LINES);             // Start drawing a primitive. GL_POINTS means we are drawing points. OpenGL works like: Start → Define → End
    glColor3f(1.0f, 0.0f, 0.0f);//yellow glColor3f() sets RGB colour using 3 float values (0.0–1.0): 1.0 = full intensity, 0.0 = none → (1,0,0)=Red, (0,1,0)=Green, (0,0,1)=Blue
    glVertex2f(0.50f, 0.00f);   // glVertex2f() defines a 2D coordinate using 2 float values (x,y); (0,0) is the centre, so it draws the red point at the centre.

    glColor3f(0.0f, 1.0f, 0.0f);//Red
    glVertex2f(0.0f,0.0f);

   // glColor3f(1.0f,0.0f,1.0f);//purple
  // glVertex2f(0.30f,0.30f);

   // glColor3f(0.0f,0.0f,1.0f);//blue
  // glVertex2f(0.30f,-0.30f);

   // glColor3f(0.0f,0.0f,1.0f);//Blue
  // glVertex2f(0.30f,0.0f);

    //glColor3f(0.0f,1.0f,0.0f);//Red2
   //glVertex2f(0.25f,0.0f);


    glEnd();         // // glEnd() ends the drawing block and must always be used after glBegin().
    glFlush();   // Render now. it means  glEnd() ends the drawing block and must always be used after glBegin().
}
// Initialization
void init()  //This runs once before drawing starts.
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Background colour = white. glClearColor() sets background colour using RGBA (Red, Green, Blue, Alpha); (1,1,1,1) gives a white background.
     // Alpha = 1.0 → Fully opaque (not transparent) Alpha = 0.0 → Fully transparent Between 0.0 and 1.0 → Semi-transparent
    glMatrixMode(GL_PROJECTION);  // glMatrixMode(GL_PROJECTION) switches to the projection matrix, which controls the camera view and coordinate system.
    glLoadIdentity(); //Reset everything before applying new settings
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);   // gluOrtho2D(left, right, bottom, top) Coordinate system or  gluOrtho2D(-1,1,-1,1) sets 2D coordinates: X and Y range from -1 to 1 → (0,0)=centre, (-1,-1)=bottom-left, (1,1)=top-right.
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv); //Initialises GLUT.

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //GLUT_SINGLE → Single buffer GLUT_RGB → Use RGB colour mode

    glutInitWindowSize(500,300); // Window size = 500 × 500 pixels.

    glutInitWindowPosition(100,100); //Window appears at position (100,100) on screen.

    glutCreateWindow("Point testing - OpenGL"); // Creates window with title.

    init();

    glutDisplayFunc(display); //Whenever window needs drawing, call display()//

    glutMainLoop(); // glutMainLoop() starts the infinite loop, keeps the window open, the program running, and continuously checks events; without it, the window closes immediately.
    return 0;
}
