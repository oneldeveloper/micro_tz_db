#include "zones.h"
#include <string.h>

typedef struct {
    const char * name;
    const char * posix_str;
} posix_tz_db_pair;

// insert posix_tz_db_tzs here

const char * posix_tz_db_get_posix_str(const char * name)
{
  const posix_tz_db_pair * pair = posix_tz_db_tzs;
  while (pair->name) {
    if (0 == strcmp(pair->name, name)) {
      return pair->posix_str;
    }
    pair++;
  }
  return NULL;
}

unsigned long posix_tz_db_size()
{
  return sizeof(posix_tz_db_tzs);
}
