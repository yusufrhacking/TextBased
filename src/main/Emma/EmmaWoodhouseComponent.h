#ifndef TEXTBASED_EMMAWOODHOUSECOMPONENT_H
#define TEXTBASED_EMMAWOODHOUSECOMPONENT_H

#include <string>

struct EmmaWoodhouseComponent{
    std::string finalState = "Emma Woodhouse, handsome, clever, and rich, with a comfortable home and happy disposition, seemed to unite some of the best blessings of existence; and had lived nearly twenty-one years in the world with very little to distress or vex her.";

    std::string getNextState(const std::string& currState){
        std::string newState = currState;
        int index = currState.size();
        char nextChar = finalState[index];
        newState += nextChar;
        if (nextChar == ' '){
            newState += finalState[index+1];
        }
        return newState;
    }
};

#endif //TEXTBASED_EMMAWOODHOUSECOMPONENT_H
