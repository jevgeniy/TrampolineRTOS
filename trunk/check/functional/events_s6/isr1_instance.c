/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_kernel.h" /*for INVALID_TASK*/

DeclareEvent(Event1);
DeclareEvent(Event2);
DeclareTask(t1);
DeclareTask(t2);
DeclareTask(t3);
DeclareTask(t4);
DeclareTask(t5);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12;
	EventMaskType result_inst_0;
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_1 = GetEvent(INVALID_TASK, &result_inst_0);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_ID , result_inst_1);

	SCHEDULING_CHECK_INIT(7);
	result_inst_2 = GetEvent(t3, &result_inst_0);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_ACCESS , result_inst_2);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_3 = GetEvent(t4, &result_inst_0);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_STATE , result_inst_3);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_4 = GetEvent(t5, &result_inst_0);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK , result_inst_4);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_5 = GetEvent(t2, &result_inst_0);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK , result_inst_5);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_6 = SetEvent(INVALID_TASK, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OS_ID , result_inst_6);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_7 = SetEvent(t3, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_ACCESS , result_inst_7);

	SCHEDULING_CHECK_INIT(13);
	result_inst_8 = SetEvent(t4, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_STATE, result_inst_8);
	 
	SCHEDULING_CHECK_INIT(14);
	result_inst_9 = SetEvent(t1, Event2);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK , result_inst_9);

	SCHEDULING_CHECK_INIT(15);
	result_inst_10 = SetEvent(t1, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK , result_inst_10);
	 
	SCHEDULING_CHECK_INIT(16);
	result_inst_11 = SetEvent(t2, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK , result_inst_11);

	SCHEDULING_CHECK_INIT(17);
	result_inst_12 = SetEvent(t5, Event1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK , result_inst_12);
	
}

/*create the test suite with all the test cases*/
TestRef EventMechanismTest_seq6_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(EventMechanismTest,"EventMechanismTest_sequence6",NULL,NULL,fixtures);
	
	return (TestRef)&EventMechanismTest;
}