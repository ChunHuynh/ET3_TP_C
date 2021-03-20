#include "names.h"
#include "num.h"
#include <math.h>

/*
TODO :

Test num
========

test mat mul tab : écrire 2 tableaux connus et vérifier que l'opération donne le bon résultat !

*/

const char* SEP = "==================================================";
const char* SEP2 = "##################################################";

void test_read_names();
void test_lower_case();
void test_upper_case();
void test_letter_to_num();
void test_bigger();
void test_smaller();
void test_compare();
void test_name_tab();

void wait_press(){
    printf("Press [Enter] key to continue.\n");
	// fflush(stdin); // option ONE to clean stdin
    while(getchar()!='\n'); // option TWO to clean stdin
    getchar(); // wait for ENTER
}

// Test if 2 floats are close enough. (This is needed because of float's bad precision)
int float_close(const float a, const float b){
	const float err = abs(a-b)/fmax(1e-15, fmin(abs(a), abs(b)));
	return err < 1e-5;
}

void test_fill_tab();
void test_add_tab();
void test_sub_tab();
void test_mul_tab();
void test_transpose();
void test_column_sum_tab();
void test_line_sum_tab();
void test_mat_mul_tab();

int main()
{
	
	// NAMES TESTING 
	// =============
	// test_read_names();
	test_lower_case();
	test_upper_case();
	test_letter_to_num();
	test_bigger();
	test_smaller();
	test_compare();
	// test_name_tab();
	
	wait_press();

	// NUM TESTING
	// ===========

	test_fill_tab();
	test_add_tab();
	test_sub_tab();
	test_mul_tab();
	test_transpose();
	wait_press();

	test_column_sum_tab();
	test_line_sum_tab();

	wait_press();
	test_mat_mul_tab();


	return 0;
}

void test_read_names(){
	printf("%s\n", SEP);
	printf("Test de read_name()\n");
	printf("%s\n", SEP);
	char* name = read_name();
	printf("Votre nom est : %s\n", name);
	printf("Vérifiez !\n");
	free(name);
}


void test_lower_case(){
	printf("%s\n", SEP);
	printf("Test de lower_case()\n");
	printf("%s\n", SEP);

	char* low_a = lower_case("LoWeR");
	printf("%s = lower ...", low_a);
	if(strcmp(low_a, "lower") == 0)
		printf("OK\n");
	else
		printf("FAILURE !\n");
	free(low_a);

	char* low_b = lower_case("mathew,;&");
	printf("%s = mathew,;& ...", low_a);
	if(strcmp(low_b, "mathew,;&") == 0)
		printf("OK\n");
	else
		printf("FAILURE !\n");
	free(low_b);

	char* low_c = lower_case("ABCD");
	printf("%s = abcd ...", low_a);
	if(strcmp(low_c, "abcd") == 0)
		printf("OK\n");
	else
		printf("FAILURE !\n");
	free(low_c);
}



void test_upper_case(){
	printf("%s\n", SEP);
	printf("Test de upper_case()\n");
	printf("%s\n", SEP);

	char* up_a = upper_case("uPpeR");
	printf("%s = UPPER ...", up_a);
	if(strcmp(up_a, "UPPER") == 0)
		printf("OK\n");
	else
		printf("FAILURE !\n");
	free(up_a);

	char* up_b = upper_case("MATHEW,;&");
	printf("%s = MATHEW,;& ...", up_a);
	if(strcmp(up_b, "MATHEW,;&") == 0)
		printf("OK\n");
	else
		printf("FAILURE !\n");
	free(up_b);

	char* up_c = upper_case("efgh");
	printf("%s = EFGH ...", up_a);
	if(strcmp(up_c, "EFGH") == 0)
		printf("OK\n");
	else
		printf("FAILURE !\n");
	free(up_c);
}

void test_letter_to_num(){
	printf("%s\n", SEP);
	printf("Test de letter_to_num()\n");
	printf("%s\n", SEP);

	int num = 0;

	num = letter_to_num('a');
	printf("rank(a) = %d ...", num);
	if(num==1)
		printf("OK\n");
	else
		printf("FAILURE !\n");

	num = letter_to_num('C');
	printf("rank(C) = %d ...", num);
	if(num==3)
		printf("OK\n");
	else
		printf("FAILURE !\n");
}

