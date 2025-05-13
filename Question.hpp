#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <iostream>
#include <string>
#include <vector>

class Question {
public:
    virtual void askQuestion() const = 0;  
    virtual bool checkAnswer(const std::string& answer) const = 0;
    virtual ~Question() {}
};

#endif
