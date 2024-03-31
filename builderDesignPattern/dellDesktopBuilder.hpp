#ifndef DELLDESKTOPBUILDER_H
#define DELLDESKTOPBUILDER_H

#include "desktopBuilder.h"

class DellDesktopBuilder : public DesktopBuilder { 
    void buildMonitor();
    void buildKeyBoard();
    void buildMouse();
    void buildSpeaker();
    void buildRam();
    void buildProcessor();
    void buildMotherBoard();

};



#endif // !DELLDEKSTOPBUILDER_H