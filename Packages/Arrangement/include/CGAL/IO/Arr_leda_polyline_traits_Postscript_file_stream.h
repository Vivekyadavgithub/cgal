// ======================================================================
//
// Copyright (c) 2001 The CGAL Consortium
//
// This software and related documentation is part of an INTERNAL release
// of the Computational Geometry Algorithms Library (CGAL). It is not
// intended for general use.
//
// ----------------------------------------------------------------------
//
// release       : $CGAL_Revision: CGAL-2.3-I-62 $
// release_date  : $CGAL_Date: 2001/05/11 $
//
// file          : include/CGAL/IO/Arr_leda_polyline_traits_Postscript_file_stream.h
// package       : Arrangement (1.82)
// maintainer    : Eyal Flato <flato@math.tau.ac.il>
// author(s)     : Eti Ezra <estere@post.tau.ac.il>
// coordinator   : Tel-Aviv University (Dan Halperin <halperin@math.tau.ac.il>)
//
// ======================================================================

#ifdef CGAL_ARR_LEDA_POLYLINE_TRAITS_H
#ifndef CGAL_ARR_LEDA_POLYLINE_TRAITS_POSTSCRIPT_FILE_STREAM_H   
#define CGAL_ARR_LEDA_POLYLINE_TRAITS_POSTSCRIPT_FILE_STREAM_H  

#include <CGAL/rat_leda_in_CGAL_2.h>
#include <LEDA/rat_segment.h>
#

#ifndef CGAL_POSTSCRIPT_FILE_STREAM_H
#include <CGAL/IO/Postscript_file_stream.h>
#endif

CGAL_BEGIN_NAMESPACE

template <class Curve>
Postscript_file_stream& operator<<(Postscript_file_stream& ps, 
                                   const Curve& cv)        
{
  typedef typename Curve::value_type           Point;
  typedef typename Curve::iterator             Curve_iter;
  typedef leda_rat_segment                     Segment;
  typedef typename Curve::const_iterator       Points_iterator;
  
  ps << *(cv.begin());
  
  Points_iterator points_iter;
  for (points_iter = cv.begin(); points_iter != cv.end(); ) {
    //for (unsigned int i = 0; i < cv.size() - 1; i++){
    Points_iterator source_point = points_iter;
    
    Points_iterator target_point =  (++points_iter);
    
    if (target_point == cv.end())
      break;
    
    ps << Segment(*source_point, *target_point);
  }

  ps << *(--points_iter);

  return ps;
}

CGAL_END_NAMESPACE

#endif
#endif 









