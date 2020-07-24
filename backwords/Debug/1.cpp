#include <stdio.h>

long filesize(FILE *stream)
{
long curpos, length;
curpos = ftell(stream);
fseek(stream,0L,SEEK_END);
length = ftell(stream);
fseek(stream, curpos, SEEK_SET);
return length;
}


int main(void)
{
FILE *hfile;
char masivi[4000]="1111111111111111112";
char a[128]="";

hfile = fopen("C:\\PROGR\\_PROJECTS\\IMG\\Nino\\4file\\file.exe", "a+");
//fseek(hfile,10001,SEEK_SET);
//fseek(hfile,30,SEEK_END);
fwrite(a,15,1,hfile);
fclose(hfile);

hfile = fopen("C:\\PROGR\\_PROJECTS\\IMG\\Nino\\4file\\file.exe", "rb");

long size=filesize(hfile);
fseek(hfile,size-30,0);
int x=fread(a,20,1,hfile);

//printf(masivi);
	for(int i=0;i<size;i++)
	putchar(a[size-i]);
fclose(hfile);
return 0;
}