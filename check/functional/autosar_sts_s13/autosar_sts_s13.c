#include "Os.h"
#include "embUnit.h"
#include "config.h"

TestRef AutosarSTSTest_seq13_t1_instance(void);
TestRef AutosarSTSTest_seq13_t2_instance1(void);
TestRef AutosarSTSTest_seq13_t2_instance2(void);
TestRef AutosarSTSTest_seq13_t2_instance3(void);
TestRef AutosarSTSTest_seq13_t2_instance4(void);

StatusType instance_t2=0;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

TASK(t1)
{
	TestRunner_start();
	TestRunner_runTest(AutosarSTSTest_seq13_t1_instance());
	ShutdownOS(E_OK);
}

TASK(t2)
{
	instance_t2++;
	switch (instance_t2) {
		case 1 :
		{
			TestRunner_runTest(AutosarSTSTest_seq13_t2_instance1());
			break;
		}
		case 2 :
		{
			TestRunner_runTest(AutosarSTSTest_seq13_t2_instance2());
			break;
		}
		case 3 :
		{
			TestRunner_runTest(AutosarSTSTest_seq13_t2_instance3());
			break;
		}
		case 4 :
		{
			TestRunner_runTest(AutosarSTSTest_seq13_t2_instance4());
			break;
		}
		default:
		{
			stdimpl_print("instance error\n");
			break;
		}
	}
}