//#define GLM_FORCE_RADIANS
//#define GLM_FORCE_DEPTH_ZERO_TO_ONE
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>

#include "../HeaderFiles/VulkanApplicationBase.h"

#include <iostream>

const int windowWidth = 1920;
const int windowHeight = 1080;
const char* windowName = "Horrible Engine";

int main()
{
	VulkanApplicationBase app;
	try
	{
		app.Run();
	}
	catch (const std::exception e)
	{
		std::cout << e.what();
		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS;
}

