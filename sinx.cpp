#include<stdio.h>
#include<math.h>
float fun(float x,int i){
	int n=1;
	int j;
	for(j=1;j<=i;j++){
		n*=j;
	}
	return pow(x,i)*pow(-1,i/2)*1.0/n;
}
int main(void){
	double sin=0;
	float x,t;
	int i=1;
	printf("ÊäÈë½Ç¶È£º");
	scanf("%f",&x);
	t = fun(x,i);
	while(fabs(t)>=10e-4){
		sin+=t;
		i+=2;
		t=fun(x,i);
	}

	printf("%f\n",sin);
	return 0;
	
	
}
