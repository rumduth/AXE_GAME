
#include <cstdio>
#include "raylib.h"

bool check_collsion(int x_circle, int y_circle, int r, int x, int  y, int w, int h)
{
    if(x_circle + r < x || x_circle - r > x + w)
        return true;
    if(y_circle - r > y + h || y_circle + r < y)
        return true;
    return false;
}
int main()
{
    //Windown Size
    int width = 400;
    int height = 400;
    InitWindow(width,height,"Axe Game Thong Nguyen");

    SetTargetFPS(60);


    //For Circle
    int x_circle = 20;
    int y_circle = 20;
    int r = 20;
    int move_circle = 10;

    //For Rectangular
    int x = 250;
    int y = 0;
    int w = 40;
    int h = 40;
    int move_rectangular = 10;


    
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(IsKeyDown(KEY_R))
        {
            x_circle = 20;
            y_circle = 20;
            x = 250;
            y = 0;
            move_rectangular = 10;
        }


        if(!check_collsion(x_circle,y_circle,r,x,y,w,h))
        {
            DrawText("Game Over",x_circle,y_circle,20,RED);
        }
        else
        {

        DrawCircle(x_circle,y_circle,r,BLUE);
        DrawRectangle(x,y,w,h,RED);

    
        //Rectangular Moving
        y += move_rectangular;
        if(y == 0 || y == height - 20)
            move_rectangular = -move_rectangular;



        //Circle Moving
        if(IsKeyDown(KEY_DOWN) && y_circle < height - r)
        {
            y_circle += move_circle;
        }
        if(IsKeyDown(KEY_UP) && y_circle > r)
        {
            y_circle -= move_circle;
        }
        if(IsKeyDown(KEY_RIGHT) && x_circle < width - r)
        {
            x_circle += move_circle;
        }
        if(IsKeyDown(KEY_LEFT) && x_circle > r)
        {
            x_circle -= move_circle;
        }
        
      

        }

        EndDrawing();
    }

}