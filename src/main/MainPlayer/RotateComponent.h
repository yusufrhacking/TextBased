#ifndef TEXTBASED_ROTATECOMPONENT_H
#define TEXTBASED_ROTATECOMPONENT_H

enum class RotationState{
    LEFT_TO_RIGHT,
    TOP_TO_BOTTOM
};

struct RotationComponent{
    RotationState state = RotationState::LEFT_TO_RIGHT;
    void rotate(std::string& text){
        std::string rotatedText;
        switch (state) {
            case RotationState::LEFT_TO_RIGHT:
                for (const char& c : text) {
                    rotatedText += c;
                    rotatedText += "\n";
                }
                if (!rotatedText.empty()) {
                    rotatedText.pop_back();
                }
                state = RotationState::TOP_TO_BOTTOM;
                break;
            case RotationState::TOP_TO_BOTTOM:
                rotatedText = text;
                rotatedText.erase(std::remove(rotatedText.begin(), rotatedText.end(), '\n'), rotatedText.end());
                state = RotationState::LEFT_TO_RIGHT;
                break;
        }
        text = std::move(rotatedText);
    }
};

#endif //TEXTBASED_ROTATECOMPONENT_H
