#include <stdio.h>

void invert(char *str){
    char *start=str;
    char *end=str;
    char temp;
    while(*end!='\0'){
        end++;
    }
    end--;
    while(start<end){
        temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}
void invert_sub(char *start, int size) {
    if (size <= 1) return;
    char temp = start[size]; 
    start[size] = '\0';
    invert(start);
    start[size] = temp; 
}
void deslocar(char *str, int n){
    while(*str!='\0'){
        if(*str>='A' && *str<= 'Z'){
            *str=((*str-'A'+(n%26)+26)%26+'A');
        }
        else if(*str>='a' && *str<='z'){
            *str=((*str-'a'+(n%26)+26)%26+'a');
        }
        else if(*str>='0' && *str<='9'){
            *str=((*str-'0'+(n%10)+10)%10+'0');
        }
        str++;
    }
}
void trocarMetades(char *str){
    int tam=0;
    int half, i;
    char temp;
    char *ptr=str;
    while(*ptr!='\0'){
        tam++;
        ptr++;
    }
    if(tam<2) return;
    half=tam/2;
    char *p1=str;
    char *p2=str+half+(tam%2);
    for(i=0;i<half;i++){
        temp=*p1;
        *p1=*p2;
        *p2=temp;
        p1++;
        p2++;
    }
} 
void trocaParesImpares(char *str){
    char temp;
    char *p=str;
    if(str==NULL||*str=='\0'||*(str+1)=='\0') return;
    while(*p!='\0' && *(p+1)!='\0'){
        temp=*p;
        *p=*(p+1);
        *(p+1)=temp;
        p+=2;
    }

}
void inverterCaix(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';
        } else if (*str >= 'A' && *str <= 'Z') {
            *str = *str - 'A' + 'a';
        }
        str++;
    }
}
void rotacionar (char *str, int n){
    int len = 0;
    char *ptr = str;
    while(*ptr!='\0'){
        len++;
        ptr++;
    }
    if(len<=1) return;
    n = n % len;
    if(n<0){
        n+=len;
    }
    if(n==0) return;
    invert(str);
    invert_sub(str, n);
    invert_sub(str + n, len - n);

}


int main (){
    char str[10005];
    int N, n;
    scanf(" %[^\n]%*c", str);
    while(1){
        scanf("%d", &N);
        if(N==1){
            invert(str);
        }
        else if(N==2){
            scanf("%d", &n);
            deslocar(str, n);
        }
        else if(N==3){
            trocaParesImpares(str);
        }
        else if(N==4){
            invertercaix(str);
        }
        else if(N==5){
            scanf("%d", &n);
            rotacionar(str, n);
        }
        else if(N==6){
            trocarMetades(str);
        }
        else  break;
        
    }
    printf("%s\n", str);    

    return 0;
}
