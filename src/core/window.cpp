#include "window.h"

#include <stdexcept>
#include <tools/log.h>

namespace Octo {
    Window::Props::Props(int width, int height, const std::string &title)
        : Width{ width }, Height{ height }, Title{ title } {}

    Window::Window(const Props &props)
        : m_Window{ nullptr }, m_Props{ props } {
        Create();
    }

    Window::Window(int width, int height, const std::string &title)
        : m_Window{ nullptr }, m_Props{ width, height, title } {
        Create();
    }

    Window::~Window() {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }

    void Window::PollEvents() {
        glfwPollEvents();
    }

    bool Window::IsShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::GetInput() {
        if (glfwGetKey(m_Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(m_Window, true);
        }
    }

    GLFWwindow* Window::GetNative() const {
        return m_Window;
    }

    std::vector<const char*> Window::GetSurfaceExtensions() const {
        uint32_t glfwExtensionsCount{};
        const char **glfwExtensions{ glfwGetRequiredInstanceExtensions(&glfwExtensionsCount) };

        return std::vector<const char*>(glfwExtensions, glfwExtensions + glfwExtensionsCount);
    }

    void Window::Create() {
        int status{ glfwInit() };

        if (status == GLFW_FALSE) {
            throw std::runtime_error("Couldn't initialize GLFW!");
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Window = glfwCreateWindow(
            m_Props.Width, 
            m_Props.Height, 
            m_Props.Title.c_str(), 
            nullptr, 
            nullptr
        );

        if (m_Window == nullptr) {
            throw std::runtime_error("Couldn't create GLFW window!");
        }

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true);
            }
        });
    }
}