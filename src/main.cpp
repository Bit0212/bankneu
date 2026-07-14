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
/*   std::vector<person> p{};
std::size_t k =static_cast<std::size_t> (f);
for (std::size_t i =0; i<k; i++){//creation of people
p.emplace_back();
    
}



*/
int* k = new int(20);
delete k;
delete k;
Game game(f);
return 0;

}
