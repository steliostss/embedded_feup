
## How to compile the program for Raspberry
I am trying just for Raspberry 2B+. The aim of this is to get an kernel7.img file that will be inserted on SD card.

###  LdB-ECM / Raspberry-Pi
https://github.com/LdB-ECM/Raspberry-Pi/tree/master/FreeRTOSv10.1.1

1. git apt-get update
2. sudo apt-get install gcc-arm-none-eabi
3. cd Raspberry/FreeRTOSv10.1.1
4. For Pi2: make Pi2
For Pi3 in 32 Bit: make Pi3
For Pi3 in 64 Bit: make Pi3-64
5. make clean to clean the project

Trying on Ubuntu (not working in windows shell).
**Working on Raspberry.**

It compiles now this basic file with tasks:
https://github.com/LdB-ECM/Raspberry-Pi/blob/master/FreeRTOSv10.1.1/Demo/main.c

    #include <stdint.h>
    #include <string.h>
    #include "rpi-SmartStart.h"
    #include "emb-stdio.h"
    #include "FreeRTOS.h"
    #include "task.h"
    #include "rpi-Irq.h"
    #include "semphr.h"

    void main (void){
	    Init_EmbStdio(WriteText); // Initialize embedded stdio
	    PiConsole_Init(0, 0, 0, printf); // Auto resolution console, message to screen
	    displaySmartStart(printf); // Display smart start details
	    ARM_setmaxspeed(printf); // ARM CPU to max speed
	    printf("Task tick rate: %u\n", configTICK_RATE_HZ);
	    
	    /* Attempt to create a semaphore. */ 
	    vSemaphoreCreateBinary(barSemaphore);
	    if (barSemaphore != NULL)
	    {
		    /* The semaphore can now be used. Its handle is stored in the
		    xSemahore variable. Calling xSemaphoreTake() on the semaphore here
		    will fail until the semaphore has first been given. */
		    xSemaphoreGive(barSemaphore);
	    }
	    
	    xTaskCreate(task1, "HARE ", 2048, NULL, 4, NULL);
	    xTaskCreate(task2, "TURTLE", 2048, NULL, 4, NULL);
	    xTaskCreate(task3, "TIMER ", 2048, NULL, 3, NULL);
	    xTaskCreate(task4, "DETAIL", 2048, NULL, 2, NULL);
	    vTaskStartScheduler();
	    
	    /*
	    * We should never get here, but just in case something goes wrong,
	    * we'll place the CPU into a safe loop.
	    */
	    while (1) { }
    }

###  gchamp20 / RTOSBench 
https://github.com/gchamp20/RTOSBench,
The creater helped me on email to compile it:

1. git apt-get update
2. sudo apt-get install gcc-arm-none-eabi
3. cd Raspberry/RTOSBench
4. make mutex/round_robin EXAMPLE=freertos-rpi2 (all targets are in Makefile)

**Note**: after putting to Raspberry, it shows nothing (I am discussing that with the git repository owner)

