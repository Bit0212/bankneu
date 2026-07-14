#include <iostream>
#include <random>
#include <raylib.h>
#include "entities.hpp"
#include "game.hpp"
std::random_device bd;
std::mt19937 gen(bd());
std::uniform_int_distribution dif(0,9);
std::uniform_int_distribution agi(13,50);
std::uniform_int_distribution cash(1450,15000);
std::uniform_int_distribution rndevents(0,3);
std::uniform_real_distribution<> rnpos(1.0f,static_cast<float>(promwh));
std::uniform_int_distribution randomexec(0,3);
std::uniform_real_distribution<> spdval(1.0f, 10.0f);
std::uniform_int_distribution randiumovich(1,5);
void person::evoke(){
    float posx = rnpos(gen);
    float posy = rnpos(gen);
this->pos = {posx,posy};
this->dvpos = {((pos.x+promwh)/2), ((pos.y+promwh)/2)};
this->radium = randiumovich(gen);
};
void person::draw(){
DrawCircle(pos.x,pos.y,radium,RED);
drawname();
}
void person::updatepos(){
float frame = GetFrameTime();
   int konstant = randomexec(gen);
potentialmovements potencielle = static_cast<potentialmovements>(konstant);
switch(potencielle){
    case potentialmovements::Up:
        this->pos.y -=this->speed*frame;
        break;
    case potentialmovements::Down:
        this->pos.y += this->speed*frame;
        break;
    case potentialmovements::Left:
        this->pos.x += this->speed*frame;
        break;
    case potentialmovements::Right:
        this->pos.x +=this->speed*frame;
        break;

        

}
if (this->pos.x>width*5 || this->pos.y>height*5){
this->pos.x = width/2;
this->pos.y = height/2;

}



}


person::person(){
        std::cout<<"i've been born today\n";

this->speed =spdval(gen); 
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
void person::drawname(){
int namesize = static_cast<int>(0.2*this->radium);    
DrawText(this->name.c_str(),this->pos.x, (this->pos.y-300),namesize,BLACK);

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
 void person::alivechecker(){

if(this->age>500 || this->actualcash <0 ||this->depressivestate>100 ){
   this->IsAlive =false; 
}


}
