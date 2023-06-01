#pragma once

#include <memory>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Octo {
    class Log {
    public:
        static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger();
    private:
    	static std::shared_ptr<spdlog::logger> s_Logger;
    };
}

#define LOG_TRACE(...)    ::Octo::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)     ::Octo::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::Octo::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Octo::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)    ::Octo::Log::GetLogger()->fatal(__VA_ARGS__)