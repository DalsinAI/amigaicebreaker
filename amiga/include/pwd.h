/* IceBreaker for AmigaOS: libnix has no pwd.h, and icebreaker.c includes it
 * (its getpwuid() is not called here: the name and the drawer are set
 * without it). From the Team's Mirror Magic port.
 * The AmiCradle Team. GPL 2 or later, like IceBreaker. */
#ifndef AMIGA_PWD_H
#define AMIGA_PWD_H
#include <sys/types.h>
struct passwd {
	char *pw_name;
	char *pw_passwd;
	uid_t pw_uid;
	gid_t pw_gid;
	char *pw_gecos;
	char *pw_dir;
	char *pw_shell;
};
static inline struct passwd *getpwuid(uid_t uid) { (void)uid; return 0; }
#endif
