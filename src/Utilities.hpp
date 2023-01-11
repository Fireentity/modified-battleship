#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <algorithm>

namespace utils {

    template <int dim,typename T>
    std::string format(const std::string &replaced, const T (&replacements)[dim], const std::function<std::string(const T &)> &to_string) {
        std::string result {replaced};
        for(int i = 0; i < dim;i++ ) {
            std::string placeholder = "{" + std::to_string(i) + "}";
            std::replace(result.begin(), result.end(), placeholder, to_string(replacements[i]));
        }
        return result;
    }

};

#endif //UTILITIES_H
