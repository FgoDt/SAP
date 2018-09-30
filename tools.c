//
// Created by fftest on 18-9-28.
//

#include "tools.h"
#include "SAPDefine.h"
#include <string.h>
#include <stdlib.h>

int sap_str_cpy(char *dst, char *src){
    RETIFNULL(dst) SAP_E_USE_NULL;
    RETIFNULL(src) SAP_E_USE_NULL;

    int len = strlen(src);
    return sap_str_cpy_with_len(dst,src,len);

}

int sap_str_cpy_with_len(char *dst, char *src, int len){
    RETIFNULL(dst) SAP_E_USE_NULL;
    RETIFNULL(src) SAP_E_USE_NULL;

    if(len<=0)
        return SAP_E_ERROR_PAR;

    memcpy(dst,src,len);

    return SAP_OP_OK;

}

int sap_str_alloc_cpy(char **dst, char *src){
    RETIFNULL(src) SAP_E_USE_NULL;

    return sap_str_alloc_cpy_with_len(dst,src,strlen(src));
}

int sap_str_alloc_cpy_with_len(char **dst, char *src,int srclen){
    RETIFNULL(src) SAP_E_USE_NULL;

    if(*dst){
        free(*dst);
    }
    *dst= (char*)malloc(srclen+1);
    return  sap_str_cpy_with_len(*dst,src,srclen);

}
