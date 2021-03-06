/*!
 *  Copyright (c) 2017 by Contributors
 *  Implementation of API functions related to schedule pass.
 * \file api_schedule.cc
 */
#include <tvm/expr.h>
#include <tvm/tensor.h>
#include <tvm/schedule.h>
#include <tvm/schedule_pass.h>
#include <tvm/api_registry.h>
#include "../schedule/graph.h"

namespace tvm {
namespace schedule {

TVM_REGISTER_API("schedule.AutoInlineElemWise")
.set_body([](TVMArgs args, TVMRetValue* ret) {
    AutoInlineElemWise(args[0]);
  });

#define REGISTER_SCHEDULE_PASS1(PassName)                         \
  TVM_REGISTER_API("schedule."#PassName)                          \
  .set_body([](TVMArgs args,  TVMRetValue *ret) {                 \
      *ret = PassName(args[0]);                                   \
    })                                                            \

#define REGISTER_SCHEDULE_PASS2(PassName)                         \
  TVM_REGISTER_API("schedule."#PassName)                          \
  .set_body([](TVMArgs args,  TVMRetValue *ret) {                 \
      *ret = PassName(args[0], args[1]);                          \
    })                                                            \


REGISTER_SCHEDULE_PASS1(InferBound);
REGISTER_SCHEDULE_PASS1(CreateReadGraph);
REGISTER_SCHEDULE_PASS2(PostDFSOrder);
REGISTER_SCHEDULE_PASS1(CreateAttachPath);
REGISTER_SCHEDULE_PASS1(ScanGetBody);
REGISTER_SCHEDULE_PASS1(ScanFixPointAnalysis);
REGISTER_SCHEDULE_PASS2(ScheduleOps);

}  // namespace schedule
}  // namespace tvm
