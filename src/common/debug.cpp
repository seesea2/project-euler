#include "debug.h"

void DebugFunctionBegin(const string kFuncName)
{
	if (!kEnalbeDebugLogs)
		return;

	cout << debug_function_call_indent << kFuncName << "  Function begin" << endl;
	if (log_count == 50)
	{
		system("pause");
		log_count = 0;
	}

	for (int i = 0; i < 4; ++i)
		debug_function_call_indent.push_back('=');
	debug_function_call_indent.push_back('>');
}

void DebugFunctionEnd(const string kFuncName)
{
	if (!kEnalbeDebugLogs)
		return;

	debug_function_call_indent.pop_back();
	for (int i = 0; i < 4; ++i)
		debug_function_call_indent.pop_back();
	cout << debug_function_call_indent << kFuncName << "  Function end" << endl;
	++log_count;

	if (log_count == 50)
	{
		system("pause");
		log_count = 0;
	}
}

void DebugPrint(const string kStr)
{
	if (!kEnalbeDebugLogs)
		return;

	cout << debug_function_call_indent << kStr << endl;
	++log_count;

	if (log_count == 50)
	{
		system("pause");
		log_count = 0;
	}
}
