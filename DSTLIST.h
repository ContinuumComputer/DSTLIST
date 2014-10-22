/* DSTTOOL.h
 *
 *
 */
#ifndef DSTTOOL_H
#define DSTTOOL_H


#pragma fieldalign shared2 __zsys_ddl_dst_entry
typedef struct __zsys_ddl_dst_entry
{
   long long                       z_lowgmt;
   long long                       z_highgmt;
   short                           z_offset;
   short                           z_version;
   __int32_t                       z_filler;
} zsys_ddl_dst_entry_def;

#endif /* DSTTOOL_H */
