//
// Created by fftest on 18-9-27.
//

#ifndef SAP_PLAYLIST_H
#define SAP_PLAYLIST_H

#include "song.h"


typedef struct SAPSongList{
    SAPSong *song;
    struct SAPSongList *next;
}SAPSongList;

typedef struct SAPPlaylist{
    SAPSongList *songList;
    int count;
    char *name;
}SAPPlaylist;

SAPPlaylist* sap_playlist_alloc();

int sap_playlist_init(SAPPlaylist *list,char *name);

int sap_playlist_create_from_url(SAPPlaylist *list,char *url);

int sap_playlist_save_to_file(SAPPlaylist *list);

int sap_playlist_add(SAPPlaylist *list);

int sap_playlist_remove(SAPPlaylist *list);

int sap_playlist_close(SAPPlaylist *list);


#endif //SAP_PLAYLIST_H
