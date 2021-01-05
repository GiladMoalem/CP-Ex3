#include <stdio.h>

#define Line 256 //chars in one line 
#define WORD 30//chars in one word

int getline1(char s[]){
int i=0;
char c = getchar();

while( c!=EOF && c!='\0' && c!='\n' && i < Line-1){
	s[i] = c;
	i++;
	c = getchar();
	}
s[i]='\0';
if(c==EOF) return EOF;
return i;
}

int getword(char word[]){
int i=0;
char c = getchar();
/*
while(c!=EOF && (c=='\n' || c=='\t' || c==' '))
	c = getchar();
*/
while(c!=EOF && c!='\0' && c!='\n' && c!='\t' && c!=' ' && i< WORD-1 && c!='\r'){
	word[i]=c;
	i++;
	c = getchar();
	}
word[i] = '\0';
if(c==EOF) return EOF;
return i;
}//

  int substring(char* str1, char* str2){
int i=0, j=0;
while( *(str2+j)!='\0' && *(str1+i)!='\0'){
  if(*(str2+j)==*(str1+i) ){
	j++;
  }else j=0;
  i++;
}
if(*(str2+j) == '\0') return 1;
return 0;
}//


int similar(char* t, char* s, int n){
int i=0,j=0;
  while(*(t+j)!= '\0' ){
if(*(t+j)==*(s+i)){
i++;
j++;
}else{
	if(n>0){
	n--;
	j++;
	}else return 0;
     }
  }
if(*(s+i)=='\0') return 1;
else return 0;
}

void print_lines(char *str){
char line[Line];
while(getline1(line)!=EOF){
if(substring(line,str))
  printf("%s\n", line );
}
}//

void print_similar_words(char* str){
char word[WORD];
while(getword(word)!=EOF){
if(similar(word,str,1)){
	printf("%s\n",word);
	}
}//while
}


int main(){

char serch[WORD];
getword(serch);
char option=getchar();

getchar();
getchar();

if(option=='a'){
print_lines(serch);
}

if(option=='b'){
print_similar_words(serch);
}

return 0;
}
