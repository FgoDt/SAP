//
// Created by fftest on 18-9-27.
//

#ifndef SAP_PLAYER_H
#define SAP_PLAYER_H

typedef struct SAPPlayer{

}SAPPlayer;

SAPPlayer* sap_player_alloc();

int sap_player_init(SAPPlayer *player);

int sap_player_play(SAPPlayer *player);

int sap_player_pause(SAPPlayer *player);

int sap_player_stop(SAPPlayer *player);

int sap_player_seek(SAPPlayer *player,double time);

int sap_player_get_potion(SAPPlayer *player);

void sap_player_close(SAPPlayer *player);

#endif //SAP_PLAYER_H
