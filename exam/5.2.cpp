#include<stdio.h>
#include<ctype.h>>
#include<string.h>
int alpha=0, num=0, space=0, other=0;
void solve(char *a) {
  for(int i=0;i<strlen(a);++i) {
    if(isdigit(a[i])) num++;
    else if (isalpha(a[i])) alpha++;
    else if (isspace(a[i])) space++;
    else other++;
  }
}
int main(void) {
  char a[100]; gets(a); solve(a);
  printf("character count is: %d\n"
         "number count is: %d\n"
         "space count is: %d\n"
         "other character count is: %d\n",
         alpha, num, space, other);

  return 0;
}
