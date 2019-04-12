#ifndef DOS_H
#define DOS_H

#include <stdint.h>


#define DOSCALL  call 5
#define BIOSCALL ld iy,(EXPTBL-1)\
call CALSLT


/* SYSTEM vars */
#define EXPTBL #0xFCC1

/* DOS calls */
// MSXDOS 1
#define CONIN   #0x01
#define CONOUT  #0x02
#define CONST   #0x0b
#define CURDRV  #0x19
#define SETDTA  #0x1A
#define FILESIZ #0x23
// MSXDOS 2
#define DPARM   #0x31
#define FFIRST  #0x40
#define FNEXT   #0x41
#define OPEN    #0x43
#define CREATE  #0x44
#define CLOSE   #0x45
#define READ    #0x48
#define WRITE   #0x49
#define SEEK    #0x4A
#define IOCTL   #0x4B
#define DELETE  #0x4D
#define GETCD   #0x59
#define PARSE   #0x5B
#define TERM    #0x62
#define EXPLAIN #0x66
#define GENV    #0x6B
#define DOSVER  #0x6F
// Nextor
#define FOUT    #0x71
#define RDDRV   #0x73
#define WRDRV   #0x74


/* DOS errors */
#define NOFIL   0xD7
#define IATTR   0xCF
#define DIRX    0xCC

/* open/create flags */
#define O_RDWR     0x00
#define O_RDONLY   0x01
#define O_WRONLY   0x02
#define O_INHERIT  0x04

/* seek modes */
#define SEEK_SET	0	//Beginning of file
#define SEEK_CUR	1	//Current position of the file pointer
#define SEEK_END	2	//End of file *

/* file attributes */
#define ATTR_READ_ONLY (1)
#define ATTR_DIRECTORY (1 << 4)
#define ATTR_ARCHIVE   (1 << 5)

/*
	MSX-DOS Call Errors
*/
#define ERR_ISBFN   0xb8	//Invalid sub-function number: The sub-function number passed to the IOCTL function (function 4Bh) was invalid.
#define ERR_EOL     0xb9	//Internal error should never occur.
#define ERR_HDEAD   0xba	//File handle has been deleted: The file associate with a file handle has been deleted so the file handle can no longer be used.
#define ERR_NRAMD   0xbb	//RAM disk does not exist: Attempt to delete the RAM disk when it does not currently exist. A function which tries to access a non-existent RAM disk will get a .IDRV error.
#define ERR_RAMDX   0xbc	//RAM disk (drive H:) already exists: Returned from the "ramdisk" function if trying to create a RAM disk when one already exists.
#define ERR_ITIME   0xbd	//Invalid time: Time parameters passed to "set time" are invalid.
#define ERR_IDATE   0xbe	//Invalid date: Date parameters passed to "set date" are invalid.
#define ERR_ELONG   0xbf	//Environment string too long: Environment item name or value string is either longer than the maximum allowed length of 255, or is too long for the user's buffer.
#define ERR_IENV    0xc0	//Invalid environment string: Environment item name string contains an invalid character.
#define ERR_IDEV    0xc1	//Invalid device operation: Attempt to use a device file handle or fileinfo block for an invalid operation such as searching in it or moving it.
#define ERR_NOPEN   0xc2	//File handle not open: The specified file handle is not currently open.
#define ERR_IHAND   0xc3	//Invalid file handle: The specified file handle is greater than the maximum allowed file handle number.
#define ERR_NHAND   0xc4	//No spare file handles: Attempt to open or create a file handle when all file handles are already in use. There are 64 file handles available in the current version.
#define ERR_IPROC   0xc5	//Invalid process id: Process id number passed to "join" function is invalid.
#define ERR_ACCV    0xc6	//File access violation: Attempt to read or write to a file handle which was opened with the appropriate access bit set. Some of the standard file handles are opened in read only or write only mode.
#define ERR_EOF     0xc7	//End of file: Attempt to read from a file when the file pointer is already at or beyond the end of file.
#define ERR_FILE    0xc8	//File allocation error: The cluster chain for a file was corrupt. Use CHKDSK to recover as much of the file as possible.
#define ERR_OV64K   0xc9	//Cannot transfer above 64K: Disk transfer area would have extended above 0FFFFh.
#define ERR_FOPEN   0xca	//File already in use: Attempt to delete, rename, move, or change the attributes or date and time of a file which has a file handle already open to it, other than by using the file handle itself.
#define ERR_FILEX   0xcb	//File exists: Attempt to create a sub-directory of the same name as an existing file. Files are not automatically deleted when creating sub-directories.
#define ERR_DIRX    0xcc	//Directory exists: Attempt to create a file or sub-directory of the same name as an existing sub-directory. Sub-directories are not automatically deleted.
#define ERR_SYSX    0xcd	//System file exists: Attempt to create a file or sub-directory of the same name as an existing system file. System files are not automatically deleted.
#define ERR_DOT     0xce	//Invalid . or .. operation: Attempt to do an illegal operation on the "." or ".." entries in a sub-directory, such as rename or move them.
#define ERR_IATTR   0xcf	//Invalid attribute: Can result from an attempt to change a file's attributes in an illegal way, or trying to do an operation on a file which is only possible on a sub-directory. Also results from illegal use of volume name fileinfo blocks.
#define ERR_DIRNE   0xd0	//Directory not empty: Attempt to delete a sub-directory which is not empty.
#define ERR_FILRO   0xd1	//Read only file: Attempt to write to or delete a file which has the "read only" attribute bit set.
#define ERR_DIRE    0xd2	//Invalid directory move: Results from an attempt to move a sub-directory into one of its own descendants. This is not allowed as it would create an isolated loop in the directory structure.
#define ERR_DUPF    0xd3	//Duplicate filename: Results from "rename" or "move" if the destination filename already exists in the destination directory.
#define ERR_DKFUL   0xd4	//Disk full: Usually results from a write operation if there was insufficient room on the disk for the amount of data being written. May also result from trying to create or extend a sub-directory if the disk is completely full.
#define ERR_DRFUL   0xd5	//Root directory full: Returned by "create" or "move" if a new entry is required in the root directory and it is already full. The root directory cannot be extended.
#define ERR_NODIR   0xd6	//Directory not found: Returned if a directory item in a drive/path/file string could not be found.
#define ERR_NOFIL   0xd7	//File not found: Can be returned by any function which looks for files on a disk if it does not find one. This error is also returned if a directory was specified but not found. In other cases, .NODIR error (see below) will be returned.
#define ERR_PLONG   0xd8	//Pathname too long: Can be returned by any function call which is given an ASCIIZ drive/path/file string. Indicates that the complete path being specified (including current directory if used) is longer than 63 characters.
#define ERR_IPATH   0xd9	//Invalid pathname: Can be returned by any function call which is given an ASCIIZ drive/path/file string. Indicates that the syntax of the string is incorrect in some way.
#define ERR_IFNM    0xda	//Invalid filename: A filename string is illegal. This is only generated for pure filename strings, not drive/path/file strings.
#define ERR_IDRV    0xdb	//Invalid drive: A drive number parameter, or a drive letter in a drive/path/file string is one which does not exist in the current system.
#define ERR_IBDOS   0xdc	//Invalid MSX-DOS call: An MSX-DOS call was made with an illegal function number. Most illegal function calls return no error, but this error may be returned if a "get previous error code" function call is made.
#define ERR_NORAM   0xde	//Not enough memory: MSX-DOS has run out of memory in its 16k kernel data segment. Try reducing the number of sector buffers or removing some environment strings. Also occurs if there are no free segments for creating the RAMdisk.
#define ERR_INTER   0xdf	//Internal error: Should never occur.


