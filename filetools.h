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

typedef struct SAPFileList{
    void *val;
    struct SAPFileList *last;
    struct SAPFileList *Next;
}SAPFileList;


SAPFileList* sap_file_list_alloc();

void sap_file_list_clear_and_free(SAPFileList *list);

int sap_file_list_add(SAPFileList *list, SAPFile *file);

int sap_file_list_add_at(SAPFileList *list, SAPFile *file, int index);

SAPFile* sap_file_list_get(SAPFileList *list, int index);

int sap_file_list_remove_at(SAPFileList *list, int index);

int sap_file_list_remove(SAPFileList *list, SAPFile *file);




SAPFile* sap_file_alloc();

int sap_file_tools_create(SAPFile *sapFile,char *url);

int sap_file_tools_find_all_file(SAPFile *SAPFile,SAPFileList *list);

int sap_file_read_song_info(SAPFile *file,SAPSong *song);

void sap_file_close(SAPFile *f);


#endif //SAP_FILETOOLS_H
