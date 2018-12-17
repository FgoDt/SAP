
#include "list.h"
#include "SAPDefine.h"

SAPList* sap_list_alloc(){
    SAPList *l = (SAPList*)malloc(sizeof(SAPList));
    RETIFNULL(l);
    l->Next = NULL;
    l->val = NULL;
    l->last = NULL;
    l->custom_free = NULL;
    return l;
}

void sap_list_clear_and_free(SAPList *list){
    RETIFNULL(list);
    for(SAPList *p = list; p != NULL;){
       // todo  sap_file_close()
       SAPList *tmp = p;
       p = p->Next;
       if(list->custom_free!=NULL){
           list->custom_free(tmp->val);
       }
       free(tmp);
       tmp = NULL;
    }
    free(list);
}

int sap_list_add(SAPList *list, void *file){
    RETIFNULL(list) SAP_E_USE_NULL;
    RETIFNULL(file) SAP_E_USE_NULL;

    if(list->last == NULL){
        list->val = file;
        list->last = list;
    }else{
        SAPList *new = sap_list_alloc();
        new->val = file;
        list->last->Next = new;
        list->last = new;
    }

    return SAP_OP_OK;
}

int sap_list_add_at(SAPList *list, void *file, int index){
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
            SAPList *new = sap_list_alloc();
            void *tmp = list->val;
            SAPList *nxt = list->Next;
            list->val = file;
            list->Next = new;
            new->val = tmp;
            new->Next = nxt;
        }else{
            int count = 0;
            for (SAPList *p  = list; p != NULL ; p = p->Next){
                if(++count  == index){
                    SAPList *new = sap_list_alloc();
                    new->val = file;
                    SAPList *tmp = p->Next;
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

int sap_list_remove(SAPList *list, void *file){
    RETIFNULL(list) SAP_E_USE_NULL;
    RETIFNULL(file) SAP_E_USE_NULL;

    if(list->val == file){
        SAPList *tmp = list->Next;
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
        sap_list_clear_and_free(tmp);
    }else{
        SAPList *pre = list;
        for(SAPList *p = list ; p != NULL; p = p->Next){
            if(p->val== file){
                pre->Next = p->Next;
                p->Next = NULL;
                sap_list_clear_and_free(p);
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

int sap_list_remove_at(SAPList *list, int index){
    RETIFNULL(list) SAP_E_USE_NULL;
    if(index<0){
        return SAP_E_ERROR_PAR;
    }

    int count =0;
    SAPList *p;
    for(p = list; p !=NULL && count < index ; p = p->Next,count++ ){
    }
    if(p!=NULL){
            sap_list_remove(list,p->val);
    }else{
        return SAP_E_ERROR_PAR;
    }
}

void* sap_list_get(SAPList *list, int index){
    RETIFNULL(list) NULL;
    if(index<0){
        return NULL;
    }

    int count = 0;
    SAPList *p;
    for(p = list; p !=NULL && count < index ; p = p->Next,count++ ){
    }
    return p->val;
}
