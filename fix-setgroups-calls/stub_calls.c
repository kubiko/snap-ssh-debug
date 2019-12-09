#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int initgroups(const char *user, gid_t group) {
  return 0;
}

int setgroups(size_t size, const gid_t *list) {
  return 0;
}

int setresuid(uid_t ruid, uid_t euid, uid_t suid) {
  return 0;
}

int setresgid(gid_t rgid, gid_t egid, gid_t sgid) {
  return 0;
}
