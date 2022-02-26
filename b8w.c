/*******************************/
/*   Banner by nero 26.04.99   */
/*   Font 8x8                  */
/*******************************/

#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define fweite          8  /* Fontweite */
#define fhoehe          8  /* Fonthoehe */
#define anzchar        96  /* von dezimal 32 bis 126 alles Andere wird 95 */
#define maxcharperline 80

static FILE *mwfile = NULL;

int power(int base, int n);
void myWrite(char *format, ...);

int main (int argc,char *argv[]) {
  int i,j,k,l;
  char *arg = "DEINTEXT";
  (argv [1]) = arg;
  argc = 2;
  char string[100];
  unsigned char (mchar[anzchar][fhoehe]) = 
{
 /*   */   0,  0,  0,  0,  0,  0,  0,  0,
 /* ! */  48,120,120, 48, 48,  0, 48,  0,
 /* " */ 108,108,108,  0,  0,  0,  0,  0,
 /* # */ 108,108,254,108,254,108,108,  0,
 /* $ */  48,124,192,120, 12,248, 48,  0,
 /* % */   0,198,204, 24, 48,102,198,  0,
 /* & */  56,108, 56,118,220,204,118,  0,
 /* ' */  96, 96,192,  0,  0,  0,  0,  0,
 /* ( */  24, 48, 96, 96, 96, 48, 24,  0,
 /* ) */  96, 48, 24, 24, 24, 48, 96,  0,
 /* * */   0,102, 60,255, 60,102,  0,  0,
 /* + */   0, 48, 48,252, 48, 48,  0,  0,
 /* , */   0,  0,  0,  0,  0, 48, 48, 96,
 /* - */   0,  0,  0,252,  0,  0,  0,  0,
 /* . */   0,  0,  0,  0,  0, 48, 48,  0,
 /* / */   6, 12, 24, 48, 96,192,128,  0,
 /* 0 */ 124,198,206,222,246,230,124,  0,
 /* 1 */  48,112, 48, 48, 48, 48,252,  0,
 /* 2 */ 120,204, 12, 56, 96,204,252,  0,
 /* 3 */ 120,204, 12, 56, 12,204,120,  0,
 /* 4 */  28, 60,108,204,254, 12, 30,  0,
 /* 5 */ 252,192,248, 12, 12,204,120,  0,
 /* 6 */  56, 96,192,248,204,204,120,  0,
 /* 7 */ 252,204, 12, 24, 48, 48, 48,  0,
 /* 8 */ 120,204,204,120,204,204,120,  0,
 /* 9 */ 120,204,204,124, 12, 24,112,  0,
 /* : */   0, 48, 48,  0,  0, 48, 48,  0,
 /* ; */   0, 48, 48,  0,  0, 48, 48, 96,
 /* < */  24, 48, 96,192, 96, 48, 24,  0,
 /* = */   0,  0,252,  0,  0,252,  0,  0,
 /* > */  96, 48, 24, 12, 24, 48, 96,  0,
 /* ? */ 120,204, 12, 24, 48,  0, 48,  0,
 /* @ */ 124,198,222,222,222,192,120,  0,
 /* A */  48,120,204,204,252,204,204,  0,
 /* B */ 252,102,102,124,102,102,252,  0,
 /* C */  60,102,192,192,192,102, 60,  0,
 /* D */ 248,108,102,102,102,108,248,  0,
 /* E */ 254, 98,104,120,104, 98,254,  0,
 /* F */ 254, 98,104,120,104, 96,240,  0,
 /* G */  60,102,192,192,206,102, 62,  0,
 /* H */ 204,204,204,252,204,204,204,  0,
 /* I */ 120, 48, 48, 48, 48, 48,120,  0,
 /* J */  30, 12, 12, 12,204,204,120,  0,
 /* K */ 230,102,108,120,108,102,230,  0,
 /* L */ 240, 96, 96, 96, 98,102,254,  0,
 /* M */ 198,238,254,254,214,198,198,  0,
 /* N */ 198,230,246,222,206,198,198,  0,
 /* O */  56,108,198,198,198,108, 56,  0,
 /* P */ 252,102,102,124, 96, 96,240,  0,
 /* Q */ 120,204,204,204,220,120, 28,  0,
 /* R */ 252,102,102,124,108,102,230,  0,
 /* S */ 120,204,224,112, 28,204,120,  0,
 /* T */ 252,180, 48, 48, 48, 48,120,  0,
 /* U */ 204,204,204,204,204,204,252,  0,
 /* V */ 204,204,204,204,204,120, 48,  0,
 /* W */ 198,198,198,214,254,238,198,  0,
 /* X */ 198,198,108, 56, 56,108,198,  0,
 /* Y */ 204,204,204,120, 48, 48,120,  0,
 /* Z */ 254,198,140, 24, 50,102,254,  0,
 /* [ */ 120, 96, 96, 96, 96, 96,120,  0,
 /* \ */ 192, 96, 48, 24, 12,  6,  2,  0,
 /* ] */ 120, 24, 24, 24, 24, 24,120,  0,
 /* ^ */  16, 56,108,198,  0,  0,  0,  0,
 /* _ */   0,  0,  0,  0,  0,  0,  0,255,
 /* ` */  48, 48, 24,  0,  0,  0,  0,  0,
 /* a */   0,  0,120, 12,124,204,118,  0,
 /* b */ 224, 96, 96,124,102,102,220,  0,
 /* c */   0,  0,120,204,192,204,120,  0,
 /* d */  28, 12, 12,124,204,204,118,  0,
 /* e */   0,  0,120,204,252,192,120,  0,
 /* f */  56,108, 96,240, 96, 96,240,  0,
 /* g */   0,  0,118,204,204,124, 12,248,
 /* h */ 224, 96,108,118,102,102,230,  0,
 /* i */  48,  0,112, 48, 48, 48,120,  0,
 /* j */  12,  0, 12, 12, 12,204,204,120,
 /* k */ 224, 96,102,108,120,108,230,  0,
 /* l */ 112, 48, 48, 48, 48, 48,120,  0,
 /* m */   0,  0,204,254,254,214,198,  0,
 /* n */   0,  0,248,204,204,204,204,  0,
 /* o */   0,  0,120,204,204,204,120,  0,
 /* p */   0,  0,220,102,102,124, 96,240,
 /* q */   0,  0,118,204,204,124, 12, 30,
 /* r */   0,  0,220,118,102, 96,240,  0,
 /* s */   0,  0,124,192,120, 12,248,  0,
 /* t */  16, 48,124, 48, 48, 52, 24,  0,
 /* u */   0,  0,204,204,204,204,118,  0,
 /* v */   0,  0,204,204,204,120, 48,  0,
 /* w */   0,  0,198,214,254,254,108,  0,
 /* x */   0,  0,198,108, 56,108,198,  0,
 /* y */   0,  0,204,204,204,124, 12,248,
 /* z */   0,  0,252,152, 48,100,252,  0,
 /* { */  28, 48, 48,224, 48, 48, 28,  0,
 /* | */  24, 24, 24,  0, 24, 24, 24,  0,
 /* } */ 224, 48, 48, 28, 48, 48,224,  0,
 /* ~ */ 118,220,  0,  0,  0,  0,  0,  0,
 /*127*/   0, 16, 56,108,198,198,254,  0,
};

  for(j=1; j<argc; j++){
   if(strlen(argv[j])*fweite>maxcharperline)
    argv[j][maxcharperline/fweite]=0x00;
   for(l=0; l<fhoehe; l++){
    memset(string,0x00,sizeof(string));
    for(i=0; i<strlen(argv[j]); i++){
     if(argv[j][i]<32 || argv[j][i]>126)
      argv[j][i]=95;
     memset(&string[i*fweite],' ',fweite);
     for(k=0; k<fweite; k++)
     if( ((int)mchar[(argv[j][i])-32][l]&power(2,k))==power(2,k))
     switch (k) {
      case  0: string[i*fweite+k+7]=argv[j][i];break;
      case  1: string[i*fweite+k+5]=argv[j][i];break;
      case  2: string[i*fweite+k+3]=argv[j][i];break;
      case  3: string[i*fweite+k+1]=argv[j][i];break;
      case  4: string[i*fweite+k-1]=argv[j][i];break;
      case  5: string[i*fweite+k-3]=argv[j][i];break;
      case  6: string[i*fweite+k-5]=argv[j][i];break;
      case  7: string[i*fweite+k-7]=argv[j][i];break;
      default: string[i*fweite+k]=argv[j][i];break;
     }
    }
    printf("%s\n", string);
    myWrite("%s\r\n", string);
   }
  }
  return 0;
}
/*************************************/
int power(int base, int n) {
int p;
  for (p=1; n>0; --n)
   p=p*base;
  return p;
}
/*************************************/
void myWrite(char *format, ...)
{
	va_list argptr;

	if(mwfile==NULL)
	{
	  mwfile=fopen("b8out.txt", "ab");
	}
	
	va_start(argptr, format);
	vfprintf(mwfile, format, argptr);
	fflush(mwfile);
	va_end(argptr);
}
