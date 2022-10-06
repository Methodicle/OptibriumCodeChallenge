#pragma once
#include <variant>


#define LogVariant(x) std::visit([](const auto& v){ std::cout << v ;}, x);
#define Log(x) std::cout << x;



