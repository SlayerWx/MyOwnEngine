#include "graphics/window.h"
using namespace MyOwnEngine;
using namespace graphics;
int main()
{
	Window engine("Maxi Ruffo ~ Engine", 800, 600);
	GLuint vao;
	glGenVertexArrays(1,&vao);
	glBindVertexArray(vao);
	while (!engine.Closed())
	{
#if 0
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER,0,0);
		engine.Update();
	}
	return 0;
}