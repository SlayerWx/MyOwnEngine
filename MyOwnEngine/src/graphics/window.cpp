#include "window.h"
namespace MyOwnEngine {	namespace graphics {
	Window::Window(const char * title, int width, int height)
	{
		_title = title;
		_width = width;
		_height = height;
		if (!Init())glfwTerminate();
		glClearColor(0.1f, 0.1f, 0.7f, 1.0f);
	}
	Window::~Window()
	{
		glfwTerminate();
	}
	void Window::Update()
	{
		glfwPollEvents();
		//glfwGetFramebufferSize(_window,&_width,&_height);
		glfwSwapBuffers(_window);
		Clear(); // for now
	}
	bool Window::Closed() const
	{
		return glfwWindowShouldClose(_window);
	}
	void Window::WindowResize(GLFWwindow* window,int width, int height)
	{
		//_width = width;
		//_height = height;
		//glfwGetFramebufferSize();
		glViewport(0, 0, _width, _height);// stretch
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
		if (glewInit() != GLEW_OK) // first glfwMakeContextCurrent and later this
		{
			cout << "Could not initialize GLEW!" << endl;
			return false;
		}
		cout << "OpenGL " << glGetString(GL_VERSION) << endl;
		return true;
	}
	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	}
}
}