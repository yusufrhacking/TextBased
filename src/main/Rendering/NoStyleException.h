#ifndef TEXTBASED_NOSTYLEEXCEPTION_H
#define TEXTBASED_NOSTYLEEXCEPTION_H
#include <exception>
#include <string>

struct NoStyleException : public std::exception {
    const char* what(){
        return "No Valid Style Given for this Component";
    }
};

#endif
