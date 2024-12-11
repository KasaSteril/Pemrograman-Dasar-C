#include <stdio.h>

int main (){
	float JariJariLingkaran, LuasLingkaran, KelilingLingkaran;
	
	printf("Masukkan jari-jari lingkaran: ");
	scanf("%f", &JariJariLingkaran);
	
	LuasLingkaran = (3.14159 * JariJariLingkaran * JariJariLingkaran);
	printf("Luas lingkaran: %.2f\n", LuasLingkaran);
	
	KelilingLingkaran = (2 * 3.14159 * JariJariLingkaran);
	printf("Keliling lingkaran: %.2f\n", KelilingLingkaran);
	
	return 0;
}