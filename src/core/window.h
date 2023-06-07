#pragma once

#include <GLFW/glfw3.h>

#include <string>
#include <vector>

namespace Octo {
    class Window {
    public:
        struct Props{
            Props(int width = 1280, int height = 720, const std::string &title = "Octo");
            int Width;
            int Height;
            std::string Title;
        };
    public:
        Window(const Props &props = Props());
        Window(int width, int height, const std::string &title);
        ~Window();

        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        Window(Window&&) = delete;
        Window& operator=(Window&&) = delete;
    public:
        void PollEvents();
        bool IsShouldClose() const;
        void GetInput();
        GLFWwindow* GetNative() const;
        std::vector<const char*> GetSurfaceExtensions() const;
    private:
        void Create();
    private:
        Props m_Props;
        GLFWwindow *m_Window;
    };
}