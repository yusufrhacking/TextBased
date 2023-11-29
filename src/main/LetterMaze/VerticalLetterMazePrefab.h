#ifndef VERTICALLETTERMAZEPREFAB_H
#define VERTICALLETTERMAZEPREFAB_H

#include <memory>
#include "../HighLevel/ECSManager.h"
#include "../PositionsAndMovement/CollisionComponent.h"
#include "../PositionsAndMovement/PositionComponent.h"
#include "../Creation/CreateLetterAtPositionEvent.h"
#include "../Text/TextGenerator.h"
#include "../Lettering/LetterPrefab.h"

extern std::unique_ptr<ECSManager> ecsManager;

struct VerticalLetterMazePrefab {
    explicit VerticalLetterMazePrefab(const Position position, int startIndex, int length) {
        Position currPosition = position;
        const TextComponent dummyLetter = TextComponent("a");
        const Size letterSize = dummyLetter.getSurfaceSize();

        for(int x = 0; x < length; x++) {
            char letter = 'a' + ((startIndex + x) % 26);
            spdlog::info("Letter {}", letter);
            LetterPrefab{letter, currPosition};
            currPosition += {static_cast<float>(0), static_cast<float>(letterSize.height) * 2};
        }
    }
};

#endif //VERTICALLETTERMAZEPREFAB_H
