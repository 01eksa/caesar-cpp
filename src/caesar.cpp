#include "caesar.h"

#include <stdexcept>

using namespace caesar;

void caesar::encode(std::string& input, const unsigned offset) {
    for (std::size_t i = 0; i < input.length(); i++) {
        if (input[i] >= lowercase_alphabet.front() && input[i] <= lowercase_alphabet.back())
            [[likely]] {
            const std::size_t index     = input[i] - lowercase_alphabet.front();
            const std::size_t new_index = (index + offset) % lowercase_alphabet.size();

            input[i] = lowercase_alphabet[new_index];
        } else if (input[i] >= uppercase_alphabet.front()
                   && input[i] <= uppercase_alphabet.back()) {
            const std::size_t index     = input[i] - uppercase_alphabet.front();
            const std::size_t new_index = (index + offset) % uppercase_alphabet.size();

            input[i] = uppercase_alphabet[new_index];
        } else
            continue;
    }
}

void caesar::decode(std::string& input, const unsigned offset) {
    const unsigned new_offset = lowercase_alphabet.size() - offset % lowercase_alphabet.size();
    return encode(input, new_offset);
}
