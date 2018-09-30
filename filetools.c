//
// Created by fftest on 18-9-28.
//

#include "filetools.h"
#include <stdlib.h>
#include <string.h>
#include "SAPDefine.h"
#include "tools.h"

SAPFile* sap_file_alloc(){
    SAPFile *sapFile = (SAPFile*)malloc(sizeof(SAPFile));
    RETIFNULL(sapFile) NULL;

    sapFile->fileType = SAP_FILE_ERROR;
    sapFile->path = NULL;
    return  sapFile;
}

int sap_file_tools_create(SAPFile *sapFile,char *url){
    RETIFNULL(sapFile) SAP_E_USE_NULL;
    RETIFNULL(url) SAP_E_USE_NULL;

    sap_str_alloc_cpy(&sapFile->path,url);

    


}

int sap_file_read_song_info(SAPFile *file,SAPSong *song);

int sap_file_close();