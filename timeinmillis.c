#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

intmax_t time_in_ms(void) {
    long            ms; // Milliseconds
    time_t          s;  // Seconds
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    s  = spec.tv_sec;
    ms = round(spec.tv_nsec / 1e6); // Convert nanoseconds to milliseconds
    if (ms > 999) {
        s++;
        ms = 0;
    }

    return ((intmax_t) s * 1000 + ms);
}

int main() {
	printf("%"PRIdMAX"\n", time_in_ms());
	
	return 0;
}
