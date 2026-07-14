#include <iostream>
#include <string>
#include <vector>
#include<raylib.h>
#include<chrono>
#include <thread>
#include "game.hpp"
#include "entities.hpp"





Game::Game(int p){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(width, height,this->windowname.c_str());
SetTargetFPS(FPS);
iterator = p;
std::vector<person> r;
std::atomic<bool> bit =true;

for(int e =0; e<iterator; e++)
 r.emplace_back();
for(person& k : r){
k.evoke();
} 

while(!WindowShouldClose()){
BeginDrawing();
ClearBackground(RAYWHITE);


for(std::size_t i = 0; i < r.size(); )
{
    r[i].draw();
    r[i].updatepos();
    r[i].randevents();
    r[i].alivechecker();

    if(!r[i].IsAlive)
    {
        r.erase(r.begin() + i);
    }
    else
    {
        i++;
    }
}

EndDrawing();
}

};
Game::~Game(){
    std::cout<<"tot ziens en dank je wel";
};

