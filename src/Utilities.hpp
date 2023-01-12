#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <algorithm>

namespace utils {

    template <unsigned long dim>
    std::string format(const std::string &replaced, const int (&replacements)[dim]) {
        std::string result {replaced};
        for(int i = 0; i < 12; i++) {
            std::stringstream placeholder{""} ;
            placeholder << "{" << i << "}";
            result = std::regex_replace(result,std::regex{placeholder.str()},std::to_string(replacements[i]));
        }
    }

    template <unsigned long dim>
    std::string format(const std::string &replaced, const char (&replacements)[dim]) {
        std::string result {replaced};
        for(int i = 0; i < 12; i++) {
            std::stringstream placeholder{""} ;
            placeholder << "{" << i << "}";
            result = std::regex_replace(result,std::regex{placeholder.str()},std::to_string(replacements[i]));
        }
    }

}

#endif //UTILITIES_H
