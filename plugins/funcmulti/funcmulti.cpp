#include "pch.h"
#include "funcmulti.h"
#include <memory>

double FuncMulti::operation(const std::vector<double>& arg) const {
	if (arg.size() == 2) {
		return arg[0] * arg[1];
	}
	throw ErrorMessage("operation * have 2 arg");
}

const char* FuncMulti::getName() {
	return "*";
}

extern "C" __declspec(dllexport) double operationE(const std::vector<double>&arg) {
	std::unique_ptr<BaseOperation> baseoper = std::make_unique<FuncMulti>();
	return baseoper->operation(arg);
}

extern "C" __declspec(dllexport) const char* getNameE() {
	std::unique_ptr<BaseOperation> name = std::make_unique<FuncMulti>();
	return name->getName();
}
