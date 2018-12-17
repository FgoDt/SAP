
#ifndef SAP_LIST_H
#define SAP_LIST_H

typedef struct SAPList{
    void *val;
    void (*custom_free)(void *val);
    struct SAPList *last;
    struct SAPList *Next;
}SAPList;

SAPList* sap_list_alloc();

void sap_list_clear_and_free(SAPList *list);

int sap_list_add(SAPList *list, void *file);

int sap_list_add_at(SAPList *list, void *file, int index);

void* sap_list_get(SAPList *list, int index);

int sap_list_remove_at(SAPList *list, int index);

int sap_list_remove(SAPList *list, void *file);

#endif