/*Instance 3 of task t5*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_newisdifferent);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t5_instance3(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_1 = ReceiveMessage(rm_newisdifferent, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(25,E_OK, result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,7, (int)received_char);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq6_t5_instance3(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t5_instance3",test_t5_instance3)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}