  /* Standard includes. */
#include <stdio.h>
#include <conio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "scheduler.h"

TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;
TaskHandle_t xHandle3 = NULL;
TaskHandle_t xHandle4 = NULL;
/*-----------------------------------------------------------*/


static void testFunc1(void* pvParameters) {
	char* c = pvParameters;
	printf("Test1 %c\r\n", *c);

	int i, a = 0;
	for (i = 0; i < 1000000; i++)
	{
		a = 1 + i * i * i * i;
	}
}


int stopc = 0;
static void testFunc2(void* pvParameters)
{
	char* c = pvParameters;
	int i, a;
	for (i = 0; i < 1000000; i++)
	{
		a = 1 + i * i * i * i;
	}
	printf("Test2 %c\r\n", *c);

	if (stopc == 3)
	{
		//vSchedulerAperiodicJobCreate(testFuncA1, "A1", "A1-2", pdMS_TO_TICKS(100));
	}
	if (stopc == 5)
	{
		/*if (pdFALSE == xSchedulerSporadicJobCreate(testFuncS1, "S1", "S1-2", pdMS_TO_TICKS(100), pdMS_TO_TICKS(1000)))
		{
			printf("Sporadic job S1 not accepted tick %d\r\n", xTaskGetTickCount());
		}*/
	}
	stopc++;
}

static void testFunc3(void* pvParameters) {
	char* c = pvParameters;
	printf("Test3 %c\r\n", *c);
	int i, a = 0;
	for (i = 0; i < 1000000; i++)
	{
		a = 1 + a * a * i;
	}
}

static void testFunc4(void* pvParameters)
{
	char* c = pvParameters;
	int i, a = 0;
	for (i = 0; i < 2000000; i++)
	{
		a = 1 + i * i * i * i;
	}
	printf("Test4 %c\r\n", *c);
}


/*** SEE THE COMMENTS AT THE TOP OF THIS FILE ***/
void main_tasks(void)
{
    printf("Main tasks loaded\n");
    //const TickType_t xTimerPeriod = mainTIMER_SEND_FREQUENCY_MS;

    vSchedulerInit();
    char c1 = 'a';
    char c2 = 'b';
    char c3 = 'c';
    char c4 = 'e';

    TaskHandle_t TH1 = NULL;
    vSchedulerPeriodicTaskCreate(testFunc1, "t1", configMINIMAL_STACK_SIZE, &c1, 1, &xHandle1, pdMS_TO_TICKS(0), pdMS_TO_TICKS(200), pdMS_TO_TICKS(100), pdMS_TO_TICKS(500));
    vSchedulerPeriodicTaskCreate(testFunc2, "t2", configMINIMAL_STACK_SIZE, &c2, 2, &xHandle2, pdMS_TO_TICKS(50), pdMS_TO_TICKS(100), pdMS_TO_TICKS(100), pdMS_TO_TICKS(100));
    vSchedulerPeriodicTaskCreate(testFunc3, "t3", configMINIMAL_STACK_SIZE, &c3, 3, &xHandle3, pdMS_TO_TICKS(0), pdMS_TO_TICKS(300), pdMS_TO_TICKS(100), pdMS_TO_TICKS(200));
    vSchedulerPeriodicTaskCreate(testFunc4, "t4", configMINIMAL_STACK_SIZE, &c4, 4, &xHandle4, pdMS_TO_TICKS(0), pdMS_TO_TICKS(400), pdMS_TO_TICKS(100), pdMS_TO_TICKS(100));

    /*xTaskCreate(testFunc1, "t1", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_SEND_TASK_PRIORITY, NULL);
    xTaskCreate(testFunc2, "t2", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_SEND_TASK_PRIORITY, NULL);
    xTaskCreate(testFunc3, "t3", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_SEND_TASK_PRIORITY, NULL);
    xTaskCreate(testFunc4, "t4", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_SEND_TASK_PRIORITY, NULL);*/

    /* Start the tasks and timer running. */
    vSchedulerStart();
    //vTaskStartScheduler();

    /* If all is well, the scheduler will now be running, and the following
line will never be reached.  If the following line does execute, then
there was insufficient FreeRTOS heap memory available for the idle and/or
timer tasks	to be created.  See the memory management section on the
FreeRTOS web site for more details. */
    for (;; );
}
/*-----------------------------------------------------------*/




