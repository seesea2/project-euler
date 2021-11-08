#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "header.h"

//const bool kEnalbeDebugLogs = true;
const bool kEnalbeDebugLogs = false;
static string debug_function_call_indent;
// static int log_count = 0;

void DebugFunctionBegin(const string kFuncName);
void DebugFunctionEnd(const string kFuncName);
void DebugPrint(const string kStr);

#endif // __DEBUG_H__