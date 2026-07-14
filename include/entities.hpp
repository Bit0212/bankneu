#ifndef ENTITIES_HPP
#define ENTITIES_HPP 
#include <iostream> 
#include <atomic>
#include <array>
#include <string>
#include <raylib.h>
class entity{ // in case of creating more entity types(classes)
    public:
virtual void evoke() =0;
virtual void updatepos()=0;
virtual void draw() =0;

};


class person : public entity{
    public:
        bool IsAlive{true};
    std::array<std::string,10> potentialnames{"jose","pedro", "constantino", "manuel", "pedro", "energumeno", "patroclo", "ulises", "al-iksindr", "o-megas"};
    std::string name;
    int radium;
    int age;
    double actualcash;
    int depressivestate;
    Vector2 pos;
    Vector2 dvpos;
    float speed;
void drawname();
void randevents();
void draw() override final;
void evoke() override final;
void updatepos() override final;
void alivechecker();

    private:
    enum class potentialstates :int {
CashLoss,
CashGain,
AgeGain ,
DepressionWon,



    };
    enum class potentialmovements : int{
    Up,
    Down,
    Right,
    Left
    };
    // why atomic?: race conditions (just in case)
   inline static std::atomic<int>simcount =0;

    public: 
     person();
~person();
};
#endif
