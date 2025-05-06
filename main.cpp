#include <iostream>
#include "Quiz.hpp"
#include "QuestionFac.hpp"

int main() {
    Quiz quiz;
    
   
    quiz.addQuestion(QuestionFactory::createQuestion("MultipleChoice"));
    quiz.addQuestion(QuestionFactory::createQuestion("MultipleChoice"));
  
   quiz.startQuiz();

    return 0;
}