void test_bigger(){
	printf("%s\n", SEP);
	printf("Test de bigger()\n");
	printf("%s\n", SEP);

	int big = 0;
	big = bigger("A", "B");
	printf("A > B = FALSE");
	if (!big)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	big = bigger("BB", "B");
	printf("BB > B = TRUE");
	if (big)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");
	
	big = bigger("gaag", "aaga");
	printf("gaad > aaga = TRUE");
	if (big)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	big = bigger("babar", "babar");
	printf("babar > babar = TRUE");
	if (!big)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");
}


void test_smaller(){
	printf("%s\n", SEP);
	printf("Test de smaller()\n");
	printf("%s\n", SEP);

	int boolean = 0;
	boolean = smaller("Z", "H");
	printf("Z < H = FALSE");
	if (!boolean)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	boolean = smaller("TATA", "TATATA");
	printf("TATA < TATATA = TRUE");
	if (boolean)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");
	
	boolean = smaller("banana", "bonobo");
	printf("banana < bonobo = TRUE");
	if (boolean)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	boolean = smaller("plouf", "plouf");
	printf("plouf < plouf = TRUE");
	if (!boolean)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");
}

void test_compare(){
	printf("%s\n", SEP);
	printf("Test de compare()\n");
	printf("%s\n", SEP);

	int value = 0;
	value = compare("Z", "H");
	printf("compare(Z, H) = 1");
	if (value > 0)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	value = compare("TATA", "TATATA");
	printf("compare(TATA, TATATA) = -1");
	if (value < 0)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	value = compare("OOO", "OO");
	printf("compare(OOO, OO) = 1");
	if (value > 0)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");
	
	value = compare("banana", "bonobo");
	printf("compare(banana, bonobo) = -1");
	if (value < 0)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	value = compare("b", "b");
	printf("compare(b, b) = 0");
	if (value == 0)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");

	value = compare("superman", "superman");
	printf("compare(superman, superman) = 0");
	if (value == 0)
		printf("... OK\n");
	else
		printf("... FAILURE !\n");
}

void test_name_tab(){
	printf("%s\n", SEP);
	printf("Test de quicksort() & append()\n");
	printf("%s\n", SEP);

	char** tab = NULL;
	const size_t size = 4;
	for (size_t i = 0; i < size; ++i)
	{
		append(&tab, i, read_name());
	}
	for (size_t i = 0; i < size; ++i)
	{
		printf("name[%lu] = %s\n", i, tab[i]);
	}

	quicksort(tab, size);

	printf("%s\n", SEP);
	for (size_t i = 0; i < size; ++i)
	{
		printf("name[%lu] = %s\n", i, tab[i]);
	}
	
	for (size_t i = 0; i < size; ++i)
	{
		free(tab[i]);
	}
	free(tab);
}


void test_fill_tab(){
	printf("%s\n", SEP);
	printf("Test de fill_tab()\n");
	printf("%s\n", SEP);

	size_t size = 8;
	float * tab = malloc(size*sizeof(float));
	fill_tab(tab, size, 1.0);
	for (size_t i = 0; i < size; ++i)
	{
		if (!float_close(tab[i], 1.0)){
			printf("tab[%lu] != 1.0 (%f) ...FAILURE !\n", i, tab[i]);
			return;
		}
	}

	fill_tab(tab, size, -1.0);
	for (size_t i = 0; i < size; ++i)
	{
		if (!float_close(tab[i], -1.0)){
			printf("tab[%lu] != -1.0 (%f) ...FAILURE !\n", i, tab[i]);
			return;
		}
	}

	fill_tab(tab, size, -0.0562);
	for (size_t i = 0; i < size; ++i)
	{
		if (!float_close(tab[i], -0.0562)){
			printf("tab[%lu] != -0.0562 (%f) ...FAILURE !\n", i, tab[i]);
			return;
		}
	}

	free(tab);
	printf("OK\n");
}

void test_add_tab(){
	printf("%s\n", SEP);
	printf("Test de add_tab()\n");
	printf("%s\n", SEP);

	float tab_A[] = {1. , 2. , 5.};
	float tab_B[] = {5. , 2. , 3.5};
	float* tab_C = add_tab(tab_A, tab_B, 3);

	int fail = !float_close(tab_C[0], 6.0) && !float_close(tab_C[1], 4.0) && !float_close(tab_C[2], 8.5);
	free(tab_C);
	if (fail){
		printf("FAILURE\n");
		return;
	}
	else
		printf("OK\n");

}

