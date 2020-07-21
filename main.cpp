#include "Engine.h"


int main()
{
    bool a=true;
    while(a){
    Engine obj;
    obj.init();
    obj.MenuEvents();
    obj.initGame();
    obj.GameEvents();
    }
    return 0;
}

