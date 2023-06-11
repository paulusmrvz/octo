#pragma once

#include <memory>
#include <optional>

#include <vulkan/vulkan.h>

#include "window.h"

struct QueueFamilyIndices {
	std::optional<uint32_t> GraphicsFamily;
	std::optional<uint32_t> PresentFamily;

	bool IsComplete() {
		return GraphicsFamily.has_value() && PresentFamily.has_value();
	}
};

namespace Octo {
	class Device {
	public:
		Device(std::shared_ptr<Window> pWin);
		~Device();
	private: // Instance
		void CreateInstance();
		void DestroyInstance();
	private: // Validation
		bool CheckValidationLayerSupport();
		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
			void *pUserData
		);
		void SetupDebugMessenger();
		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
		void DestroyMessenger();
	private: // Surface
		void CreateSurface();
		void DestroySurface();
	private: // Physical Device
		void PickPhysicalDevie();
		bool IsDeviceSuitable(VkPhysicalDevice device);
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
	private: // Logical Device
		void CreateDevice();
		void DestroyDevice();
	private: // Fields
		std::shared_ptr<Window> m_pWin;
	private: // Instance
		VkInstance m_Instance;
	private: // Validation
		const std::vector<const char*> m_ValidationLayers {
			"VK_LAYER_KHRONOS_validation"
		};
		VkDebugUtilsMessengerEXT m_DebugMessenger;
	private: // Surface
		VkSurfaceKHR m_Surface;
	private: // Physical Device
		VkPhysicalDevice m_PhDevice;
		const std::vector<const char*> m_DeviceExtensions {
			VK_KHR_SWAPCHAIN_EXTENSION_NAME
		};
	private: // Logical Device
		VkDevice m_Device;
	private: // Queues
		VkQueue m_GraphicsQueue;
		VkQueue m_PresentQueue;
	};
}