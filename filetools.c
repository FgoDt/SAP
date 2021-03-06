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

    return SAP_OP_OK;
}

int sap_file_tools_find_all_file(SAPFile *SAPFile,SAPFileList *list){
    RETIFNULL(SAPFile);
    RETIFNULL(list);

    
}

int sap_file_read_song_info(SAPFile *file,SAPSong *song);

void sap_file_close(SAPFile *f){
    RETIFNULL(f);
    if(f->path!=NULL){
        free(f->path);
    }
    free(f);
}


SAPFileList* sap_file_list_alloc(){
    SAPFileList *l = (SAPFileList*)malloc(sizeof(SAPFileList));
    RETIFNULL(l);
    l->Next = NULL;
    l->val = NULL;
    l->last = NULL;
    return l;
}

void sap_file_list_clear_and_free(SAPFileList *list){
    RETIFNULL(list);
    for(SAPFileList *p = list; p != NULL;){
       // todo  sap_file_close()
       SAPFileList *tmp = p;
       p = p->Next;
       free(tmp);
       tmp = NULL;
    }
    free(list);
}

int sap_file_list_add(SAPFileList *list, SAPFile *file){
    RETIFNULL(list) SAP_E_USE_NULL;
    RETIFNULL(file) SAP_E_USE_NULL;

    if(list->last == NULL){
        list->val = file;
        list->last = list;
    }else{
        SAPFileList *new = sap_file_list_alloc();
        new->val = file;
        list->last->Next = new;
        list->last = new;
    }

    return SAP_OP_OK;
}

int sap_file_list_add_at(SAPFileList *list, SAPFile *file, int index){
    RETIFNULL(list) SAP_E_USE_NULL;
    if(index<0){
        return SAP_E_ERROR_PAR;
    }

    if(list->last == NULL){
        if(index!=0) 
            return SAP_E_ERROR_PAR;
        list->val = file;
        list->last = list;
    }else{
        if(index == 0){
            SAPFileList *new = sap_file_list_alloc();
            SAPFile *tmp = list->val;
            SAPFileList *nxt = list->Next;
            list->val = file;
            list->Next = new;
            new->val = tmp;
            new->Next = nxt;
        }else{
            int count = 0;
            for (SAPFileList *p  = list; p != NULL ; p = p->Next){
                if(++count  == index){
                    SAPFileList *new = sap_file_list_alloc();
                    new->val = file;
                    SAPFileList *tmp = p->Next;
                    p->Next = new;
                    new->Next = tmp;
                    if(tmp == NULL){
                        list->last = new;
                    }
                    break;
                }
            }
            if(count<index){
                return SAP_E_ERROR_PAR;
            }

        }
    }

    return SAP_OP_OK;

}

int sap_file_list_remove(SAPFileList *list, SAPFile *file){
    RETIFNULL(list) SAP_E_USE_NULL;
    RETIFNULL(file) SAP_E_USE_NULL;

    if(list->val == file){
        SAPFileList *tmp = list->Next;
        if(tmp==NULL){
            //to do sap_file_close();
            list->val = NULL;
            list->Next = NULL;
            list->last = NULL;
            return SAP_OP_OK;
        }
        list->val = tmp->val;
        list->Next = tmp->Next;
        tmp->Next = NULL;
        sap_file_list_clear_and_free(tmp);
    }else{
        SAPFileList *pre = list;
        for(SAPFileList *p = list ; p != NULL; p = p->Next){
            if(p->val== file){
                pre->Next = p->Next;
                p->Next = NULL;
                sap_file_list_clear_and_free(p);
                if(pre->Next == NULL){
                    list->last = pre;
                }
                return SAP_OP_OK;
            }
            pre = p;
        }
    }

    return SAP_OP_OK;
}

int sap_file_list_remove_at(SAPFileList *list, int index){
    RETIFNULL(list) SAP_E_USE_NULL;
    if(index<0){
        return SAP_E_ERROR_PAR;
    }

    int count =0;
    SAPFileList *p;
    for(p = list; p !=NULL && count < index ; p = p->Next,count++ ){
    }
    if(p!=NULL){
            sap_file_list_remove(list,p->val);
    }else{
        return SAP_E_ERROR_PAR;
    }
}

SAPFile* sap_file_list_get(SAPFileList *list, int index){
    RETIFNULL(list) NULL;
    if(index<0){
        return NULL;
    }

    int count = 0;
    SAPFileList *p;
    for(p = list; p !=NULL && count < index ; p = p->Next,count++ ){
    }
    return p->val;
}
