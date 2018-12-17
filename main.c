//
// Created by fftest on 18-9-28.
//

#include "filetools.h"
#include "list.h"
#include <stdio.h>


int main(){

    SAPFile *file = sap_file_alloc();
    sap_file_tools_create(file,"helloc");



    SAPList *list = sap_list_alloc();
    list->custom_free = sap_file_close;
    SAPFile *fle = sap_file_alloc();
    sap_list_add(list,fle);
    sap_list_add(list,file);
    sap_list_clear_and_free(list);
    sap_list_remove_at(list,0);

    file = sap_file_alloc();
    sap_file_tools_create(file,"hellocccc");
    sap_list_add(list,file);


    for(list = list; list !=NULL; list = list->Next){
        printf("%s \n",((SAPFile*)list->val)->path);
    }

    getchar();

    return 0;
}