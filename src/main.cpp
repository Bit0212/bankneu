#include <iostream>
#include <string>
#include<vector>
#include <random>
#include <array>
#include <atomic>
#include <raylib.h>  
#include "entities.hpp"



int main(){
std::cout<<"hello all the world, how are them hehe \n";
std::cout<<"to begin this, please insert a number to run this simulation\n";
int f{0};
std::cin>>f;
if(f<0){
    std::cerr<<"don't put negative numbers in this simulation\n";
    return 1;
}
std::vector<person> p{};
std::size_t k =static_cast<std::size_t> (f);
for (std::size_t i =0; i<k; i++){//creation of people
p.emplace_back();
    
}


while (!p.empty()){
    //p.size() is unsigned
for(int f =static_cast<int>(p.size())-1; f>=0;f--){
    p[f].randevents();
    if(p[f].age>100 || p[f].actualcash <0 ||p[f].depressivestate>100 ){
p.erase(p.begin()+f);
    
}

}


}


return 0;

}
