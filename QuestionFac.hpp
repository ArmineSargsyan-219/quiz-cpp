#ifndef QUESTIONFACTORY_H
#define QUESTIONFACTORY_H

#include "multiChoiseQ.hpp"

class QuestionFactory {
public:
    static Question* createQuestion(const std::string& type) {
        if (type == "MultipleChoice") {
            return new MultipleChoiceQuestion("What is 2 + 2?", {"1", "2", "3", "4"}, 3);
        }
        return nullptr;
    }
};

#endif
