//Marco Pavanetto 2032486

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <algorithm>

namespace utils {

    static constexpr char firstLetter = 'A';
    static constexpr char firstLetterToAvoid = 'J';

    std::string format(const std::string &replaced, const std::string &placeholder, const std::string &replacement) {
        return std::regex_replace(replaced, std::regex{placeholder}, replacement);
    }

    template<unsigned long dim>
    std::string format(const std::string &replaced, const int (&replacements)[dim]) {
        std::string result{replaced};
        for (int i = 0; i < dim; i++) {
            std::stringstream placeholder{};
            placeholder << "%" << i << "%";
            result = utils::format(result,placeholder.str(),std::to_string(replacements[i]));
        }
        return result;
    }

    template<unsigned long dim>
    std::string format(const std::string &replaced, const char (&replacements)[dim]) {
        std::string result{replaced};
        for (int i = 0; i < dim; i++) {
            std::stringstream placeholder{};
            placeholder << "%" << i << "%";
            result = utils::format(result,placeholder.str(),std::string{replacements[i]});
        }
        return result;
    }

    std::string repeat(const std::string &string, int times) {
        std::stringstream ss{};
        for (int i = 0; i < times; i++) {
            ss << string;
        }
        return ss.str();
    }

    char number_to_letter(int n) {
        char letter = firstLetter + (n - 1);
        if (letter >= firstLetterToAvoid) {
            letter += 2;
        }
        return letter;
    }

}

#endif //UTILITIES_H
