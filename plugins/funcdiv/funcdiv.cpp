#include "pch.h"
#include "funcdiv.h"

double FuncDiv::operation(const std::vector<double>& arg) const {
	if (arg.size() == 2) {
		if (arg[1] == 0) throw ErrorMessage("Division by zero");
		return arg[0] / arg[1];
	}
	throw ErrorMessage("command / have 2 arg");
}

const char* FuncDiv::getName() {
	return "/";
}

extern "C" __declspec(dllexport) double operationE(const std::vector<double>&arg) {
	std::unique_ptr<BaseOperation> baseoper = std::make_unique<FuncDiv>();
	return baseoper->operation(arg);
}

extern "C" __declspec(dllexport) const char* getNameE() {
	std::unique_ptr<BaseOperation> name = std::make_unique<FuncDiv>();
	return name->getName();
}