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

struct LetterMazePrefab {
    explicit LetterMazePrefab(const Position center, int startIndex, int length) {
        Position currPosition = center;
        const TextComponent dummyLetter = TextComponent("a");
        const Size letterSize = dummyLetter.getSurfaceSize();

        for(int x = 0; x < length; x++) {
            char letter = 'a' + ((startIndex + x) % 26);
            LetterPrefab{letter, currPosition};
            currPosition += {static_cast<float>(letterSize.width) * 2, static_cast<float>(0)};
        }
    }
};



#endif
