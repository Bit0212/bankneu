#include <iostream>
#include <string>
#include<vector>
#include <random>
#include <array>
#include <atomic>

std::random_device bd;
std::mt19937 gen(bd());

std::uniform_int_distribution dif(0,5);
std::uniform_int_distribution agi(13,50);
std::uniform_int_distribution cash(1450,15000);
std::uniform_int_distribution rndevents(0,3);
class person{
    public:
    std::array<std::string,6> potentialnames{"jose","pedro", "constantino", "manuel", "pedro", "energumeno"};
    std::string name;
    int age;
    double actualcash;
    int depressivestate;
    private:
    enum class potentialstates :int {
CashLoss,
CashGain,
AgeGain ,
DepressionWon,



    };
    // why atomic?: race conditions (just in case)
   inline static std::atomic<int>simcount =0;

    public: 
     person(){
        std::cout<<"i've been born today\n";


this->name =potentialnames[dif(gen)];
this->age =agi(gen); 
this->actualcash =cash(gen); 
this->depressivestate =0;
    }
~person(){
    std::cout<<"i'm dead at all, with this stats\n";
    std::cout<<this->name<<","<<this->age<<","<<this->actualcash<<","<<this->depressivestate<<"\n";



}    
void randevents(){
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




};


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
