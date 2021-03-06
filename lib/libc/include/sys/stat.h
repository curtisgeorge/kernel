#pragma once

#include <sys/types.h>
#include <time.h>

#define S_IRWXU 0700
#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IXUSR 0100
#define S_IRWXG 070
#define S_IRGRP 040
#define S_IWGRP 020
#define S_IXGRP 010
#define S_IRWXO 07
#define S_IROTH 04
#define S_IWOTH 02
#define S_IXOTH 01
#define S_ISUID 04000
#define S_ISGID 02000
#define S_ISVTX 01000

#define S_ISBLK(m)  0
#define S_ISCHR(m)  0
#define S_ISDIR(m)  0
#define S_ISFIFO(m) 0
#define S_ISREG(m)  0
#define S_ISLNK(m)  0
#define S_ISSOCK(m) 0

# define st_atime st_atim.tv_sec
# define st_mtime st_mtim.tv_sec
# define st_ctime st_ctim.tv_sec

struct stat {
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  off_t st_size;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  blksize_t st_blksize;
  blkcnt_t st_blocks;
};

struct stat64 {
  dev_t st_dev;
  ino_t st_ino;
  mode_t st_mode;
  nlink_t st_nlink;
  uid_t st_uid;
  gid_t st_gid;
  dev_t st_rdev;
  off_t st_size;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  blksize_t st_blksize;
  blkcnt_t st_blocks;
};

int    chmod(const char*, mode_t);
int    fchmod(int, mode_t);
int    fstat(int, struct stat*);
int    fstat64(int, struct stat64*);
int    lstat(const char*, struct stat*);
int    lstat64(const char*, struct stat64*);
int    mkdir(const char*, mode_t);
int    mkfifio(const char*, mode_t);
int    mknod(const char*, mode_t, dev_t);
int    stat(const char*, struct stat*);
int    stat64(const char*, struct stat64*);
mode_t umask(mode_t);
