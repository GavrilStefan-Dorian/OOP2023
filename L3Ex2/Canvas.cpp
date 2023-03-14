#include "Canvas.h"
#include <stdio.h>
#include <math.h>
Canvas::Canvas(int wd, int ht) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            CANVAS[i][j] = ' ';
    width = wd;
    height = ht;
    
};

void Canvas::DrawCircle(int x, int y, int ray, char ch) {

    static const double PI = 3.1415926535;
    double i, angle, x1, y1;

    for (i = 0; i < 90; i += 0.1)
    {
        angle = i;
        x1 = ray * cos(angle * PI / 180);
        y1 = ray * sin(angle * PI / 180);
        CANVAS[x + (int)x1][y + (int)y1]= ch;
        CANVAS[x - (int)x1][y + (int)y1] = ch;
        CANVAS[x + (int)x1][y - (int)y1] = ch;
        CANVAS[x - (int)x1][y - (int)y1] = ch;

    }
};

    void Canvas::FillCircle(int x, int y, int ray, char ch) {

        static const double PI = 3.1415926535;
        double i, angle, x1, y1;

        for (i = 0; i < 90; i += 0.1)
        {
            angle = i;
            x1 = ray * cos(angle * PI / 180);
            y1 = ray * sin(angle * PI / 180);
            DrawLine(x - (int)x1,y + (int)y1,x+(int)x1,y+(int)y1, ch);
            DrawLine(x - (int)x1, y - (int)y1, x + (int)x1, y - (int)y1, ch);

        }
    };

    void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
        int i, j;
        for (j = left,i = top; i <= bottom;i++)
            this->CANVAS[i][j] = ch;
        for (j = left, i = top; j <= right; j++)
            this->CANVAS[i][j] = ch;
        for (j = right, i = bottom; i >= top; i--)
            this->CANVAS[i][j] = ch;
        for (j = right, i = bottom; j >= left; j--)
            this->CANVAS[i][j] = ch;
    };

    void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
    {
        int i, j;
        for (i = top; i <= bottom; i++)
            for (j = left; j <= right; j++)
                this->CANVAS[i][j] = ch;
    };

    void Canvas::SetPoint(int x, int y, char ch) {
        this->CANVAS[x][y] = ch;
    };

    void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    
        int dx, dy ,p, x, y;
        dx = x2 - x1;
        dy = y2 - y1;
        x = x1;
        y = y1;
        p = 2 * dy - dx;
        while (x < x2) {
            if (p >= 0)
            {
                CANVAS[x][y] = ch;
                y++;
                p = p + 2 * dy - 2 * dx;
            }
            else
            {
                CANVAS[x][y] = ch;
                p = p + 2 * dy;
            }
            x++;
        }
        
    };

    void Canvas::Print() {
        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
                printf("%c", CANVAS[i][j]);
        printf("\n");
        }
    }; // shows what was printed

    void Canvas::Clear() { // clears the canvas
        for (int i = 0; i < this->height; i++)
            for (int j = 0; j < this->width; j++)
                CANVAS[i][j] = ' ';
    };
