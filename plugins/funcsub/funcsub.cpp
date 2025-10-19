#include "pch.h"
#include "funcsub.h"

double FuncSub::operation(const std::vector<double>& arg) const {
	if (arg.size() == 1) {
		return -arg[0];
	}
	else if (arg.size() == 2) {
		return arg[0] - arg[1];
	}
	throw ErrorMessage("command - have 1 or 2 arg");
}

const char* FuncSub::getName() {
	return "-";
}

extern "C" __declspec(dllexport) double operationE(const std::vector<double>&arg) {
	std::unique_ptr<BaseOperation> baseoper = std::make_unique<FuncSub>();
	return baseoper->operation(arg);
}

extern "C" __declspec(dllexport) const char* getNameE() {
	std::unique_ptr<BaseOperation> name = std::make_unique<FuncSub>();
	return name->getName();
}
