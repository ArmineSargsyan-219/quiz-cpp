#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
    virtual void askQuestion() = 0;
    virtual bool checkAnswer(const std::string& answer) = 0;
    virtual ~Question() {}
};

#endif
