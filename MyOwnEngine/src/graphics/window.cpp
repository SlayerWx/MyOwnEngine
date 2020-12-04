#include "window.h"
namespace MyOwnEngine {	namespace graphics {
	Window::Window(const char * title, int width, int height)
	{
		_title = title;
		_width = width;
		_height = height;
		if (!Init())glfwTerminate();
	}
	Window::~Window()
	{
		glfwTerminate();
	}
	void Window::Update() const
	{
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
	bool Window::Closed() const
	{
		return glfwWindowShouldClose(_window);
	}
	bool Window::Init()
	{
		if (!glfwInit())
		{
			cout << "Failed to initialize GLFW!" << endl;
			return false;
		}
		_window = glfwCreateWindow(_width, _height, _title, NULL, NULL);
		if (!_window)
		{
			cout << "Failed to create GLFW window!" << endl;
			return false;
		}
		glfwMakeContextCurrent(_window);
		return true;
	}
}
}