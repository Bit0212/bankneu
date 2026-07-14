#include <iostream>
#include <string>
#include<vector>
#include <random>
#include <array>
#include <atomic>
#include <raylib.h>  
#include "entities.hpp"
#include "game.hpp"



int main(){
std::cout<<"hello all the world, how are them hehe \n";
std::cout<<"to begin this, please insert a number to run this simulation\n";
int f{0};
std::cin>>f;
if(f<0){
    std::cerr<<"don't put negative numbers in this simulation\n";
    return 1;
}

Game game(f);
return 0;

}
