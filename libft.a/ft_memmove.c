#include <stdio.h>
#include <stddef.h>

void *memmove(void *dst, const void *src, size_t len){
    unsigned char tmp_dst;
    const unsigned char tmp_src;

    tmp_dst = (unsigned char)dst;
    tmp_src = (const unsigned char)src;
    if(tmp_dst > tmp_src){
        while(len--){
            *tmp_dst = *tmp_src;
            tmp_dst++;
            tmp_src++;
        }
    }else{
        *tmp_dst += (len - 1);
        *tmp_src += (len - 1);
        while(len--){
            *tmp_dst = *tmp_src;
            tmp_dst--;
            tmp_src--;
        }
    }
    return (dst);
}