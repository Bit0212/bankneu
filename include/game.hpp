#ifndef GAME_HPP
#define GAME_HPP
#include <raylib.h>
#include <string>
#include <thread>

template< typename T, typename ... Arguments  >
constexpr T promedium( Arguments ... argos){
    T numerator =0;
 numerator = static_cast<T>((argos+...));

return numerator/sizeof...(argos);

} 

inline constexpr int width = 1920;
inline constexpr int height = 1080;
inline constexpr int FPS = 15;
inline constexpr int promwh =  promedium<int>(height,width);
class Game{
    public:
        int iterator;
        std::thread l; 
    std::string windowname{"Heypeople"};
    Game(int p);
    ~Game();
};


#endif
