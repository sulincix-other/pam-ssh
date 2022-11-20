#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <config.h>

void ssh_authenticate(char* user, char* pass);

PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {
    char* user;
    pam_get_user(pamh,&user,NULL);
    char* pass;
    pam_get_authtok(pamh,PAM_AUTHTOK,&pass,NULL);
    
    ssh_authenticate(user,pass);

    return PAM_SUCCESS;
}
