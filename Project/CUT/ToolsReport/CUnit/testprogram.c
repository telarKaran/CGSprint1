
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stddef.h>
#include "header.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include "CUnit/Console.h"
int init_suite(void) 
{ 
	return 0;    //To Initialize the suite
}

int clean_suite(void) 
{
       	return 0;   //To uninitialize the suite after Unit Testing
}

void test_checkValidity(void)         //our test function 1
{
	char *str1 = "F001:Column values in BOM reports are incorrect:Aircraft design:BOM report:21/08/2022:open:fatal";
	char *str2 = "O001:Aircraft:BOM reports:21/08/2022:open:niceToHave";
	char *str3 = "N001:BOM report columns not alligned properly:Aircraft design:BOM report:21/08/2022:open:niceToHave";
	char *str4 = "F002:Unit prices are not shown while preparing invoice:Invoices:Display products:23/04/2022:close:fatal";
	CU_ASSERT(checkValidity(str1)==1);
	CU_ASSERT(checkValidity(str2)==0);
	CU_ASSERT(checkValidity(str3)==1);
	CU_ASSERT(checkValidity(str4)==1);
}

int main (void)     // Main function
{

	CU_pSuite pSuite1 = NULL;

	// Initialize CUnit test registry
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	// Add suite1 to registry
	pSuite1 = CU_add_suite("Basic_Test_Suite1", init_suite, clean_suite);
	if (pSuite1 == NULL) 
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	// add test1 to suite1
	if ((NULL == CU_add_test(pSuite1, "\n\n……… Testing test_checkValidity function……..\n\n", test_checkValidity)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}



	CU_basic_run_tests();// OUTPUT to the screen

	CU_cleanup_registry();//Cleaning the Registry
	
	return CU_get_error();

}
