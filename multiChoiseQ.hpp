#ifndef MULTICHOICEQ_HPP
#define MULTICHOICEQ_HPP

#include "Question.hpp"

#include <vector>
#include <string>

class MultipleChoiceQuestion : public Question {
private:
    std::string questionText;
    std::vector<std::string> choices;
    int correctAnswerIndex;

public:
    MultipleChoiceQuestion(const std::string& text, const std::vector<std::string>& opts, int correctIndex)
        : questionText(text), choices(opts), correctAnswerIndex(correctIndex) {}

    void askQuestion() const override {
        std::cout << questionText << "\n";
        for (size_t i = 0; i < choices.size(); ++i) {
            std::cout << i + 1 << ". " << choices[i] << "\n";
        }
    }

    bool checkAnswer(const std::string& answer) const override {
        try {
            int answerIndex = std::stoi(answer) - 1; 
            return answerIndex == correctAnswerIndex;
        }
        catch (...) {
            return false;
        }
    }
};

#endif
