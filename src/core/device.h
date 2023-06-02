#pragma once

#include <memory>
#include <optional>

#include <vulkan/vulkan.h>

#include "window.h"

struct QueueFamilyIndices {
    std::optional<uint32_t> GraphicsFamily;

    bool isComplete() {
        return GraphicsFamily.has_value();
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
    private: // Physical Device
        void PickPhysicalDevie();
        bool IsDeviceSuitable(VkPhysicalDevice device);
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
    private: // Physical Device
        VkPhysicalDevice m_PhDevice;
    private: // Logical Device
        VkDevice m_Device;
        VkQueue m_GraphicsQueue;
    };
}