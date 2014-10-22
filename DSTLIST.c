/*
 * DSTLIST.c
 *
 *  Created on: 15/10/2014
 *      Author: Continuum Computer Technologies
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <tal.h>
#include <cextdecs.h>

#include <tnsint.h>
#include "DSTLIST.h"

#define ZSYS_VAL_DST_VERSION_SEP1997    1
#define ZSYS_VAL_DST_OK                 0
#define ZSYS_VAL_DST_SECURITY_ERROR     1
#define ZSYS_VAL_DST_BAD_VERSION        2
#define ZSYS_VAL_DST_BAD_PARAMETER      3
#define ZSYS_VAL_DST_INTERVAL_ERROR     4
#define ZSYS_VAL_DST_DELETE_NOW_ERROR   5
#define ZSYS_VAL_DST_TYPE_ERROR         6
#define ZSYS_VAL_DST_TABLE_EMPTY        7
#define ZSYS_VAL_DST_BOUNDS_ERROR       8
#define ZSYS_VAL_DST_RANGE_LOW          9
#define ZSYS_VAL_DST_RANGE_HIGH         10
#define ZSYS_VAL_DST_COUNT_OVERFLOW     11
#define ZSYS_VAL_DST_INTERNAL_ERROR     12


#define BOOL int
#define TRUE -1
#define FALSE 0

char* months[] = { "?0!", "JAN", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC", NULL };

int main ( int arc, char **argv )
{
  short       error = 0;
  long long   keyGMT = -1;

  zsys_ddl_dst_entry_def dstEntry;

  printf("RATSync/DSTLIST - DST listing program - TxxxxJ06 - (15OCT2014)\n");
  printf("(C) COPYRIGHT 2014 - Continuum Computer Technologies, S.L.\n\n");

  dstEntry.z_version = ZSYS_VAL_DST_VERSION_SEP1997;

  while (error == 0)
  {
      error = DST_GETINFO_ (keyGMT, (short*)&dstEntry);

      keyGMT = dstEntry.z_highgmt;

      if ((error == 0) || (error != ZSYS_VAL_DST_RANGE_HIGH))
      {
          short  gmt[8];

          INTERPRETTIMESTAMP(dstEntry.z_lowgmt, gmt);

          printf ("TRANSITION %.2d %s %.4d, %.2d:%.2d GMT, ",
              gmt[2], months[gmt[1]], gmt[0], gmt[3], gmt[4]);

          INTERPRETTIMESTAMP(dstEntry.z_highgmt, gmt);

          printf ("%.2d %s %.4d, %.2d:%.2d GMT, LST + %d secs\n",
              gmt[2], months[gmt[1]], gmt[0], gmt[3], gmt[4], dstEntry.z_offset);
       }
  }

  if (error != ZSYS_VAL_DST_RANGE_HIGH)
  {
      printf("result = %d\n", error);
  }

  return 0;
}
