#ifndef ABYZPRIORITIZINGSYSTEM_H
#define ABYZPRIORITIZINGSYSTEM_H
#include "../ECSObjects/UpdateSystem.h"
#include "../Middlemarch/EndOfReadingEvent.h"


class WordRelicPrioritizingSystem: public UpdateSystem {
    std::chrono::steady_clock::time_point lastUpdateTime;
    int workDelayMilliseconds = 50;
    void onEndOfReading(EndOfReadingEvent& event);
    bool start;
public:
    WordRelicPrioritizingSystem();
    void update(double deltaTime) override;

};



#endif //ABYZPRIORITIZINGSYSTEM_H
