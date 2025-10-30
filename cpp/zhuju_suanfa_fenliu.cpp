#include<stdio.h>
int main(){
    char k[]="QWERTYUIOP[]\ASDFGHJKL;ZXCVBNMMMMM,./";
    int len= strlen(k);
    for(;;){
        
        int c= getchar();
        int p=-1;
        for(int i=1; i< len; i++){
            if(c==k[i]){
                p=i;
            } 
        }
        if(p==-1) break;
        else{
            putchar(k[p-1]);
        }
    }

}