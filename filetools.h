//
// Created by fftest on 18-9-28.
//

#ifndef SAP_FILETOOLS_H
#define SAP_FILETOOLS_H

#include "song.h"

typedef enum SAPFileType{
    SAP_FILE_ERROR,
    SAP_FILE_DIR,
    SAP_FILE_MUSIC_FILE,
    SAP_FILE_CONFIG_FILE,
    SAP_FILE_PLAY_LIST_FILE
}SAPFileType;

typedef struct SAPFile{
    SAPFileType fileType;
    char *path;
}SAPFile;

SAPFile* sap_file_alloc();

int sap_file_tools_create(SAPFile *sapFile,char *url);

int sap_file_read_song_info(SAPFile *file,SAPSong *song);

int sap_file_close();


#endif //SAP_FILETOOLS_H
