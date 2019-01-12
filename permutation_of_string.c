#include<string.h>
int k=0;
void swap(char *a,char *b)
{
  char temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
void permutations(char s[][100],char *str,int i,int n)
{
 
  int j;
  if(i==n)
  {
    strcpy(s[k],str);
    k++;
  }
  else
  {
   for(j=i;j<=n;j++)
   {
     swap((str+i),(str+j));
     permutations(s,str,i+1,n);
     swap((str+i),(str+j));
   }
  }
}
void printPermute(char *str)
{
char s[100][100];
int i,j;
int len=strlen(str);
  permutations(s,str,0,len-1);
  
  for(i=0;i<k;i++)
  {
    for(j=0;j<k-1;j++)
    {
      if(strcmp(s[j],s[j+1])>0){
      char d[100];
        strcpy(d,s[j]);
        strcpy(s[j],s[j+1]);
        strcpy(s[j+1],d);
      }
    }
  }
  for(i=0;i<k;i++)
  {
    printf("%s ",s[i]);
  }
  k=0;
}

