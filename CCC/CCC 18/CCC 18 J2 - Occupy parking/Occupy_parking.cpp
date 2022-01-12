#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int N, cont=0;
    char line1[101], line2[101];

    scanf("%d %s %s", &N, line1, line2);
    for (int i=0; i<N; i++){
        if ((line1[i] == 'C') && (line2[i] == 'C')){
            cont++;
        }
    }
    printf("%d", cont);
}
