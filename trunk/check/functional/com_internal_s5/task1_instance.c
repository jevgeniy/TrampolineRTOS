/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_com_definitions.h"  //for E_COM_ID
#include "config.h" /*Display information in the right way (printf on UNIX...)*/

DeclareMessage(sm);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	int result_inst_1, result_inst_2;
	unsigned char car1;
	
	result_inst_1 = SendMessage(SEND_MESSAGE_COUNT, "1");	
	TEST_ASSERT_EQUAL_INT(E_COM_ID, result_inst_1);
	
	car1 = 1;
	result_inst_2 = SendMessage(sm, &car1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 2;
	result_inst_2 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 3;
	result_inst_2 = SendMessage(sm, &car1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 2;
	result_inst_2 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 1;
	result_inst_2 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 0;
	result_inst_2 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 1;
	result_inst_2 = SendMessage(sm, &car1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 2;
	result_inst_2 = SendMessage(sm, &car1);	
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
	
	car1 = 5;
	result_inst_2 = SendMessage(sm, &car1);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_2);
		
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}
