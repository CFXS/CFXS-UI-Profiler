// [CFXS] //
#pragma once

#define L0_OVERLOAD_ENUM_BITWISE_OPERATORS(enumName)                                                                        \
    constexpr enumName operator|(enumName a, enumName b) {                                                                  \
        return static_cast<enumName>(static_cast<std::underlying_type<enumName>::type>(a) |                                 \
                                     static_cast<std::underlying_type<enumName>::type>(b));                                 \
    }                                                                                                                       \
    constexpr bool operator&(enumName a, enumName b) {                                                                      \
        return static_cast<std::underlying_type<enumName>::type>(a) & static_cast<std::underlying_type<enumName>::type>(b); \
    }

inline uint64_t operator"" _kB(uint64_t val) {
    return val * 1024;
}

inline uint64_t operator"" _MB(uint64_t val) {
    return val * 1024 * 1024;
}

inline uint64_t operator"" _GB(uint64_t val) {
    return val * 1024 * 1024 * 1024;
}