#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>
#include <iostream>
#include "Redactor/Windows/Window/Window.h"
#include "Redactor/Windows/SimpleRenderWindow/SimpleRenderWindow.h"
#include "Redactor/Graphic/Vertex3D/Vertex3D.h"
#include "Redactor/Graphic/Drawers/Console/StandardVertex3DDrawer/StandardVertex3DDrawer.h"
#include "Redactor/Graphic/Drawers/OpenGL/StandardVertex3DDrawer/StandardVertex3DDrawer.h"
#include "Redactor/Graphic/LinkedLine3D/LinkedLine3D.h"
#include "Redactor/Graphic/Line3D/Line3D.h"
#include "Redactor/Graphic/Drawers/Console/StandardLine3DDrawer/StandardLine3DDrawer.h"
#include "Redactor/Graphic/Drawers/OpenGL/StandardLine3DDrawer/StandardLine3DDrawer.h"
#include "Redactor/Windows/SubclassesProc/DoubleEditSubclassProc/DoubleEditSubclassProc.h"
#include "Redactor/Windows/GW/GOW/Vertex3DWindow/Vertex3DWindow.h"
#include "Redactor/Windows/GW/GOW/Line3DWindow/Line3DWindow.h"
#include "Redactor/Windows/GW/GOW/LinkedLine3DWindow/LinkedLine3DWindow.h"

float theta = 0.0f;
bool is_up_moving = true;
void draw_triangle(void);
void draw_square(void);
void CreateVertexAndContextForTest(Redactor::Graphic::Vertex3D* vert, Redactor::Graphic::DrawContext::Vertex3DStandardContext* context);
void CreateLineDrawContextForTest(Redactor::Graphic::DrawContext::Line3DStandardContext* context);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    SetConsoleOutputCP(1251);
    MSG msg;
    BOOL bQuit = FALSE;

    Redactor::Graphic::Vertex3D vert;
    Redactor::Graphic::DrawContext::Vertex3DStandardContext vert_context;
    Redactor::Graphic::Drawers::Console::StandardVertex3DDrawer vert_console_drawer = Redactor::Graphic::Drawers::Console::StandardVertex3DDrawer();
    Redactor::Graphic::Drawers::OpenGL::StandardVertex3DDrawer vert_opengl_drawer = Redactor::Graphic::Drawers::OpenGL::StandardVertex3DDrawer();

    CreateVertexAndContextForTest(&vert, &vert_context);
    Redactor::Graphic::Vertex3D vert_next = vert;
    vert_next.SetX(-0.3);
    vert_next.SetY(-0.3);

    vert_console_drawer.Draw(vert, vert_context);
    vert_console_drawer.Draw(vert_next, vert_context);

    Redactor::Graphic::LinkedLine3D line = Redactor::Graphic::LinkedLine3D(nullptr, &vert_next);
    line.SetDeallocFlags(false, false);
    Redactor::Graphic::DrawContext::Line3DStandardContext line_context;
    Redactor::Graphic::Drawers::Console::StandardLine3DDrawer line_console_drawer;
    Redactor::Graphic::Drawers::OpenGL::StandardLine3DDrawer line_opengl_drawer;

    CreateLineDrawContextForTest(&line_context);
    line_console_drawer.Draw((Redactor::Graphic::Line3D)line, line_context);

    Redactor::Graphic::Line3D line_0 = Redactor::Graphic::Line3D(-1, 0, 0, 1, 0.5, 0);

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

    if(!Redactor::Windows::GW::GOW::RegisterVertex3DWindowClass())
    {
        DWORD error = GetLastError();
        printf("%dx%d\n", HIWORD(error), LOWORD(error));
        return -3;
    }

    if(!Redactor::Windows::GW::GOW::RegisterLine3DWindowClass())
    {
        DWORD error = GetLastError();
        printf("%dx%d\n", HIWORD(error), LOWORD(error));
        return -4;
    }

    if(!Redactor::Windows::GW::GOW::RegisterLinkedLine3DWindowClass())
    {
        DWORD error = GetLastError();
        printf("%dx%d\n", HIWORD(error), LOWORD(error));
        return -5;
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

    Redactor::Windows::GW::GOW::Vertex3DWindow vertEdit = Redactor::Windows::GW::GOW::Vertex3DWindow();
    vertEdit.SetObjectPtr(&vert);

    Redactor::Windows::GW::GOW::LinkedLine3DWindow lineEdit = Redactor::Windows::GW::GOW::LinkedLine3DWindow();
    lineEdit.SetObjectPtr(&line);
    if(!window.Create())
        return -10;
    if(!render.Create())
        return -11;
    if(!render_s.Create())
        return -12;
    if(!vertEdit.Create())
        return -13;
    if(!lineEdit.Create())
        return -14;

    window.Show(nCmdShow);
    render.Show(nCmdShow);
    render_s.Show(nCmdShow);
    vertEdit.Show(nCmdShow);
    lineEdit.Show(nCmdShow);

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
            line.SetEndY(theta);

           /* OpenGL animation code goes here */
            //render.DrawByFunc(draw_triangle);
            render.SetCurrent();
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            line_opengl_drawer.Draw(line, line_context);
            vert_opengl_drawer.Draw(vert, vert_context);
            vert_opengl_drawer.Draw(vert_next, vert_context);
            line_opengl_drawer.Draw(line_0, line_context);
            render.SwapBuffer();
            render_s.DrawByFunc(draw_square);


            if(is_up_moving)
                theta += 0.02;
            else
                theta -= 0.02;
            if(theta > 1)
            {
                theta = 1;
                is_up_moving = false;
            }
            else if(theta < -1)
            {
                theta = -1;
                is_up_moving = true;
            }
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

void CreateVertexAndContextForTest(Redactor::Graphic::Vertex3D* vert, Redactor::Graphic::DrawContext::Vertex3DStandardContext* context)
{
    if(vert == nullptr || context == nullptr)
        return;
    vert->SetX(0.5);
    vert->SetY(0.6);
    vert->SetZ(0.0);

    Redactor::Graphic::Colors::Color4B col = Redactor::Graphic::Colors::Color4B(245, 25, 10, 255);
    Redactor::Graphic::UVs::UV2D uv = Redactor::Graphic::UVs::UV2D(0.5, 0.1);
    bool visibility = true;
    context->SetColor(col);
    context->SetTextureCoords(uv);
    context->SetVisibility(visibility);
    context->SetSize(5);
}

void CreateLineDrawContextForTest(Redactor::Graphic::DrawContext::Line3DStandardContext* context)
{
    if(context == nullptr)
        return;
    context->SetStartColor(255, 0, 0);
    context->SetEndColor(0, 0, 255);
    context->SetStripFactor(2);
    context->SetStripPattern(0b0010011100100111);
    context->SetStripMode(true);
    context->SetWidth(3);
}
