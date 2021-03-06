//-------------------------------------------
// Project: Physics eXtension Library (PXL) -
//      http://vispa.physik.rwth-aachen.de/ -
// Copyright (C) 2009-2012 Martin Erdmann   -
//               RWTH Aachen, Germany       -
// Licensed under a LGPL-2 or later license -
//-------------------------------------------

#include "Pxl/Pxl/interface/pxl/core/Relations.hh"
#include "Pxl/Pxl/interface/pxl/core/Relative.hh"

namespace pxl
{

void Relations::serialize(const OutputStream &out) const
{
	out.writeInt(size());
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		(*iter)->getId().serialize(out);
	}
}

}
