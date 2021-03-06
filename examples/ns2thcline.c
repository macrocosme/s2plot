/* ns2thcline.c
 *
 * Copyright 2006-2012 David G. Barnes, Paul Bourke, Christopher Fluke
 *
 * This file is part of S2PLOT.
 *
 * S2PLOT is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S2PLOT is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S2PLOT.  If not, see <http://www.gnu.org/licenses/>. 
 *
 * We would appreciate it if research outcomes using S2PLOT would
 * provide the following acknowledgement:
 *
 * "Three-dimensional visualisation was conducted with the S2PLOT
 * progamming library"
 *
 * and a reference to
 *
 * D.G.Barnes, C.J.Fluke, P.D.Bourke & O.T.Parry, 2006, Publications
 * of the Astronomical Society of Australia, 23(2), 82-93.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "s2plot.h"

int main(int argc, char *argv[])
{
   float x1, y1, z1;				/* Start of line */
   float x2, y2, z2;				/* End of line */
   float r1, g1, b1;				/* Colour of line segment (start) */
   float r2, g2, b2;				/* Colour of line segment (end) */
   float size;					/* Thickness of line */
   int N = 10;					/* Number of lines */
   int i;					/* Loop variable */

   srand48((long)time(NULL));			/* Seed random numbers */
   s2opend("/?",argc, argv);			/* Open the display */
   s2swin(-1.,1., -1.,1., -1.,1.);		/* Set the window coordinates */
   s2box("BCDET",0,0,"BCDET",0,0,"BCDET",0,0);	/* Draw coordinate box */

   s2sci(S2_PG_YELLOW);				/* Set colour */
   for (i=0;i<N;i++) {
      x1 = drand48()*2.0 - 1.0;			/* Random (x,y,z) coordinates */
      y1 = drand48()*2.0 - 1.0;
      z1 = drand48()*2.0 - 1.0;
      x2 = drand48()*2.0 - 1.0;			/* Random (x,y,z) coordinates */
      y2 = drand48()*2.0 - 1.0;
      z2 = drand48()*2.0 - 1.0;
      r1  = drand48();
      g1  = drand48();
      b1  = drand48();
      r2  = drand48();
      g2  = drand48();
      b2  = drand48();
      size = drand48()*10.0;			/* Line thickness */
      ns2thcline(x1,y1,z1, x2,y2,z2, r1,g1,b1, r2,g2,b2, size);	/* Draw the thick line */
   }

   s2show(1);					/* Open the s2plot window */
   
   return 1;
}
