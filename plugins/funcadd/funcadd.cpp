#include "pch.h"
#include "funcadd.h"

double FuncAdd::operation(const std::vector<double>& arg) const{
	if (arg.size() == 2) {
		return arg[0] + arg[1];
	}
	else {
		throw ErrorMessage("command + have 2 arg");
	}
}

const char* FuncAdd::getName(){
	return "+";
}

extern "C" __declspec(dllexport) double operationE(const std::vector<double>&arg) {
	std::unique_ptr<BaseOperation> baseoper = std::make_unique<FuncAdd>();
	return baseoper->operation(arg);
}

extern "C" __declspec(dllexport) const char* getNameE() {
	std::unique_ptr<BaseOperation> name = std::make_unique<FuncAdd>();
	return name->getName();
}