#include "manager.h"
#include "SAPDefine.h"
#include <stdlib.h>


typedef struct SAP{
    SAPManager *manager;
}SAP;

SAP* sap_alloc(){
    SAP *ret = (SAP*)malloc(sizeof(SAP));

    return ret;
}

int sap_open(SAP *sap){
    RETIFNULL(sap) SAP_E_USE_NULL;

    sap->manager = sap_manager_alloc();
    RETIFNULL(sap->manager) SAP_E_NO_MEM;

    return SAP_OP_OK;
}

int sap_run(SAP *sap){
    RETIFNULL(sap) SAP_E_USE_NULL;
    RETIFNULL(sap->manager) SAP_E_USE_NULL;

    int ret = sap_manager_open(sap->manager);

    return  ret;
}

void sap_close(SAP *sap){

    RETIFNULL(sap);

    if(sap->manager){
        sap_manager_close(sap->manager);
    }
    free(sap);
}

int sap_main(int argc, char *argv[]){

    //for debug
    sap_set_log_level(SAPLOG_LEVEL_D);

    SAP *sap = sap_alloc();

    int ret = sap_open(sap);

    if(ret!=SAP_OP_OK){
        return  ret;
    }

    ret = sap_run(sap);
    if(ret!=SAP_OP_OK){
        return ret;
    }

    sap_close(sap);

    return 0;
}