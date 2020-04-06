#ifndef __DEBUGHEADER_H_INCLUDED__
#define __DEBUGHEADER_H_INCLUDED__

#include "header.h"

//const bool kEnalbeDebugLogs = true;
const bool kEnalbeDebugLogs = false;
static string debug_function_call_indent;
static int log_count;


void DebugFunctionBegin(const string kFuncName);
void DebugFunctionEnd(const string kFuncName);
void DebugPrint(const string kStr);

#endif