#pragma once
#include <iostream>
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
		void Update() const;
		bool Closed() const;
	private:
		bool Init();

	};
}
}