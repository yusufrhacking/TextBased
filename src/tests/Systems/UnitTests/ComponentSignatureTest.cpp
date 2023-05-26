#include <catch2/catch_test_macros.hpp>
#include "../../../main/ECS/Design/Objects/ComponentSignature.h"
#include "../../../main/ECS/Components/TextComponents/TextComponent.h"
#include "../../../main/ECS/Components/TextComponents/TreeComponent.h"
#include "../../../main/ECS/Design/Objects/Component.h"
#include "../../../main/ECS/Components/PositionComponent.h"

TEST_CASE("Component Signature Testing", "[ECS]"){
    ComponentSignature systemSignature;
    ComponentSignature entitySignature;
    //A tree component inherits from Text Component
//    REQUIRE(ComponentSignature::systemHoldsEntity(systemSignature, entitySignature));
}