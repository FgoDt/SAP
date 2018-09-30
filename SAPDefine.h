//
// Created by fftest on 18-9-27.
//

#ifndef SAP_SAPDEFINE_H
#define SAP_SAPDEFINE_H

#include <stdio.h>
#include "log.h"



#define SAPLOG_LEVEL_E 0
#define SAPLOG_LEVEL_W 1
#define SAPLOG_LEVEL_D 2


#define SAPLOG(ctx,level,fmt) sap_logp(ctx,level,__FILE__,__FUNCTION__,fmt)
#define SAPLOG1(ctx,level,fmt,i) sap_logp(ctx,level,__FILE__,__FUNCTION__,fmt,i)
#define SAPLOG2(ctx,level,fmt,i,j) sap_logp(ctx,level,__FILE__,__FUNCTION__,fmt,i,j)
#define SAPLOG3(ctx,level,fmt,i,j,k) sap_logp(ctx,level,__FILE__,__FUNCTION__,fmt,i,j,k)

#define SAPLOGE(ctx,fmt) SAPLOG(ctx,SAPLOG_LEVEL_E,fmt)
#define SAPLOGW(ctx,fmt) SAPLOG(ctx,SAPLOG_LEVEL_W,fmt)
#define SAPLOGD(ctx,fmt) SAPLOG(ctx,SAPLOG_LEVEL_D,fmt)

#define SAPLE(fmt) SAPLOG(NULL,SAPLOG_LEVEL_E,fmt)
#define SAPLW(fmt) SAPLOG(NULL,SAPLOG_LEVEL_W,fmt)
#define SAPLD(fmt) SAPLOG(NULL,SAPLOG_LEVEL_D,fmt)

#define OPENMARK 0x12F3F2
#define SAPCTXISNULL(x) ((x)->openmark != OPENMARK)
#define RETIFCTXNULL(x) if(SAPCTXISNULL(x)) return
#define RETIFNULL(x) if((x) == NULL) return

#define SAP_SET_NULL(x) ((x) = NULL)

#define SAP_E_
#define SAP_OP_OK 0
#define SAP_E_AVLIB_ERROR -1
#define SAP_E_NO_MEM  -2
#define SAP_E_NO_MEDIAFILE -3
#define SAP_E_ERROR_PAR -4
#define SAP_E_USE_NULL -255
#define SAP_E_FATAL -0xfff
#define SAP_E_UNDEFINE -0xffff
#endif //SAP_SAPDEFINE_H
