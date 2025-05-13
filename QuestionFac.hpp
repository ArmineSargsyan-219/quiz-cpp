#ifndef QUESTIONFACTORY_HPP
#define QUESTIONFACTORY_HPP

#include "multiChoiseQ.hpp"  
#include <memory> 
#include <vector>
#include <string>

class QuestionFactory {
public:
    static std::vector<std::unique_ptr<Question>> createQuestions(const std::string& subject) {
        std::vector<std::unique_ptr<Question>> questions;

        if (subject == "Math") {
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is 2 + 2?", 
                                                                        std::vector<std::string>{"1", "2", "3", "4"}, 3));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is 3 + 5?", 
                                                                        std::vector<std::string>{"6", "7", "8", "9"}, 2));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is 9 * 8?", 
                                                                        std::vector<std::string>{"56", "72", "64", "81"}, 1));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is 12 / 4?", 
                                                                        std::vector<std::string>{"2", "3", "4", "5"}, 1));
        } else if (subject == "Science") {
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is the boiling point of water?", 
                                                                        std::vector<std::string>{"90°C", "100°C", "110°C", "120°C"}, 1));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is the chemical symbol for water?", 
                                                                        std::vector<std::string>{"O2", "H2O", "CO2", "O3"}, 1));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is the chemical formula for carbon dioxide?", 
                                                                        std::vector<std::string>{"CO2", "CO", "C2O", "O2"}, 0));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What planet is known as the Red Planet?", 
                                                                        std::vector<std::string>{"Earth", "Mars", "Jupiter", "Venus"}, 1));
        } else if (subject == "History") {
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("Who was the first President of the United States?", 
                                                                        std::vector<std::string>{"Abraham Lincoln", "George Washington", "Thomas Jefferson", "John Adams"}, 1));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("Which year did World War II end?", 
                                                                        std::vector<std::string>{"1940", "1945", "1950", "1960"}, 1));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("In which year did the Titanic sink?", 
                                                                        std::vector<std::string>{"1912", "1920", "1930", "1940"}, 0));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("Who discovered America?", 
                                                                        std::vector<std::string>{"Christopher Columbus", "Leif Erikson", "Marco Polo", "Ferdinand Magellan"}, 0));
        } else if (subject == "Geography") {
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("What is the capital of France?", 
                                                                        std::vector<std::string>{"Paris", "Rome", "Madrid", "Berlin"}, 0));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("Which continent is Australia located in?", 
                                                                        std::vector<std::string>{"Asia", "Africa", "Oceania", "Europe"}, 2));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("Which river is the longest in the world?", 
                                                                        std::vector<std::string>{"Amazon River", "Nile River", "Yangtze River", "Ganges River"}, 1));
            questions.push_back(std::make_unique<MultipleChoiceQuestion>("Which is the largest ocean on Earth?", 
                                                                        std::vector<std::string>{"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean"}, 1));
        }

        return questions;
    }
};

#endif
