/*
 * DSTLIST.c
 *
 *  Created on: 15/10/2014
 *  Author: Aldo Rivera, Continuum Computer Technologies
 *
 *  Brief:
 * 		Prints out plain info (GMT times and offsets in seconds),
 * 		about current loaded DST table in a NonStop Server.
 *
 *  Compile Env:
 *      NSDEE 4 / H06.23 compiler env
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <cextdecs.h(DST_GETINFO_, INTERPRETTIMESTAMP)>
#include <zsysdefs/ZSYSC>  // must be donwloaded from NSK

#include "DSTLIST.h"

char* months[] = { "???", "JAN", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC", NULL };

int main ( int arc, char **argv )
{
  short       error = 0;
  long long   keyGMT = -1;

  zsys_ddl_dst_entry_def dstEntry;

  printf("RATSync/DSTLIST - DST listing program for NonStop Servers - T0000J06 - (15OCT2014)\n");
  printf("Copyright 2014 (c) Continuum Computer Technologies, S.L.\n\n");

  dstEntry.z_version = ZSYS_VAL_DST_VERSION_SEP1997;

  while (error == 0)
  {
      error = DST_GETINFO_ (keyGMT, (short*)&dstEntry);

      keyGMT = dstEntry.z_highgmt;

      if ((error == 0) || (error != ZSYS_VAL_DST_RANGE_HIGH))
      {
          short  gmt[8];

          INTERPRETTIMESTAMP(dstEntry.z_lowgmt, gmt);

          printf ("TRANSITION %.2d %s %.4d, %.2d:%.2d GMT, "
        		 , gmt[2], months[gmt[1]], gmt[0], gmt[3], gmt[4]);

          INTERPRETTIMESTAMP(dstEntry.z_highgmt, gmt);

          printf ("%.2d %s %.4d, %.2d:%.2d GMT, GMT + %d secs\n"
        		 , gmt[2], months[gmt[1]], gmt[0], gmt[3], gmt[4], dstEntry.z_offset);
       }
  }

  if (error != ZSYS_VAL_DST_RANGE_HIGH)
  {
      printf("*** ERROR result = %d\n", error);
  }

  return 0;
}
