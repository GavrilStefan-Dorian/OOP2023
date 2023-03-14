#include "Canvas.h"
using namespace std;
int main() {
	
	Canvas myCanvas(100, 100);
	myCanvas.DrawRect(3, 3, 10, 10, 'A');
	myCanvas.FillRect(20, 4, 40, 8, 'H');
	myCanvas.SetPoint(29, 29, '9');
	myCanvas.DrawCircle(30, 60, 10, 'G');
	myCanvas.FillCircle(50, 20,20, 'o');
	myCanvas.DrawLine(20, 30, 70, 80, 'J');
	myCanvas.Print();
	
	return 0;
}