//
// Created by fftest on 18-9-27.
//

#ifndef SAP_LOG_H
#define SAP_LOG_H
void sap_set_log_level(int level);

void sap_logp(void *ctx, int level,const char *file, const char *func, const char *fmtstr, ...);
#endif //SAP_LOG_H
