//===- LerosISelDAGToDAG.cpp - A dag to dag inst selector for Leros ---===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines an instruction selector for the Leros target.
//
//===----------------------------------------------------------------------===//

#include "Leros.h"
#include "LerosTargetMachine.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/CodeGen/SelectionDAGISel.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

// Leros  specific code to select Leros machine
// instructions for SelectionDAG operations.
namespace {
class LerosDAGToDAGISel : public SelectionDAGISel {
public:
  LerosDAGToDAGISel(LerosTargetMachine &TM) : SelectionDAGISel(TM) {}

  virtual StringRef getPassName() const {
    return "Leros DAG->DAG Pattern Instruction Selection";
  }

  void Select(SDNode *N) override;

public:
// Include the pieces autogenerated from the target description.
#include "LerosGenDAGISel.inc"
};
} // end anonymous namespace

void LerosDAGToDAGISel::Select(SDNode *N) {}

// This pass converts a legalized DAG into a Leros-specific DAG, ready
// for instruction scheduling.
FunctionPass *llvm::createLerosISelDag(LerosTargetMachine &TM) {
  return new LerosDAGToDAGISel(TM);
}
