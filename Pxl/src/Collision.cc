//-------------------------------------------
// Project: Physics eXtension Library (PXL) -
//      http://vispa.physik.rwth-aachen.de/ -
// Copyright (C) 2009-2012 Martin Erdmann   -
//               RWTH Aachen, Germany       -
// Licensed under a LGPL-2 or later license -
//-------------------------------------------

#include "Pxl/Pxl/interface/pxl/hep/Collision.hh"

namespace pxl {

std::ostream& Collision::print(int level, std::ostream& os, int pan) const
{
    printPan1st(os, pan) << "Collision: " << getName() << std::endl;

    if (level>0) printContent(level, os, pan);

    return os;
}

} // namespace pxl
