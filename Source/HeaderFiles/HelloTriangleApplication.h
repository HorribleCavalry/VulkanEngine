#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
//#include <vulkan/vulkan_core.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication
{
private:
	int width;
	int height;
	std::string windowName;
	GLFWwindow* window;

	VkInstance instance;

public:
	HelloTriangleApplication() :
		width(1920),
		height(1080),
		windowName("Horrible Vulkan Hello Triangle")
	{

	}

	~HelloTriangleApplication()
	{
		Cleanup();
	}
public:
	void Run()
	{
		InitWindow();
		InitVulkan();
		MainLoop();
		Cleanup();
	}

	void Show()
	{

	}

	void Hide()
	{

	}

	void CheckVKEnumerateInstanceExtensionProperties()
	{
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> extensions(extensionCount);

		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
		std::cout << "Available extensions:\n";

		for (const auto& extension : extensions) {
			std::cout << '\t' << extension.extensionName << '\n';
		}
	}

private:
	void InitWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	void CreateVKInstance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Horrible Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;

		const VkResult& createInsResult = vkCreateInstance(&createInfo, nullptr, &instance);
		if (createInsResult != VK_SUCCESS) {
			throw std::runtime_error("failed to create instance!");
		}
	}

	void InitVulkan()
	{
		CreateVKInstance();
	}

	void ResetWindowSize()
	{

	}

	void MainLoop()
	{
		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();
		}
	}

	void Cleanup()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
};