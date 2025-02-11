#include<stdio.h>

int main(){
int x;
int y;
char op;
scanf("%i %c %i", &x, &op, &y);
if (op== '+'){
    printf("%i %c %i =%i\n", x, op, y, x+y);

}
if (op== '/'){
    printf("%i %c %i =%i\n", x, op, y, x/y);
    
}
if (op== '/'){
    float precise_result= (float)x/ (float)y;
    printf("%i %c %i =%f\n", x, op, y, precise_result);
    return 0;
}


}
