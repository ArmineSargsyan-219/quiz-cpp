#ifndef MULTIPLECHOICEQUESTION_H
#define MULTIPLECHOICEQUESTION_H

#include "Question.hpp"
#include <vector>
#include <iostream>

class MultipleChoiceQuestion : public Question {
private:
    std::string questionText;
    std::vector<std::string> options;
    int correctOption;

public:
    MultipleChoiceQuestion(std::string text, std::vector<std::string> opts, int correct)
        : questionText(text), options(opts), correctOption(correct) {}

    void askQuestion() override {
        std::cout << questionText << std::endl;
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << i + 1 << ". " << options[i] << std::endl;
        }
    }

    bool checkAnswer(const std::string& answer) override {
        return std::stoi(answer) - 1 == correctOption;
    }
};

#endif
