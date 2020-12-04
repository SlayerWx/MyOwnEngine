#include <iostream>
#include <GLFW/glfw3.h>
#include "graphics/window.h"
using namespace std;
using namespace MyOwnEngine;
using namespace graphics;
int main()
{
	Window engine("Maxi Ruffo ~ Engine", 800, 600);
	while (!engine.Closed())
	{
		engine.Update();
	}
	system("PAUSE");
	return 0;
}