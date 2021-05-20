#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *function(void *arg);
 
int main(int argc, char *argv[]){
    int ret = 10;
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1,NULL,function,(char*)"111");
    pthread_create(&thread2,NULL,function,(char*)"111");
//    pthread_join(thread1,NULL);
    pthread_detach(thread1);
    pthread_detach(thread2);
    while(1){
        int ret4 = 40;
    }
    return 0;	
}
 
void *function(void *arg){
    int f_ret = 20;
    int f_ret2 = 30;   
}
