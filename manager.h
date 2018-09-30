//
// Created by fftest on 18-9-27.
//

#ifndef SAP_MANAGER_H
#define SAP_MANAGER_H

#include "playlist.h"
#include "player.h"

typedef struct SAPManager{
    SAPPlaylist *list;
    SAPPlayer *player;

}SAPManager;

SAPManager* sap_manager_alloc();

int sap_manager_open(SAPManager *m);


void sap_manager_close(SAPManager *m);

#endif //SAP_MANAGER_H