typedef struct {
	uint8_t  drvnum;		//     DE+0      - Physical drive number (1=A: etc)
	uint16_t secSize;		//     DE+1,2    - Sector size (always 512 currently)
	uint8_t  secClus;		//     DE+3      - Sectors per cluster (non-zero power of 2)
	uint16_t resvSec;		//     DE+4,5    - Number of reserved sectors (usually 1)
	uint8_t  numFats;		//     DE+6      - Number of copies of the FAT (usually 2)
	uint16_t rootNum;		//     DE+7,8    - Number of root directory entries
	uint16_t totalSec16;	//     DE+9,10   - Total number of logical sectors | NEXTOR: (0h fill)
	uint8_t  mediaDesc;		//     DE+11     - Media descriptor byte
	uint8_t  secFat;		//     DE+12     - Number of sectors per FAT (0=256)
	uint16_t rootSec;		//     DE+13..14 - First root directory sector number
	uint16_t dataSec;		//     DE+15..16 - First data sector number
	uint16_t maxClus;		//     DE+17..18 - Maximum cluster number
	uint8_t  dirtyFlag;		//     DE+19     - Dirty disk flag
	uint16_t volId;			//     DE+20..23 - Volume id. (-1 => no volume id)
	uint32_t totalSec32;	//     DE+24..27 - Reserved (0h fill) | NEXTOR: Logical sectors as a 32 bit value
	uint8_t  fsType;		//     DE+28     - Reserved (0h fill) | NEXTOR: Filesystem type (0:FAT12 1:FAT16 255:Other)
	uint8_t  reserved[3];	//     DE+29..31 - Reserved (0h fill)
} DPARM_info;	// Disk drive parameters info


char get_screen_size(void);

int getchar(void);
int putchar(int c);
void cputs(char *s);
int cprintf(const char *format, ...);
int kbhit(void);

char get_current_drive(void);
char get_current_directory(char drive, char *path);
char get_drive_params(char drive, DPARM_info *param);

uint16_t fopen(char *fn, char mode);
uint8_t  fclose(char fp);
uint16_t fcreate(char *fn, char mode, char attributes);
uint16_t remove(char *file);
uint16_t fread(char* buf, unsigned int size, char fp);
uint16_t fwrite(char* buf, unsigned int size, char fp);
uint32_t fseek (char fp, uint32_t offset, char origin);
char fileexists(char *filename);

int parse_pathname(char volume_name_flag, char* s);
void exit(int code);
char dosver(void);
void explain(char* buffer, char error_code);
char get_env(char* name, char* buffer, char buffer_size);

void set_transfer_address(uint8_t *memaddress);
char read_abs_sector_drv(uint8_t drv, uint32_t startsec, uint8_t nsec);
char write_abs_sector_drv(uint8_t drv, uint32_t startsec, uint8_t nsec);


#endif