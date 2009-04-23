/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1;
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_1 =  TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(4 , E_OK , result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq3_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}
