#include<stdio.h>
#include<stdlib.h>
 
// Map[N0][N1] := Map[i*N1+j];
void initMap(unsigned char * r, unsigned char * g, unsigned char * b, int N0, int N1){
 int i, j;
for (i=0; i < N0; i++)
{
        for (j=0; j < N1; j++)
        {
                r[i*N1+j] = 0*rand() % 256;
                g[i*N1+j] = 0*rand() % 256;
                b[i*N1+j] = rand() % 256;
                }
}
return ;
}
 
 
int main(){
 
        unsigned char k;
 
        unsigned char signature[2] = { 'B', 'M' };
        unsigned int fileSize = 14 + 40 + 100*100*4;
        unsigned int reserved = 0;
        unsigned int offset = 14 + 40;
 
        unsigned int headerSize = 40;
        unsigned int dimensions[2] = { 100, 100 };
        unsigned short colorPlanes = 1;
        unsigned short bpp = 32;
        unsigned int compression = 0;
        unsigned int imgSize = 100*100*4;
        unsigned int resolution[2] = { 2795, 2795 }; //2795 ??????? ?? ???? (71ppi)
        unsigned int pltColors = 0;
        unsigned int impColors = 0;
        char * r;
        char * g;
        char * b;
        int N0;
        int N1;
 
        FILE * out;
        int i, j;
 
        out = fopen("out.bmp", "w");
        fwrite((void*)signature,sizeof(signature),1,out);
        fwrite((void*)&fileSize,sizeof(fileSize),1,out);
        fwrite((void*)&reserved,sizeof(reserved),1,out);
        fwrite((void*)&offset,sizeof(offset),1,out);
 
        fwrite((void*)&headerSize,sizeof(headerSize),1,out);
        fwrite((void*)dimensions,sizeof(dimensions),1,out);
        fwrite((void*)&colorPlanes,sizeof(colorPlanes),1,out);
        fwrite((void*)&bpp,sizeof(bpp),1,out);
        fwrite((void*)&compression,sizeof(compression),1,out);
        fwrite((void*)&imgSize,sizeof(imgSize),1,out);
        fwrite((void*)&resolution,sizeof(resolution),1,out);
        fwrite((void*)&pltColors,sizeof(pltColors),1,out);
        fwrite((void*)&impColors,sizeof(impColors),1,out);
 
 
        N0 = dimensions[0];
        N1 = dimensions[1];
        r = (char *)malloc(N0*N1);
        g = (char *)malloc(N0*N1);
        b = (char *)malloc(N0*N1);
 
 
 
initMap(r,g,b,N0,N1);
 

for (i=0; i < dimensions[1]; i++)
{
        for (j=0; j < dimensions[0]; j++)
        {
                k = 0;
                fwrite((void*)(&b[i*N1+j]),1,1,out);
                fwrite((void*)(&g[i*N1+j]),1,1,out);
                fwrite((void*)(&r[i*N1+j]),1,1,out);
                fwrite((void*)(&k),1,1,out);
                }
}
 
        fclose(out);
 
        return 0;
 
 
}
