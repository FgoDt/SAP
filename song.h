//
// Created by fftest on 18-9-27.
//

#ifndef SAP_SONG_H
#define SAP_SONG_H

typedef struct SAPSong{

}SAPSong;

SAPSong* sap_song_alloc();

int sap_song_add_info(SAPSong *song);

int sap_song_close(SAPSong *song);

#endif //SAP_SONG_H
