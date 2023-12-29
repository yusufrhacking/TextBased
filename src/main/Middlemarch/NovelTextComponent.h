#ifndef TEXTBASED_NOVELTEXTCOMPONENT_H
#define TEXTBASED_NOVELTEXTCOMPONENT_H
#include <string>
#include <utility>

struct NovelTextComponent {
    size_t readIndex = 0;
    std::string subject;
    bool pauseAtInitialSubject;
    bool subjectFound = false;

    NovelTextComponent() = default;
    explicit NovelTextComponent(std::string subject): subject(std::move(subject)) {
        pauseAtInitialSubject = false;
    }

    NovelTextComponent(std::string subject, bool pauseAtInitialSubject): subject(std::move(subject)), pauseAtInitialSubject(pauseAtInitialSubject) {}
};

#endif
