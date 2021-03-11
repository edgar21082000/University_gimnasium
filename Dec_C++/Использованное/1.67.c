#include <stdio.h>
#include <math.h>>

int main(){
	int m1, m2, m3;
	int p, p1, p2, p3;
	
	m1=0; m2=0; m3=0;
	int tmp;
	for(p=1;p<=3;p++){
		scanf("%d", &tmp);
		tmp = abs(tmp);
		if (tmp>=m3){
			if(tmp>=m2){
				if(tmp>=m1){
					m3 = m2;
					p3 = p2;
					
					m2 = m1;
					p2 = p1;
					
					m1 = tmp;
					p1 = p;
					continue;
				}
				else{
					m3 = m2;
					p3 = p2;
					
					m2=tmp;
					p2 = p;
					continue;
				}
			}
			else{
				m3 = tmp;
				p3 = p;
				continue;
			}
		}
	}
	//printf("max1 = %d | place = %d\nmax2 = %d | place = %d\nmax3 = %d | place = %d\n", m1 , p1, m2, p2, m3, p3);
	
	
	while(scanf("%d", &tmp)==1){
		tmp = abs(tmp);
		//printf("max1 = %d | place = %d\nmax2 = %d | place = %d\nmax3 = %d | place = %d\n", m1 , p1, m2, p2, m3, p3);
		if (tmp>=m3){
			if(tmp>=m2){
				if(tmp>=m1){
					m3 = m2;
					p3 = p2;
					
					m2 = m1;
					p2 = p1;
					
					m1 = tmp;
					p1 = p;
					
					p++;
					continue;
				}
				else{
					m3 = m2;
					p3 = p2;
					
					m2=tmp;
					p2 = p;
					
					p++;
					continue;
				}
			}
			else{
				m3 = tmp;
				p3 = p;
				p++;
				continue;
			}
		}
		p++;
	}
	
	printf("max1 = %d | place = %d\nmax2 = %d | place = %d\nmax3 = %d | place = %d\n", m1 , p1, m2, p2, m3, p3);
}



	
	//printf("max1 = %d | place = %d\nmax2 = %d | place = %d\nmax3 = %d | place = %d\n", m1 , p1, m2, p2, m3, p3);
	

