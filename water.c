#include <stdlib.h>
#include <stdio.h>

int Area(int * height, int a, int b) {
	int AREA = height[a] > height[b] ? (height[b] * (b-a)) : (height[a] * (b-a));
	return AREA;
}

int maxArea(int * height, int heightSize) {
	int a = 0;
	int b = heightSize-1;
	int h = Area(height, a,b);
	int newH;

	while (b > a) {

		if (height[a] > height[b]) {
			b = b-1;
		} else {
			a = a+1;
		}

		newH = Area(height,a,b);
		if (newH > h) {
			h = newH;
		}

	}

	return h;

}

int bruteForce(int * height, int heightSize) {
	int h, newH;
	h = 0;

	for (int i = 0; i < heightSize; i++) {
		for (int j = i+1; j < heightSize; j++) {
			newH = Area(height,i,j);
			if (newH > h) {
				h = newH;
			}
		}
	}

	return h;
}

int main() {
	int a [] = {2,6,2,6,23,4,7,213, 123, 523,1 ,141 ,1, 1,11,6,8};
	printf("H: %d.\n",maxArea(a,11));	
	printf("H: %d.\n",bruteForce(a,11));	
}
