#pragma once
#include <variant>

// Logging functions, for specific to std::variant

#define LogVariant(x) std::visit([](const auto& v){ std::cout << v ;}, x);
#define Log(x) std::cout << x;



