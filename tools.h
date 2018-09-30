//
// Created by fftest on 18-9-28.
//

#ifndef SAP_TOOLS_H
#define SAP_TOOLS_H

int sap_str_cpy(char *dst, char *src);

int sap_str_cpy_with_len(char *dst, char *src, int len);

int sap_str_alloc_cpy(char **dst, char *src);

int sap_str_alloc_cpy_with_len(char **dst, char *src,int srclen);

#endif //SAP_TOOLS_H
