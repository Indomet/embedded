#include <stdio.h>

int contains_substring(const char *stringone, const char*substring);

int main()
{
const char stringone[] = "haeleaello";
const char substring[] = "ell";
int c = contains_substring(stringone,substring);
printf("%d", c);
    return 0;
}

int contains_substring(const char *stringone, const char*substring){
    int j;
    for(int i= 0; stringone[i]!='\0';i++){
        if(substring[0] ==stringone[i] ){
        for(j= 0; substring[j]!='\0'; j++){
            if(substring[j]!=stringone[i+j]){
                break;
            }
        } 
        if(substring[j] == '\0'){
            return i;
        }
        
        }

    }
    return -1;

}
