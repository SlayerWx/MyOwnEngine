#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;
namespace MyOwnEngine{namespace graphics{
	class Window
	{
	private:
		const char* _title;
		int _width,_height;
		GLFWwindow* _window;
		bool _closed;
	public:
		Window(const char* name,int width,int height);
		~Window();
		void Update();
		bool Closed() const;
		void WindowResize(GLFWwindow* window,int width,int height);
		inline int GetWidth() const { return _width; };
		inline int GetHeight() const { return _height; };
	private:
		bool Init();
		void Clear() const;

	};
}
}