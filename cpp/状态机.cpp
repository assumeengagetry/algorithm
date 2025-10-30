#include<studio.h>
#include<char.h>
using namespace std;
int main(){
    
    int state=0;
    for(;;){
        int c=getchar();
        if(c=='\n') break;
        if(c==''''){
            if(state==0){
            putchar('`');
            putchar('`');
            state=1;
            }
        else{
            putchar('''');
            state=0;
        }
        continue;
        }
        
    }
}
int main(){
     for(;;){
 int c= getchar();
 while(c!='-1'&& c!=''''){
    putchar(c);
    c=getchar();
 } 
 if(c=='-1') break;
 printf('``');
 c=getchar();
 while(c!='-1'&& c!=''''){
    putchar(c);
    c=getchar();
 }
 if(c=='-1') break;
 printf('''');
    }
}