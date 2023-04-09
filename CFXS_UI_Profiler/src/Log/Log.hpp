// [CFXS] //
#pragma once

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

#include <QString>

class Log {
public:
    static void Initialize();

    static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() {
        return s_CoreLogger;
    }

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
};

template<>
struct fmt::formatter<QString> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.end();
    }

    template<typename FormatContext>
    auto format(const QString& input, FormatContext& ctx) -> decltype(ctx.out()) {
        return format_to(ctx.out(), "{}", input.toStdString());
    }
};

// Core log macros
#define LOG_TRACE(...)    ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)     ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)     ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)    ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::Log::GetCoreLogger()->critical(__VA_ARGS__)
