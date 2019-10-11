/**************************************************
 * This file includes only declarations for 
 * the data structures for module managers
 * Please refer to module_manager.h for more details
 *************************************************/
#ifndef MODULE_MANAGER_FWD_H
#define MODULE_MANAGER_FWD_H

#include "vtr_strong_id.h"

/* Strong Ids for ModuleManager */
struct module_id_tag;
struct module_port_id_tag;
struct module_pin_id_tag;
struct module_net_id_tag;
struct module_net_src_id_tag;
struct module_net_sink_id_tag;

typedef vtr::StrongId<module_id_tag> ModuleId;
typedef vtr::StrongId<module_port_id_tag> ModulePortId;
typedef vtr::StrongId<module_pin_id_tag> ModulePinId;
typedef vtr::StrongId<module_net_id_tag> ModuleNetId;
typedef vtr::StrongId<module_net_src_id_tag> ModuleNetSrcId;
typedef vtr::StrongId<module_net_sink_id_tag> ModuleNetSinkId;

class ModuleManager;

#endif 
