#ifndef QUIZ_H
#define QUIZ_H

#include "Question.hpp"
#include <vector>
#include <iostream>

class Quiz {
private:
    std::vector<Question*> questions;
    int score;

public:
    Quiz() : score(0) {}

    void addQuestion(Question* question) {
        questions.push_back(question);
    }

    void startQuiz() {
        for (auto& question : questions) {
            question->askQuestion();
            std::string answer;
            std::getline(std::cin, answer);
            if (question->checkAnswer(answer)) {
                score++;
            }
        }
        std::cout << "Your score: " << score << "/" << questions.size() << std::endl;
    }

    ~Quiz() {
        for (auto q : questions) {
            delete q;
        }
    }
};

#endif
