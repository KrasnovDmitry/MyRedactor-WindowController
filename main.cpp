#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>
#include "Redactor/Windows/Window/Window.h"
#include "Redactor/Windows/SimpleRenderWindow/SimpleRenderWindow.h"

float theta = 0.0f;

void draw_triangle(void);
void draw_square(void);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    MSG msg;
    BOOL bQuit = FALSE;

    if(!Redactor::Windows::RegisterSimpleWindowClass())
    {
        DWORD error = GetLastError();
        printf("%dx%d\n", HIWORD(error), LOWORD(error));
        return -1;
    }

    if(!Redactor::Windows::RegisterSimpleRenderWindowClass())
    {
        DWORD error = GetLastError();
        printf("%dx%d\n", HIWORD(error), LOWORD(error));
        return -2;
    }

    Redactor::Windows::Window window = Redactor::Windows::Window("My Window",
                                                                 WS_OVERLAPPEDWINDOW,
                                                                 CW_USEDEFAULT,
                                                                 CW_USEDEFAULT,
                                                                 600,
                                                                 500);

    Redactor::Windows::SimpleRenderWindow render = Redactor::Windows::SimpleRenderWindow("SimpleRender",
                                                                                         WS_CHILD | WS_VISIBLE,
                                                                                         20,
                                                                                         20,
                                                                                         300,
                                                                                         300,
                                                                                         &window);

    Redactor::Windows::SimpleRenderWindow render_s = Redactor::Windows::SimpleRenderWindow("SimpleRenderS",
                                                                                         WS_CHILD | WS_VISIBLE,
                                                                                         400,
                                                                                         200,
                                                                                         100,
                                                                                         100,
                                                                                         &window);

    if(!window.Create())
        return -3;
    if(!render.Create())
        return -4;
    if(!render_s.Create())
        return -4;
    window.Show(nCmdShow);
    render.Show(nCmdShow);
    render_s.Show(nCmdShow);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {

           /* OpenGL animation code goes here */
            render.DrawByFunc(draw_triangle);
            render_s.DrawByFunc(draw_square);

            theta += 1.0f;
            Sleep (1);
        }
    }

    render.Destroy();

    return msg.wParam;
}

void draw_triangle(void)
{
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);

        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

    glEnd();

    glPopMatrix();
}

void draw_square(void)
{
    glPushMatrix();
    glRotatef(-theta, 0.0f, 0.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(0.7f,   0.7f);
        glVertex2f(0.7f,  -0.7f);
        glVertex2f(-0.7f, -0.7f);
        glVertex2f(-0.7f, 0.7f);

    glEnd();

    glPopMatrix();
}
