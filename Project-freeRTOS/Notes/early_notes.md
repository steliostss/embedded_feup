# Benchmarking freeRTOS

This file holds notes about benchmarking of freeRTOS for the project of Embedded Systems of FEUP (2019--2020)

# Features to measure / evaluate based on code / scenarios:

1. Interrupt latency time (considered even though it is based on uC architectural design) 
2. Context switch time
3. Kernel Computation to Communication Ratio (CCR) consumption
4. Kernel API performance 

## INTERRUPT LATENCY TIME: 

Intention of this measurement is to identify minimal interrupt latency time. 

### Test code

1.    Configure two IO pins (TestPin1, TestPin2) as described below: 

      a. TestPin1 as output mode.
      b. TestPin2 as external interrupt port with falling edge detection option. So default state is HIGH.

2.    Create a task which sets TestPin1 as always LOW.
3.    Create an external interrupt ISR, set TestPin1 as HIGH. 

### Measurement method

1.    Connect TestPin1, TestPin2 ports to DSO channel 2, channel 1 respectively. 
2.    Give falling edge trigger to TestPin2 port.
3.    Measure time difference between interrupt generated time (HIGH to LOW transition at TestPin2) and time at which start executing the first instruction in the ISR (LOW to HIGH transition at TestPin1). 

## CONTEXT SWITCH TIME :

Context switch can be triggered by different sources like external interrupt, kernel services, timer interrupt etc., So, different methods are available to measure context switch time. For evaluation purpose, two methods are identified and average of those measurements is considered as context switch time. 

### Method_1: tick ISR to TASK switch 

#### Test code

1.    Configure one IO pin (TestPin1) as output mode.

2.    Configure a hardware timer as 8ms interval timer, which is used as system tick.

3.    Add the following code in “8ms interval timer” ISR function:

      a. Set TestPin1 as HIGH at the start of ISR function.

Rationale: “freeRTOS” kernel designed in such a way that scheduler function (it ensures that which task to run next) is called from tick ISR routine. So, this tick is executed every 8ms and it switched back to always with high priority task. So, task switch time is time taken to execute scheduler function and also switching time from tick ISR to high priority task.  

4.    Create one task which makes TestPin1 as always LOW.

#### Measurement method

1.    Connect TestPin1 port to DSO channel 1. 
2.    Measure CRO channel 1 out waveform. Calculate context switching time using below formula:

Context switch time = tab – X

tab – Time taken to execute complete tick ISR function and also switching back to high priority task.
X    – Time taken to execute tick increment function. So this must be measured separately using test pin toggling method with tick increment function.  

### Method_2: TASK to TASK switch using a Kernel services (vTaskSuspend ( ), vTaskResume ( ))

#### Test code

1.    Configure one IO pin (TestPin1) as output mode.

2.    Create two tasks as described below:

      a. Task1: “HighPrioTask” with priority 4.
      b. Task2: “LowPrioTask” with priority 3.

3.    Add the following code in “HighPrioTask”:
a. Suspend “HighPrioTask” task.
b. Set TestPin1 as HIGH

4.    Add the following code in “LowPrioTask”:
a. Give 2 ms delay.
b. Set TestPin1 as LOW and then HIGH (Toggle it once)
c. Set TestPin1 as LOW
d. Resume “HighPrioTask” task.

#### Measurement method

1.    Connect TestPin1 port to DSO channel 0. 
2.    Measure CRO channel 0 out waveform. 

Time taken from step 4.c to step 3.b is called as context switch time.



> he have to pay attention to average and maximum time which are the most interesting. 
>
> to measure max time we have 



# Memory Management of freeRTOS

### Why do queues use that much RAM?

Event management is built into the queue functionality. This means the queue data structures contain all the RAM that other RTOS systems sometimes allocate separately. There is no concept of an event control block within FreeRTOS.