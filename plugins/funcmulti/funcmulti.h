#pragma once

#include <Windows.h>
#include <memory>

#include "../../includes/BaseOperationClass.h"
#include "../../includes/ErrorMessage.h"

class FuncMulti : public BaseOperation {
public:
	double operation(const std::vector<double>& arg) const override;

	const char* getName() override;
};

extern "C" __declspec(dllexport) double operationE(const std::vector<double>&arg);
extern "C" __declspec(dllexport) const char* getNameE();
