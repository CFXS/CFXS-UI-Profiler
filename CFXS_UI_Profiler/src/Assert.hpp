// [CFXS] //
#pragma once

#include <filesystem>

#define L0_ASSERT(x, y)                                                                                                        \
    {                                                                                                                          \
        if (!(x)) {                                                                                                            \
            LOG_CORE_ERROR("{0}:{1}  ASSERT FAILED: " #y "\n", std::filesystem::path(__FILE__).filename().string(), __LINE__); \
            L0_DEBUGBREAK();                                                                                                   \
        }                                                                                                                      \
    }

#define L0_NOT_IMPLEMENTED L0_ASSERT(0, "Not Implemented :(")