#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	char lab[20][20];
	int i, j;
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++) lab[i][j]='.';
	}
	
	int port, x, y; 
	
	srand(time(NULL));
	
	for(i=0;i<20;i+=2){
		port=rand(); port=port%20; 
		for(j=0;j<20;j++){
			if(j==port) continue;
			else lab[i][j]='w';
		}
	}
	
	while(1){
		x=rand(); x=x%20; 
		y=rand(); y=y%20;
		if(lab[x][y]=='.'){
			lab[x][y]='b';
			break;
		}
	}
	
	while(1){
		x=rand(); x=x%20; 
		y=rand(); y=y%20;
		if(lab[x][y]=='.'){
			lab[x][y]='0';
			break;
		}
	}
	
	FILE *fp;
	fp=fopen("my_lab.maz", "w");
	
	for(i=0;i<20;i++){
		for(j=0;j<20;j++) fprintf(fp, "%c", lab[i][j] );
		fprintf(fp, "\n");
	}
	
	fclose(fp);
	return 0;
}
