//-------------------------------------------
// Project: Physics eXtension Library (PXL) -
//      http://vispa.physik.rwth-aachen.de/ -
// Copyright (C) 2009-2012 Martin Erdmann   -
//               RWTH Aachen, Germany       -
// Licensed under a LGPL-2 or later license -
//-------------------------------------------

#ifndef INITIALIZE_HEP_HH_
#define INITIALIZE_HEP_HH_

#include "Pxl/Pxl/interface/pxl/core/macros.hh"

namespace pxl
{
class PXL_DLL_EXPORT Hep
{
public:
	static void initialize();
	static void shutdown();

};
}

#endif /* INITIALIZE_HH_ */
