#include <iostream>
#include <memory>
#include "Quiz.hpp"
#include "QuestionFac.hpp"

int main() {
    Quiz quiz;

    std::cout << "1. Start Quiz\n2. Exit\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore(); 

    if (choice == 1) {
        std::cout << "Select a Subject:\n";
        std::cout << "1. Math\n2. Science\n3. History\n4.Geography\n";
        int subjectChoice;
        std::cin >> subjectChoice;
        std::cin.ignore(); 

        std::string selectedSubject;

        switch (subjectChoice) {
            case 1:
                selectedSubject = "Math";
                break;
            case 2:
                selectedSubject = "Science";
                break;
            case 3:
                selectedSubject = "History";
                break;
            case 4:
                selectedSubject = "Geography";
                break;
            default:
                std::cout << "Invalid choice. Exiting...\n";
                return 0;
        }

        auto questions = QuestionFactory::createQuestions(selectedSubject);

        for (auto& question : questions) {
            quiz.addQuestion(std::move(question));
        }
        quiz.startQuiz();
    }

    return 0;
}
