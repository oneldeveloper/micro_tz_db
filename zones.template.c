#include "zones.h"
#include <string.h>

const char * posix_tz_db_get_posix_str(const char * name)
{
  const posix_tz_db_pair * pair = posix_tz_db_tzs;
  while (pair->name) {
    if (0 == strcmp(pair->name, name)) {
      return pair->posix_str;
    }
  }
  return NULL;
}
