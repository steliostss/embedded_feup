# IMAGE test files for Raspberry

I am also putting the outputs from console to these files.

### Important notes
- it has just MAX and MIN, for average we need to *create a script* that parses the file and takes all t1-t2 and makes the average number @todo 

- the program was ran several times (not just once!) so for the statistics we need to take some average values or exclude the nonsence one...

- the most important is to understand what are the timers t1,t2 

- if the t1/t2 number is negative just take -t1/-t2 (they also do it in the code)

- note/question: for round robin I am running it now with 2 tasks, is it a problem?

#### Done test
- round_robin
- sem
- sem_prio
- sem_processing
- mutex
- mutex_pip
- mutex_processing
- mutex_workload
- mq
- mq_workload
- mq_processing

- event\* missing in test folder!
- interrupt_processing is giving no results!
- jitter is also giving no results!

