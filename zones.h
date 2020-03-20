#pragma once

/**
 * Looks up the POSIX string corresponding to the given tz database name
 * @param[in]   name   the tz database name for the timezone in question
 * @return             the POSIX string for the timezone in question
 **/
const char * posix_tz_db_get_posix_str(const char * name);
