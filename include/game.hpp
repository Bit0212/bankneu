#ifndef GAME_HPP
#define GAME_HPP
#include<cmath>
#include <raylib.h>
//for bit from the future:
//use standard desviation (this template is intended for this)
//then generate the value in dv
template< typename T, typename ... Arguments  >
constexpr T promedium( Arguments ... argos){
    T numerator =0;
 numerator = static_cast<T>((argos+...));

return numerator/sizeof...(argos);

} 

inline constexpr int width = 600;
inline constexpr int height = 800;
inline constexpr int FPS = 60;
inline constexpr int promwh =  promedium<int>(height,width);

class Game{

    Game();
    ~Game();
};


#endif
