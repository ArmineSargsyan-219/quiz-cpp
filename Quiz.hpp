#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include <iostream>
#include <memory>
#include <memory> 
#include "Question.hpp"

class Quiz {
private:
    std::vector<std::unique_ptr<Question>> questions;
    int score;

public:
    Quiz() : score(0) {}

    void addQuestion(std::unique_ptr<Question> question) {
        questions.push_back(std::move(question));  
    }

    size_t getQuestionsSize() const {  
        return questions.size();
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

    ~Quiz() {}
};

#endif
