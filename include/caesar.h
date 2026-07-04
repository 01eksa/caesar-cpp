#pragma once

#include <string>

namespace caesar {

    inline constexpr std::string_view lowercase_alphabet = "abcdefghijklmnopqrstuvwxyz";
    inline constexpr std::string_view uppercase_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    void encode(std::string& input, unsigned offset);

    void decode(std::string &input, unsigned offset);


}
