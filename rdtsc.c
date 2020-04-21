
/* NOTE:
 *      compile with
 *      gcc -o rdtsc rdtsc.c -Wall -lrt
 */

/* required for printf() */
#include <stdio.h>
/* required for clock_gettime() */
#include <time.h>
/* required for gettimeofday() */
#include <sys/time.h>
#include <unistd.h>


/* Remember to update this with the actual speed of your CPU.
 * You can get it from the /proc/cpu file under linux. Just execute
 * $cat /proc/cpu
 */
#define CPU_SPEED ((long long)(350798000))

int main(int argc, char **argv) {

 long long start, end;

 asm volatile ("rdtsc" : "=A" (start) : : "memory");
 {struct timespec ts; clock_gettime(CLOCK_REALTIME, &ts);}
// {struct timeval tv; gettimeofday(&tv, NULL);}
// sleep(1);
 asm volatile ("rdtsc" : "=A" (end) : : "memory");

 printf("start = %lld, end = %lld, diff = %lld\n", start, end, end - start);
 printf("diff time = %f\n", (double)(end - start)/CPU_SPEED);

 return 0;
}

// Timestamp counter
// Counter increments with the same speed as CPU so its much more detailed and there is no loss of information
// With a simple conversion you calculate seconds.
// counter value is in Hz (?)
//