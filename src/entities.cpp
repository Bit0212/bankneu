#include <iostream>
#include <random>
#include <raylib.h>
#include "entities.hpp"
#include "game.hpp"
std::random_device bd;
std::mt19937 gen(bd());
std::uniform_int_distribution dif(0,5);
std::uniform_int_distribution agi(13,50);
std::uniform_int_distribution cash(1450,15000);
std::uniform_int_distribution rndevents(0,3);
std::uniform_real_distribution rnpos(1.0f,static_cast<float>(promwh));

void person::evoke(){
this->pos = {rnpos(gen),rnpos(gen)};
};
void person::updatepos(){


};


person::person(){
        std::cout<<"i've been born today\n";


this->name =potentialnames[dif(gen)];
this->age =agi(gen); 
this->actualcash =cash(gen); 
this->depressivestate =0;
std::cout<<"my name is : "<<this->name<<" \n";

    }
person::~person(){
    std::cout<<"i'm dead at all, with this stats\n";
    std::cout<<this->name<<","<<this->age<<","<<this->actualcash<<","<<this->depressivestate<<"\n";



}  

void person::randevents(){
int n = rndevents(gen);
int desc  = (this->actualcash*20)/100;
potentialstates Potential = static_cast<potentialstates>(n);
switch (Potential){
    case potentialstates::CashLoss:
    std::cout<<"nothing good happens\n";
    this->actualcash -= desc;
    break;
    case potentialstates::AgeGain:
    std::cout<<"nothing else matters\n";
    this->age +=10;
    break;
    case potentialstates::DepressionWon:
    std::cout<<"depression in its max state\n";
    this->depressivestate +=10;
    break;
    case potentialstates::CashGain:
        std::cout<<"more cash hehe\n";
        this->actualcash +=desc;
        break;
    
    default:
        std::cout<<"this one shouldn't happen";
        break;
        
    
    
}
simcount++;
std::cout<<"this is the event number: "<<simcount<<"keep going\n"; 

}

