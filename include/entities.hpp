#include <iostream>
#include <atomic>
#include <array>
#include <string>
#include <raylib.h>
class entity{
    public:
virtual void evoke() =0;
virtual void updatepos()=0;

};


class person : public entity{
    public:
    std::array<std::string,6> potentialnames{"jose","pedro", "constantino", "manuel", "pedro", "energumeno"};
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
void draw();
void evoke() override final;
void updatepos() override final;


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

