#ifndef QUESTIONLOADER_H
#define QUESTIONLOADER_H

#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include "multiChoiseQ.hpp"

class QuestionLoader {
public:
    static std::vector<std::unique_ptr<Question>> loadQuestionsFromFile(const std::string& filename) {
        std::vector<std::unique_ptr<Question>> questions;
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream stream(line);
            std::string type;
            std::getline(stream, type, '|');

            if (type == "MultipleChoice") {
                std::string text;
                std::getline(stream, text, '|');
                std::vector<std::string> options;
                for (int i = 0; i < 4; ++i) {
                    std::string option;
                    std::getline(stream, option, '|');
                    options.push_back(option);
                }
                int correctOption;
                stream >> correctOption;
                questions.push_back(std::make_unique<MultipleChoiceQuestion>(text, options, correctOption - 1));
            }
    
        }

        return questions;
    }
};

#endif
