#include <iostream>
#include <string>
#include <vector>
#include<raylib.h>
#include<chrono>
#include <thread>
#include "game.hpp"
#include "entities.hpp"

void x(std::vector<person>& r){
while (!r.empty()){
    //p.size() is unsigned
for(int f =static_cast<int>(r.size())-1; f>=0;f--){
    r[f].randevents();
    if(r[f].age>100 || r[f].actualcash <0 ||r[f].depressivestate>100 ){
r.erase(r.begin()+f);
    
}
std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}
}
}



Game::Game(int p){
    InitWindow(width, height,this->windowname.c_str());
SetTargetFPS(FPS);
iterator = p;
std::vector<person> r;
std::atomic<bool> bit =true;


for(int e =0; e<iterator; e++)
 r.emplace_back();
for(person k : r){
k.evoke();
}
std::thread l(x,std::ref(r));
while(!WindowShouldClose()){
BeginDrawing();
ClearBackground(RAYWHITE);
for(person f : r){
f.draw();
f.updatepos();

}



EndDrawing();
}

};
Game::~Game(){
    std::cout<<"tot ziens en dank je wel";

};

