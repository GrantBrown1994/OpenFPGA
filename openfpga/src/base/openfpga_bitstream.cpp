/********************************************************************
 * This file includes functions to build bitstream database
 *******************************************************************/
/* Headers from vtrutil library */
#include "vtr_time.h"
#include "vtr_log.h"

#include "build_device_bitstream.h"
#include "bitstream_writer.h"
#include "build_fabric_bitstream.h"
#include "openfpga_bitstream.h"

/* Include global variables of VPR */
#include "globals.h"

/* begin namespace openfpga */
namespace openfpga {

/********************************************************************
 * A wrapper function to call the build_device_bitstream() in FPGA bitstream
 *******************************************************************/
void fpga_bitstream(OpenfpgaContext& openfpga_ctx,
                    const Command& cmd, const CommandContext& cmd_context) {

  CommandOptionId opt_verbose = cmd.option("verbose");
  CommandOptionId opt_file = cmd.option("file");

  openfpga_ctx.mutable_bitstream_manager() = build_device_bitstream(g_vpr_ctx,
                                                                    openfpga_ctx,
                                                                    cmd_context.option_enable(cmd, opt_verbose));

  if (true == cmd_context.option_enable(cmd, opt_file)) {
    write_arch_independent_bitstream_to_xml_file(openfpga_ctx.bitstream_manager(),
                                                 cmd_context.option_value(cmd, opt_file));
  }
}

/********************************************************************
 * A wrapper function to call the build_fabric_bitstream() in FPGA bitstream
 *******************************************************************/
void build_fabric_bitstream(OpenfpgaContext& openfpga_ctx,
                            const Command& cmd, const CommandContext& cmd_context) {

  CommandOptionId opt_verbose = cmd.option("verbose");

  openfpga_ctx.mutable_fabric_bitstream() = build_fabric_dependent_bitstream(openfpga_ctx.bitstream_manager(),
                                                                             openfpga_ctx.module_graph(),
                                                                             cmd_context.option_enable(cmd, opt_verbose));
} 

} /* end namespace openfpga */