#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Data2Bmp(unsigned int *, int, int);



int main(void)
{
	unsigned int a[65536];
	int i, k;
	for (i=0;i<65536;i++)
	{
		k=i*i+12*i-128;
		k=k%256;
		a[i]=((i%256)+k)%256;
	}
	Data2Bmp(a, 256, 256);
}



void Data2Bmp(unsigned int *Data, int Width, int Height){
	int i, j;
unsigned char bm[54]; //Массив для хранения заголовка
unsigned char * DataPic; //Массив для хранения картинки
FILE * out;
unsigned char R,G,B;
unsigned int D;
//Описание и инициализация переменных заголовка
char bfType[2]={'B','M'};
unsigned int bfSize= 54+Width*Height*3;
unsigned short bfReserved1=0;
unsigned short bfReserved2=0;
unsigned int bfOffBits=54;
unsigned int biSize=40;
unsigned int biWidth=Width;
unsigned int biHeight=Height;
unsigned short biPlanes=1;
unsigned short biBitCount=24;
unsigned int biCompression=0;
unsigned int biSizeImage= Width*Height*3;
unsigned int biXPixelsPreMeter=0;
unsigned int biYPixelsPreMeter=0;
unsigned int biClrUsed=0;
unsigned int biClrImportant=0;
//Заполнение массива с переменными заголовка
memcpy((void *)(bm + 0), (void*) (&bfType[0]), 2);
memcpy((void *)(bm + 2), (void*) (&bfSize), 4);
memcpy((void *)(bm + 6), (void*) (&bfReserved1), 2);
memcpy((void *)(bm + 8), (void*) (&bfReserved2), 2);
memcpy((void *)(bm +10), (void*) (&bfOffBits), 4);
memcpy((void *)(bm +14), (void*) (&biSize), 4);
memcpy((void *)(bm +18), (void*) (&biWidth), 4);
memcpy((void *)(bm +22), (void*) (&biHeight), 4);
memcpy((void *)(bm +26), (void*) (&biPlanes), 2);
memcpy((void *)(bm +28), (void*) (&biBitCount), 2);
memcpy((void *)(bm +30), (void*) (&biCompression), 4);
memcpy((void *)(bm +34), (void*) (&biSizeImage), 4);
memcpy((void *)(bm +38), (void*) (&biXPixelsPreMeter), 4);
memcpy((void *)(bm +42), (void*) (&biYPixelsPreMeter), 4);
memcpy((void *)(bm +46), (void*) (&biClrUsed), 4);
memcpy((void *)(bm +50), (void*) (&biClrImportant), 4);
if(Width%4!=0){
printf("Width\%4!=0\n");
exit(1);
}
DataPic = (unsigned char *)malloc(Width*Height*3);
if(DataPic==NULL){
printf("%s %s: Err_malloc\n", __FILE__, __FUNCTION__);
exit(2);
}
out = fopen("Data1.bmp","wb");
if(out==NULL){
printf("Data.bmp: Err_fopen\n");
exit(3);
}
for(i=0;i<Height;i++){
for(j=0;j<Width; j++){
D = Data[i*Width+j];
R = D%255;
G = (D/256)%255;
B = (D/256/256)%255;
DataPic[i*Width*3+3*j+0]= R;
DataPic[i*Width*3+3*j+1]= G;
DataPic[i*Width*3+3*j+2]= B;
}
}
fwrite((void*) bm,1,54,out);
fwrite((void*) DataPic,1,Height*Width*3,out);
fclose(out);
return;
}
