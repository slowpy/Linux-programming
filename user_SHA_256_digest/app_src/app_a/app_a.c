/*app_a.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char **argv)
{

    SHA256_CTX ctx;
    unsigned char results[SHA256_DIGEST_LENGTH];
    char out_digest[32*2+1]={0};
    int i;

    unsigned char data[10]={0};
    memset(data,'X',sizeof(data));

    SHA256_Init(&ctx);
    SHA256_Update(&ctx, (unsigned char *)data, sizeof(data));
    SHA256_Final(results, &ctx);

    for (i = 0; i < SHA256_DIGEST_LENGTH; i++){
		snprintf(out_digest+i*2,3,"%02x",results[i]);
    }

    printf("data:%s\n",data);
    printf("data SHA256 digest:%s\n", out_digest);
    return 0;
}
