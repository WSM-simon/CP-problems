#include <stdio.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x= (x<<3)+(x<<1)+_-'0');}while(0)
char _;

#include <string.h>


int main(int argc, char* argv[])
{
	int N;
	scan(N);
	char name[1000];
	int p;
	int max = -1;
	char winner[1000];

	for (int i = 0; i < N; ++i)
	{
		scanf("%s\n%d", name, &p);
		if (p > max)
		{
			max = p;
			strcpy(winner, name);
		}
	}
	printf("%s", winner);
}