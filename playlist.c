//
// Created by fftest on 18-9-27.
//
#include "playlist.h"
#include "SAPDefine.h"
#include <stdlib.h>
#include <string.h>

#define DEFAULT_NAME "MUSIC"

SAPPlaylist* sap_playlist_alloc(){
    SAPPlaylist *playlist = (SAPPlaylist*)malloc(sizeof(SAPPlaylist));
    RETIFNULL(playlist) NULL;
    playlist->songList = NULL;
    playlist->count = 0;
    playlist->name = NULL;
    return playlist;
}

int sap_playlist_init(SAPPlaylist *list,char *name){
    RETIFNULL(list) SAP_E_USE_NULL;
    char *listname = DEFAULT_NAME;
    if(name != NULL){
        listname = name;
    }
    list->name = malloc(strlen(listname)+1);
    memset(list->name,0,strlen(listname)+1);
    memcpy(list->name,listname,strlen(listname));
    return SAP_OP_OK;
}


int sap_playlist_create_from_url(SAPPlaylist *list,char *url){
    RETIFNULL(list) SAP_E_USE_NULL;
}

int sap_playlist_save_to_file(SAPPlaylist *list);

int sap_playlist_add(SAPPlaylist *list);

int sap_playlist_remove(SAPPlaylist *list);

int sap_playlist_close(SAPPlaylist *list);