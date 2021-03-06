/*----- PROTECTED REGION ID(PEX48DS.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        PEX48DS.cpp
//
// description : C++ source for the PEX48DS class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               PEX48DS are implemented in this file.
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
// Kirill Pshenichnyi (c) PNPI
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <PEX48DS.h>
#include <PEX48DSClass.h>

/*----- PROTECTED REGION END -----*/	//	PEX48DS.cpp

/**
 *  PEX48DS class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  Start         |  start
//  Stop          |  stop
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//  value  |  Tango::DevULong64	Scalar
//================================================================

namespace PEX48DS_ns
{
/*----- PROTECTED REGION ID(PEX48DS::namespace_starting) ENABLED START -----*/

    Pex48Device *PEX48DS::pex48 = nullptr;

/*----- PROTECTED REGION END -----*/	//	PEX48DS::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::PEX48DS()
 *	Description : Constructors for a Tango device
 *                implementing the classPEX48DS
 */
//--------------------------------------------------------
PEX48DS::PEX48DS(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(PEX48DS::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::constructor_1
}
//--------------------------------------------------------
PEX48DS::PEX48DS(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(PEX48DS::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::constructor_2
}
//--------------------------------------------------------
PEX48DS::PEX48DS(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(PEX48DS::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void PEX48DS::delete_device()
{
	DEBUG_STREAM << "PEX48DS::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(PEX48DS::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::delete_device
	delete[] attr_value_read;
}

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void PEX48DS::init_device()
{
	DEBUG_STREAM << "PEX48DS::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(PEX48DS::init_device_before) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	attr_value_read = new Tango::DevULong64[1];
	/*----- PROTECTED REGION ID(PEX48DS::init_device) ENABLED START -----*/

	if(pex48!=nullptr) delete pex48;
	pex48 = new Pex48Device(path_to_device);
	//pex48->setSigHandler((void *)Pex48Device::pex48_sig_handler);
    //pex48->setSigHandler((void *)(int)(&(pex48->pex48_sig_handler)));

    //std::cout << "addr: " << (void *)(int)(pex48->pex48_sig_handler(1));

    if(pex48->getErrno()!=Pex48Device::ERR_OK){
        device_status = "Error open device file!\n";
        device_state = Tango::FAULT;
    }else{
        device_state = Tango::ON;
    }
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::init_device
}

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void PEX48DS::get_device_property()
{
	/*----- PROTECTED REGION ID(PEX48DS::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("path_to_device"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on PEX48DSClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		PEX48DSClass	*ds_class =
			(static_cast<PEX48DSClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize path_to_device from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  path_to_device;
		else {
			//	Try to initialize path_to_device from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  path_to_device;
		}
		//	And try to extract path_to_device value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  path_to_device;

	}

	/*----- PROTECTED REGION ID(PEX48DS::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void PEX48DS::always_executed_hook()
{
	DEBUG_STREAM << "PEX48DS::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(PEX48DS::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void PEX48DS::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "PEX48DS::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(PEX48DS::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::read_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute value related method
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Scalar
 */
//--------------------------------------------------------
void PEX48DS::read_value(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PEX48DS::read_value(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PEX48DS::read_value) ENABLED START -----*/

	*attr_value_read = pex48->getCounterValue();
	attr.set_value(attr_value_read);
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::read_value
}

//--------------------------------------------------------
/**
 *	Method      : PEX48DS::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void PEX48DS::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(PEX48DS::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command Start related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void PEX48DS::start()
{
	DEBUG_STREAM << "PEX48DS::Start()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PEX48DS::start) ENABLED START -----*/

	if(pex48->getErrno()!=Pex48Device::ERR_OK){
	    device_state = Tango::FAULT;
	    return;
	}

	pex48->startCounter();
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::start
}
//--------------------------------------------------------
/**
 *	Command Stop related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void PEX48DS::stop()
{
	DEBUG_STREAM << "PEX48DS::Stop()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PEX48DS::stop) ENABLED START -----*/

    if(pex48->getErrno()!=Pex48Device::ERR_OK){
        device_state = Tango::FAULT;
        return;
    }
	pex48->stopCounter();
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::stop
}
//--------------------------------------------------------
/**
 *	Method      : PEX48DS::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void PEX48DS::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(PEX48DS::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	PEX48DS::add_dynamic_commands
}

/*----- PROTECTED REGION ID(PEX48DS::namespace_ending) ENABLED START -----*/

//	Additional Methods

/*----- PROTECTED REGION END -----*/	//	PEX48DS::namespace_ending
} //	namespace
