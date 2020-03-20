## What is it?

An embeddable mapping between [IANA Time Zone Database](https://www.iana.org/time-zones) names
(like "America/New_York" and "China/Shanghai") and their equivalent [POSIX `"TZ"` rule descriptions](https://www.freebsd.org/cgi/man.cgi?query=tzset)
(like "EST5EDT,M3.2.0,M11.1." and "CST-8").

In this way, more user-friendly names can be used in a timezone-setting API, and
timezone rules can be easily updated with a firmware upgrade.

Provide user-facing clients with `zones.json` to have a shared timezone vocabulary with the embedded library.
