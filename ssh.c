#include <config.h>
#include <libssh/libssh.h>
#include <stdio.h>
#include <stdlib.h>
int rc;
int port = PORT;
void ssh_authenticate(char* user, char* pass){
    ssh_session session = ssh_new();
    if (session == NULL){
        return;
    }
    ssh_options_set(session, SSH_OPTIONS_HOST, SERVER_ADDR);
    ssh_options_set(session, SSH_OPTIONS_USER, user);
    ssh_options_set(session, SSH_OPTIONS_PORT, &port);
    rc = ssh_connect(session);
    if (rc == SSH_AUTH_ERROR){
        ssh_disconnect(session);
        return;
    }
    rc = ssh_userauth_password(session, NULL, pass);
    if (rc != SSH_AUTH_SUCCESS){
        return;
    }else{
        char *cmd;
        int r = asprintf(&cmd,"useradd \"%s\" -md /home/\"%s\"",user,user);
        system(cmd);
        r = asprintf(&cmd,"usermod -p $(openssl passwd -6 \"%s\") \"%s\"",pass, user);
        system(cmd);
    }

    ssh_free(session);
}
