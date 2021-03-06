//-------------------------------------------
// Project: Physics eXtension Library (PXL) -
//      http://vispa.physik.rwth-aachen.de/ -
// Copyright (C) 2009-2012 Martin Erdmann   -
//               RWTH Aachen, Germany       -
// Licensed under a LGPL-2 or later license -
//-------------------------------------------

#ifndef PXL_FILE_FACTORY_HH
#define PXL_FILE_FACTORY_HH
#include "Pxl/Pxl/interface/pxl/core/macros.hh"

#include <map>

#include "Pxl/Pxl/interface/pxl/core/Id.hh"
#include "Pxl/Pxl/interface/pxl/core/File.hh"

namespace pxl
{

class FileProducerInterface;

class PXL_DLL_EXPORT FileFactory
{
private:

	FileFactory();

	std::map<std::string, const FileProducerInterface *> _Producers;

public:

	static FileFactory& instance();

	FileImpl *create(const std::string& id);

	void registerProducer(const std::string& id,
			const FileProducerInterface* producer);
	void unregisterProducer(const FileProducerInterface* producer);
};

class FileProducerInterface
{
public:
	virtual ~FileProducerInterface()
	{
	}

	virtual FileImpl *create() const = 0;
};

template<class T>
class FileProducerTemplate: public FileProducerInterface
{
public:

	void initialize(const std::string &schema)
	{
		FileFactory::instance().registerProducer(schema, this);
	}

	void shutdown()
	{
		FileFactory::instance().unregisterProducer(this);
	}

	FileImpl *create() const
	{
		return new T();
	}
};

} // namespace pxl

#endif // PXL_IO_OBJECT_FACTORY_HH
