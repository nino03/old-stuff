#include <stdio.h>
#include <windows.h>

long filesize(FILE *stream)
{
long curpos, length=-1123;
curpos = ftell(stream);
fseek(stream,0L,SEEK_END);
length = ftell(stream);
fseek(stream, curpos, SEEK_SET);
return length;
}


int main(void)
{
FILE *hfile;
char *buf=0,*buf_1=0;

A:
hfile = fopen("1.txt", "rb");
	if(!hfile)
	{
	//printf("File open error");
	//return 0;
	Sleep(1000);
	goto A;
	}
//printf("File opened");
long size=filesize(hfile);
buf=new char[size];
buf_1=new char[size];
//fseek(hfile,size-30,0);
int x=fread(buf,size,1,hfile);
fclose(hfile);

//printf(masivi);
	for(int i=0;i<size;i++)
		buf_1[i]=buf[size-1-i];


hfile = fopen("1.txt", "w");
//fseek(hfile,10001,SEEK_SET);
//fseek(hfile,30,SEEK_END);
fwrite(buf_1,size,1,hfile);
fclose(hfile);


return 0;
}