void test_sub_tab(){
	printf("%s\n", SEP);
	printf("Test de sub_tab()\n");
	printf("%s\n", SEP);

	float tab_A[] = {1. , 2. , 5.};
	float tab_B[] = {5. , 2. , 3.5};
	float* tab_C = sub_tab(tab_A, tab_B, 3);

	int fail = !float_close(tab_C[0], -4.0) && !float_close(tab_C[1], 0.0) && !float_close(tab_C[2], 1.5);
	free(tab_C);
	if (fail){
		printf("FAILURE\n");
		return;
	}
	else
		printf("OK\n");
}

void test_mul_tab(){
	printf("%s\n", SEP);
	printf("Test de mul_tab()\n");
	printf("%s\n", SEP);

	float tab_A[] = {1. , 2. , 5.};
	float tab_B[] = {5. , 2. , 3.5};
	float* tab_C = mul_tab(tab_A, tab_B, 3);

	int fail = !float_close(tab_C[0], 5.0) && !float_close(tab_C[1], 4.0) && !float_close(tab_C[2], 17.5);
	free(tab_C);
	if (fail){
		printf("FAILURE\n");
		return;
	}
	else
		printf("OK\n");
}

void test_transpose(){
	printf("%s\n", SEP);
	printf("Test de transpose_2D()\n");
	printf("%s\n", SEP);

	float tab[] = {1,2,3, 4,5,6};
	float* tab_T = transpose_2D(tab, 2, 3);
	float tab_expected[] = {1,4, 2,5, 3,6};
	
	printf("initial table :\n");
	print_tab_2D(tab, 2, 3);
	printf("transpose table:\n");
	print_tab_2D(tab_T, 3, 2);

	int fail = 0;
	for (size_t i = 0; i < 6; ++i)
	{
		if (!float_close(tab_T[i], tab_expected[i])){
			fail = 1;
		}
	}

	free(tab_T);
	
	if (fail)
	{
		printf("FAILURE !\n");
	}
	else
		printf("OK\n");
}

void test_line_sum_tab(){
	printf("%s\n", SEP);
	printf("Test de line_sum_tab_2D()\n");
	printf("%s\n", SEP);

	float tab[] = {1,2,3, 4,5,6};
	float* tab_sum = line_sum_tab_2D(tab, 2, 3);
	float tab_expected[] = {6,15};

	printf("initial table :\n");
	print_tab_2D(tab, 2, 3);
	printf("line sum table :\n");
	print_tab(tab_sum, 2);

	int fail = 0;
	for (size_t i = 0; i < 2; ++i)
	{
		if (!float_close(tab_sum[i], tab_expected[i])){
			fail = 1;
		}
	}

	free(tab_sum);
	
	if (fail)
	{
		printf("FAILURE !\n");
	}
	else
		printf("OK\n");
}


void test_column_sum_tab(){
	printf("%s\n", SEP);
	printf("Test de column_sum_tab_2D()\n");
	printf("%s\n", SEP);

	float tab[] = {1,2,3, 4,5,6};
	float* tab_sum = column_sum_tab_2D(tab, 2, 3);
	float tab_expected[] = {5,7,9};

	printf("initial table :\n");
	print_tab_2D(tab, 2, 3);
	printf("column sum table :\n");
	print_tab(tab_sum, 3);

	int fail = 0;
	for (size_t i = 0; i < 3; ++i)
	{
		if (!float_close(tab_sum[i], tab_expected[i])){
			fail = 1;
		}
	}

	free(tab_sum);
	
	if (fail)
	{
		printf("FAILURE !\n");
	}
	else
		printf("OK\n");
}

void test_mat_mul_tab(){
	printf("%s\n", SEP);
	printf("Test de mat mul tab()\n");
	printf("%s\n", SEP);

	float tab_A[] = {1,2,3, 4,5,6};
	float tab_B[] = {6,5,4,3, 2,1,1,2, 3,4,5,6};
	float* tab_mul = mat_mul_tab_2D(tab_A, tab_B, 2, 3, 4);
	float tab_expected[] = {19,19, 21, 25, 52, 49, 51, 58};

	printf("initial table A :\n");
	print_tab_2D(tab_A, 2, 3);
	printf("initial table B :\n");
	print_tab_2D(tab_B, 3, 4);
	printf("mat mul table (A.B) :\n");
	print_tab_2D(tab_mul, 2, 4);

	int fail = 0;
	for (size_t i = 0; i < 8; ++i)
	{
		if (!float_close(tab_mul[i], tab_expected[i])){
			fail = 1;
		}
	}

	free(tab_mul);
	
	if (fail)
	{
		printf("FAILURE !\n");
	}
	else
		printf("OK\n");
}