#include <iostream>
#include <string>
#include <array>

constexpr char generate_random_key(int seed, size_t length) {
    unsigned int hash = 2166136261u;
    hash ^= static_cast<unsigned int>(seed);
    hash *= 16777619u;
    hash ^= static_cast<unsigned int>(length);
    hash *= 16777619u;
    return static_cast<char>((hash % 94) + 33);
}

template <size_t N>
struct xorstr {
    char data[N];

    template <size_t... Is>
    constexpr xorstr(const char(&str)[N], int seed, std::index_sequence<Is...>)
        : data{ (str[Is] ^ generate_random_key(seed, N))... } {
    }

    constexpr xorstr(const char(&str)[N], int seed)
        : xorstr(str, seed, std::make_index_sequence<N>()) {
    }

    std::string decrypt(int seed) const {
        char key = generate_random_key(seed, N);
        std::string res;
        res.reserve(N - 1);
        for (size_t i = 0; i < N - 1; i++) {
            res.push_back(data[i] ^ key);
        }
        return res;
    }
};

#define xorstr_(str) ([]() { \
    constexpr auto x = xorstr(str, __LINE__); \
    return x; \
}()).decrypt(__LINE__)