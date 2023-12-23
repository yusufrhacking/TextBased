#ifndef LETTERMAZEPREFAB_H
#define LETTERMAZEPREFAB_H

#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Creation/CreateLetterAtPositionEvent.h"
#include "../Text/TextGenerator.h"
#include "../Lettering/LetterPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct LetterStreamPrefab {
    explicit LetterStreamPrefab(const Position position, int startIndex, int length) {
        Position currPosition = position;
        const TextComponent dummyLetter = TextComponent("a");
        const EntitySize letterSize = dummyLetter.getSurfaceSize();

        for(int x = 0; x < length; x++) {
            char letter = 'a' + ((startIndex + x) % 26);
            LetterPrefab{letter, currPosition};
            currPosition += {static_cast<float>(letterSize.width) * 2, static_cast<float>(0)};
        }
    }
    explicit LetterStreamPrefab(const Position position, int startIndex, int length, bool flip) {
        Position currPosition = position;
        const TextComponent dummyLetter = TextComponent("a");
        const EntitySize letterSize = dummyLetter.getSurfaceSize();

        for(int x = 0; x < length; x++) {
            char letter;
            if (flip) {
                letter = 'z' - ((length - 1 - x + startIndex) % 26);
            } else {
                letter = 'a' + ((startIndex + x) % 26);
            }
            LetterPrefab{letter, currPosition};
            currPosition += {static_cast<float>(letterSize.width) * 2, static_cast<float>(0)};
        }
    }

};



#endif
