/** @file example.c
 *  @brief An example usage of this timezone database mapping in an embedded system
 *
 *  @author Jacob Lambert
 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#include "zones.h"

void set_tz(const char *name) {
  setenv("TZ", posix_tz_db_get_posix_str(name), 1);
  tzset();
}

void print_local_time(const char *name) {
  time_t now;
  time(&now);
  struct tm timeinfo;
  char strftime_buf[64];
  set_tz(name);
  localtime_r(&now, &timeinfo);
  strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
  printf("The current date/time in %s is: %s\n", name, strftime_buf);
}

int main() {
  printf("Total library db size: %lu B\n", sizeof(posix_tz_db_tzs));
  print_local_time("America/New_York");
  print_local_time("Asia/Shanghai");
  print_local_time("Europe/Lisbon");
}