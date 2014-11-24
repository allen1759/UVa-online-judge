#include <cstdio>

int main()
{
    char wer[4][15]= {"`1234567890-=",
                      "QWERTYUIOP[]\\",
                      "ASDFGHJKL;\'",
                      "ZXCVBNM,./"
                     };
    char ch;
    while(scanf("%c", &ch)!=EOF)
    {
        if(ch==' ' || ch=='\n')
            printf("%c", ch);
        else{
            for(int i=0; i<4; i++){
                for(int j=0; j<15; j++){
                    if(ch=='\0') break;
                    if(ch==wer[i][j])
                        printf("%c", wer[i][j-1]);
                }
            }
        }
    }
    return 0;
}
