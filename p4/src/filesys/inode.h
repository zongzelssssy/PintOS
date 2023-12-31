#ifndef FILESYS_INODE_H
#define FILESYS_INODE_H

#include <stdbool.h>
#include "filesys/cache.h"
#include "filesys/off_t.h"
#include "devices/block.h"

/* Define some variable about inode */
#define TABLE_L 128
#define DIR_L 8
#define INDIR_L 32

#define DIR_SECTOR (DIR_L * BLOCK_SECTOR_SIZE)
#define INDIR_SECTOR (INDIR_L * BLOCK_SECTOR_SIZE)
#define TABLE_SECTOR (TABLE_L * BLOCK_SECTOR_SIZE)
#define MAX_SIZE (DIR_L * BLOCK_SECTOR_SIZE + TABLE_L * INDIR_L * BLOCK_SECTOR_SIZE)

struct bitmap;

void inode_init (void);
bool inode_create (block_sector_t, off_t);
struct inode *inode_open (block_sector_t);
struct inode *inode_reopen (struct inode *);
block_sector_t inode_get_inumber (const struct inode *);
void set_dir (struct inode *);
void inode_close (struct inode *);
void inode_remove (struct inode *);
off_t inode_read_at (struct inode *, void *, off_t size, off_t offset);
off_t inode_write_at (struct inode *, const void *, off_t size, off_t offset);
bool whether_is_dir (struct inode *);
int count_open_inode (struct inode *);
void inode_deny_write (struct inode *);
void inode_allow_write (struct inode *);
off_t inode_length (const struct inode *);

#endif /* filesys/inode.h */
