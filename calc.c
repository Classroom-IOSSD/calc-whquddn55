#include <stdio.h>
#include "operators.h"
#include "my_scanf.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result; 
	int line = 0;

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		my_scanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			my_scanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			double (*pointerOfFunction)(int, int);
			switch(operator) {
				case '+':
				pointerOfFunction = add;
				break;
				case '-':
				pointerOfFunction = minus;
				break;
				case '*':
				pointerOfFunction = mul;	
				break;
				case '/':
				pointerOfFunction = div;
				break;
			}		
			result = pointerOfFunction(operand1,operand2);
			printf("%d %c %d = %lf\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

