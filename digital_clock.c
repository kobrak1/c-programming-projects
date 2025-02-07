/* digital clock with C programming language */
#include <stdlib.h>
#include <time.h> // to use the sleep() function
#include <stdio.h>
#include <unistd.h>

int main()
{
  int hour, minute, second;
  hour = minute = second = 0;

  while(1)
  {
    // clear output screen
    system("clear");
    printf("%02d : %02d : %02d", hour, minute, second);

    // print time in HH : MM : SS
    fflush(stdout);

    // increase second
    second++;

    // update hour minute and second
    if (second == 60)
    {
      minute++;
      second = 0;
    }

    if (minute == 60)
    {
      hour++;
      minute = 0;
      second = 0;
    }

    if (hour == 24)
    {
      hour = 0;
      minute = 0;
      second = 0;
    }

    // call sleep() to simulate 1 sec
    sleep(1);
  }
  return 0;
}
