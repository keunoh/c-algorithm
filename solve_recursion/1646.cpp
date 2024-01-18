#include <stdio.h>
#include <math.h>

int main(){
    long long ft[50];
    int i,n,s,e,a[51],b[51],pa=0,pb=0;

    for(i=2,ft[0]=1,ft[1]=1;i<50;i++)
        ft[i]=ft[i-1]+ft[i-2]+1;
    scanf("%d%d%d",&n,&s,&e);
    
    for(i=n-1,s--;s && i>=0;i--,s--){
        if(s>ft[i-1])
            s-=ft[i-1], a[pa++]=1;
        else
            i--, a[pa++]=0;
    }

    for(i=n-1,e--;e && i>=0;i--,e--){
        if(e>ft[i-1])
            e-=ft[i-1], b[pb++]=1;
        else
            i--,b[pb++]=0;
    }

    for(s=0;s<pa && s<pb;s++)
        if(a[s]!=b[s]) break;
    for(i=s;i<pa;i++) putchar('U');
    for(i=s;i<pb;i++) putchar(b[i]?'R':'L');
    putchar('\n');
}